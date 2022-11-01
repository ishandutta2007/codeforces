//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=3e5+4;
#define lc (p<<1)
#define rc (p<<1|1)
struct seg{
	int t[N<<2];
	void modify(int p,int l,int r,int x,int v){
		if(l==r){t[p]=v;return;}
		int mid=l+r>>1;
		if(x<=mid)modify(lc,l,mid,x,v);
		else modify(rc,mid+1,r,x,v);
		t[p]=min(t[lc],t[rc]);
	}
	int query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return t[p];
		int mid=l+r>>1;
		if(qr<=mid)return query(lc,l,mid,ql,qr);
		if(mid<ql)return query(rc,mid+1,r,ql,qr);
		return min(query(lc,l,mid,ql,qr),query(rc,mid+1,r,ql,qr));
	}
}tmn,tmx;
int n,tpmn,tpmx,h[N],f[N],stmn[N],stmx[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++)h[i]=read();
	for(int i=2,x,l,r,mid;i<=n;i++){
		while(tpmn&&stmn[tpmn]>=h[i-1])tpmn--;
		while(tpmx&&stmx[tpmx]<=h[i-1])tpmx--;
		stmn[++tpmn]=h[i-1];
		stmx[++tpmx]=h[i-1];
		tmn.modify(1,1,n,tpmn,f[i-1]);
		tmx.modify(1,1,n,tpmx,f[i-1]);
//		cerr<<f[i-1]<<" ";
		if(h[i]==h[i-1])f[i]=f[i-1]+1;
		else if(h[i]<h[i-1]){
			x=upper_bound(stmn+1,stmn+tpmn+1,h[i])-stmn;
//			cerr<<x<<"\n";
			f[i]=tmn.query(1,1,n,max(1,x-1),tpmn)+1;
		}
		else{
			l=1;r=tpmx;
			while(l<r){
				mid=l+r>>1;
				if(stmx[mid]<h[i])r=mid;
				else l=mid+1;
			}
//			cerr<<r<<"\n";
			f[i]=tmx.query(1,1,n,max(1,r-1),tpmx)+1;
		}
	}
	cout<<f[n];
	return (0-0);
}