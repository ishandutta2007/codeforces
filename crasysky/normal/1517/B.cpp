#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define vit vector<int>::iterator
#define sit set<pr>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int N=1e3+3; int a[N][N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m; scanf("%d%d",&n,&m);
		rep(i,1,n){
			rep(j,1,m) scanf("%d",&a[i][j]);
		}
		rep(j,1,m){
			rep(i,1,n) sort(a[i]+j,a[i]+1+m);
			int p=1;
			rep(k,1,n) if (a[k][j]<a[p][j]) p=k;
			rep(k,1,n) if (k!=p) swap(a[k][j],a[k][m]);
		}
		rep(i,1,n){
			rep(j,1,m) printf("%d ",a[i][j]);
			putchar('\n');
		}
	}
	return 0;
}