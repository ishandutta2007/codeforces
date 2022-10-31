#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i) 
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define db long double
using namespace std;
const int N=1e6+6; int a[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,u,v; scanf("%d%d%d",&n,&u,&v);
		rep(i,1,n) scanf("%d",&a[i]);
		int mx=0;
		rep(i,2,n) mx=max(mx,max(a[i]-a[i-1],a[i-1]-a[i]));
		if (mx==0) cout<<min(u+v,v+v)<<endl;
		else if (mx==1) cout<<min(u,v)<<endl;
		else cout<<0<<endl;
	}
	return 0;
}