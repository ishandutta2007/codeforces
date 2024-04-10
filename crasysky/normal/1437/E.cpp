#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; 
int m,c[N],st[20*N],tp;
void update(int x,int y){
	for (;x<=m;x+=x&-x) c[x]=max(c[x],y),st[++tp]=x;
}
int query(int x){
	int s=-1; for (;x;x-=x&-x) s=max(s,c[x]); return s;
}
void clear(){ while (tp) c[st[tp--]]=-1; }
int a[N],b[N],p[N],tag[N];
signed main(){
	int n,k; scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",&a[i]);
	a[0]=-1e9; rep(i,0,n) b[++m]=a[i]-i;
	sort(b+1,b+1+m),m=unique(b+1,b+1+m)-b-1;
	rep(i,0,n) p[i]=lower_bound(b+1,b+1+m,a[i]-i)-b;
	rep(i,1,k){
		int b; scanf("%d",&b),tag[b]=true;
	}
	rep(i,1,m) c[i]=-1; update(p[0],0);
	int mx=-1;
	rep(i,1,n){
		int f=query(p[i]); if (tag[i]) clear(),mx=-1; 
		mx=max(mx,f+=f!=-1),update(p[i],f);
	}
	cout<<(mx==-1?-1:n-mx)<<endl;
	return 0;
}