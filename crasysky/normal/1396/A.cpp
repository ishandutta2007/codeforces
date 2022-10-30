#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; int a[N];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	if (n==1){
		printf("1 1\n0\n1 1\n0\n1 1\n%d",-a[1]);
		return 0;
	}
	printf("%d %d\n",1,n-1);
	rep(i,1,n-1) printf("%lld ",(ll)a[i]*(n-1));
	printf("\n%d %d\n",2,n);
	rep(i,2,n-1) printf("0 ");
	printf("%lld\n%d %d\n",(ll)a[n]*(n-1),1,n);
	rep(i,1,n) printf("%lld ",-(ll)a[i]*n);
	return 0; 
}