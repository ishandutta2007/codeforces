#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
int a[1003][1003];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m; scanf("%d%d",&n,&m);
		rep(i,1,n)
			rep(j,1,m){
				int x; scanf("%d",&x);
				a[i][j]=i+j+x&1?x+1:x;
			}
		rep(i,1,n){
			rep(j,1,m) printf("%d ",a[i][j]);
			putchar('\n');
		}
	}
	return 0;
}