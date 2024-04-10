#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define x first
#define y second
#define ll long long
using namespace std;
const int N=1e6+6; int a[N],b[N];
signed main(){
	int n; scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		per(j,30,0) if (a[i]>>j&1){ b[i]=j; break; }
	}
	rep(i,2,n-1)
		if (b[i-1]==b[i]&&b[i]==b[i+1]){ puts("1"); return 0; }
	rep(i,1,n) a[i]^=a[i-1];
	int ans=n+1;
	rep(x,1,n)
		rep(y,x,n)
			rep(z,y+1,n)
				if ((a[z]^a[y])<(a[y]^a[x-1])) ans=min(ans,z-x-1);
	printf("%d\n",ans==n+1?-1:ans);
	return 0;
}