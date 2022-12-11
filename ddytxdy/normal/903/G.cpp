#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
const int N=2e5+50;
int n,m,q,a[N],b[N];LL laz[N*4],mn[N*4],s[N];
vector<pii >v[N];
void build(int x,int l,int r,int op){
	laz[x]=0;
	if(l==r){mn[x]=op?s[l]:b[l];return;}
	int mid=(l+r)>>1;
	build(x<<1,l,mid,op);build(x<<1|1,mid+1,r,op);
	mn[x]=min(mn[x<<1],mn[x<<1|1]);
}
void push(int x,LL d){mn[x]+=d;laz[x]+=d;}
void down(int x){
	if(laz[x])push(x<<1,laz[x]),push(x<<1|1,laz[x]),laz[x]=0;
}
void change(int x,int l,int r,int ql,int qr,int d){
	if(l>qr||r<ql)return;
	if(l>=ql&&r<=qr){push(x,d);return;}
	int mid=(l+r)>>1;down(x);
	change(x<<1,l,mid,ql,qr,d);change(x<<1|1,mid+1,r,ql,qr,d);
	mn[x]=min(mn[x<<1],mn[x<<1|1]);
}
void change(int x,int l,int r,int p,LL d){
	if(l==r){mn[x]=d;return;}
	int mid=(l+r)>>1;
	p<=mid?change(x<<1,l,mid,p,d):change(x<<1|1,mid+1,r,p,d);
	mn[x]=min(mn[x<<1],mn[x<<1|1]);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++)scanf("%d%d",&a[i],&b[i]);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		v[x].pb(mp(y,z));
	}
	build(1,0,n-1,0);
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++)
			change(1,0,n-1,0,v[i][j].first-1,v[i][j].second);
		s[i]=mn[1]+a[i];
	}
	build(1,1,n,1);printf("%lld\n",mn[1]);
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		s[x]+=y-a[x];a[x]=y;
		change(1,1,n,x,s[x]);
		printf("%lld\n",mn[1]);
	}
}