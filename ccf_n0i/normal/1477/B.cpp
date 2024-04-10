#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i,l[200005],r[200005],tt;
int sum[800005],tag[800005],len[800005]; 
string s,t;
void build(int x,int l,int r){
	tag[x]=-1;
	if(l==r){
		len[x]=1;
		sum[x]=(t[l-1]&1);return;
	}
	int mid=(l+r)/2;
	build(x+x,l,mid);
	build(x+x+1,mid+1,r);
	sum[x]=sum[x+x]+sum[x+x+1];
	len[x]=len[x+x]+len[x+x+1];
}
void upd(int x,int c){
	sum[x]=len[x]*c;
	tag[x]=c;
}
void pushdo(int x){
	if(tag[x]!=-1){
		upd(x+x,tag[x]);
		upd(x+x+1,tag[x]);
		tag[x]=-1;
	} 
}
void update(int x,int l,int r,int ql,int qr,int c){
	if(ql<=l&&r<=qr){upd(x,c);return;}
	int mid=(l+r)/2;pushdo(x);
	if(ql<=mid)update(x+x,l,mid,ql,qr,c);
	if(qr>mid)update(x+x+1,mid+1,r,ql,qr,c);
	sum[x]=sum[x+x]+sum[x+x+1];
}
int query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2;pushdo(x);int s=0;
	if(ql<=mid)s+=query(x+x,l,mid,ql,qr);
	if(qr>mid)s+=query(x+x+1,mid+1,r,ql,qr);
	return s; 
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>tt;
	while(tt--){
		cin>>n>>m;
		cin>>s>>t;
		rep(i,m)cin>>l[i]>>r[i];
		build(1,1,n);
		bool f=1;
		for(i=m;i;i--){
			int s=query(1,1,n,l[i],r[i]);
			if(s*2<(r[i]-l[i]+1)){
				update(1,1,n,l[i],r[i],0);
				continue;
			}
			if(((r[i]-l[i]+1)-s)*2<(r[i]-l[i]+1)){
				update(1,1,n,l[i],r[i],1);
				continue;
			}
			f=0;break;
		}
		if(f){
			rep(i,n){
				if((s[i-1]&1)!=query(1,1,n,i,i)){
					f=0;break;
				} 
			}
		}
		if(f)puts("YES");else puts("NO");
	}
	return 0;
}