#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
#define db long double
using namespace std;
const int N=1e6+6; ll a[N],b[N]; int x[N],s[N],o[N];
int main(){
	int n; ll t; scanf("%d%lld",&n,&t);
	rep(i,1,n) scanf("%lld",&a[i]);
	rep(i,1,n) scanf("%d",&x[i]);
	rep(i,1,n) if (x[i]<i){ puts("No"); return 0; }
	rep(i,2,n) if (x[i]<x[i-1]){ puts("No"); return 0; }
	rep(i,1,n) ++s[i],--s[x[i]],++o[x[i]];
	rep(i,1,n) s[i]+=s[i-1];
	rep(i,1,n) if (s[i]&&o[i]){ puts("No"); return 0; }
	rep(i,1,n-1)
		if (s[i]) b[i]=a[i+1]+t;
		else b[i]=a[i+1]+t-1;
	rep(i,2,n-1) if (b[i]<=b[i-1]){ puts("No"); return 0; }
	puts("Yes");
	rep(i,1,n-1)
		if (s[i]) printf("%lld ",a[i+1]+t);
		else printf("%lld ",a[i+1]+t-1);
	printf("%lld\n",(ll)3e18);	
	return 0;
}