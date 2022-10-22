#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
struct sgt{
	int l,r,ls,rs;
	int mx[32],mn[32];
};
sgt s[3*N];
int rt,P;
int a[N][5];
void update(int p){
	for(int k=0;k<(1<<m);k++){
		s[p].mx[k]=max(s[s[p].ls].mx[k],s[s[p].rs].mx[k]);
		s[p].mn[k]=min(s[s[p].ls].mn[k],s[s[p].rs].mn[k]);		
	}
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	if(l==r){
		for(int k=0;k<(1<<m);k++){
			int num=0;
			for(int i=0;i<m;i++)
				num+=(k&(1<<i)?1:-1)*a[l][i];
			s[p].mx[k]=s[p].mn[k]=num;
		}
		return p;
	}
	int mid=(l+r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	update(p);
	return p;
}
void change(int p,int pos){
	if(s[p].l==s[p].r){
		for(int k=0;k<(1<<m);k++){
			int num=0;
			for(int i=0;i<m;i++)
				num+=(k&(1<<i)?1:-1)*a[pos][i];
			s[p].mx[k]=s[p].mn[k]=num;
		}
		return;
	}
	int mid=(s[p].l+s[p].r)>>1;
	if(pos<=mid) change(s[p].ls,pos);
	else change(s[p].rs,pos);
	update(p);
}
pair<int,int> query(int p,int l,int r,int k){
	if(s[p].l==l&&s[p].r==r)
		return {s[p].mx[k],s[p].mn[k]};
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) return query(s[p].ls,l,r,k);
	else if(l>mid) return query(s[p].rs,l,r,k);
	else{
		pair<int,int> q1=query(s[p].ls,l,mid,k),q2=query(s[p].rs,mid+1,r,k);
		return {max(q1.first,q2.first),min(q1.second,q2.second)};
	}
}
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=0;j<m;j++)
			cin>>a[i][j];
	}
	rt=build(1,n);
	int T;cin>>T;
	while(T--){
		int op;cin>>op;
		if(op==1){
			int x;cin>>x;
			for(i=0;i<m;i++) cin>>a[x][i];
			change(rt,x);
		}
		else{
			int l,r;cin>>l>>r;
			int ans=0;
			for(k=0;k<(1<<m);k++){
				pair<int,int> q=query(rt,l,r,k);
				ans=max(q.first-q.second,ans);
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}