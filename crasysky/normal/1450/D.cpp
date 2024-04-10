#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6; int a[N],c[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) c[i]=0;
		rep(i,1,n) scanf("%d",&a[i]),++c[a[i]];
		bool f=false;
		rep(i,1,n) f=f||c[i]>1;
		putchar(f?'0':'1');
		int ans=1,l=1,r=n;
		rep(i,1,n){
			if (c[i]!=1||a[l]!=i&&a[r]!=i){ ans=r-l+(c[i]==0); break; }
			if (a[l]==i) ++l; if (a[r]==i) --r;
		}
		rep(i,2,ans) putchar('0');
		rep(i,ans+1,n) putchar('1');
		putchar('\n');
	}
	return 0;
}
/*
1
6
2 3 5 5 5 1
*/