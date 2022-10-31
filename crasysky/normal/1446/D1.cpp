#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=2e5+5;
int c[102][N],v[102][2*N],a[N];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(j,1,100)
		rep(i,1,n) c[j][i]=c[j][i-1]+(a[i]==j);
	int p=0;
	rep(j,1,100) if (c[j][n]>=c[p][n]) p=j;
	memset(v,-1,sizeof(v));
	rep(j,1,100) v[j][n]=0;
	int ans=0;
	rep(i,1,n)
		rep(j,1,100){
			if (j==p) continue;
			int &x=v[j][c[p][i]-c[j][i]+n];
			if (~x) ans=max(ans,i-x);
			else x=i;
		}
	cout<<ans<<endl;
	return 0;
}