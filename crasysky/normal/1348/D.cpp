#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
using namespace std;
const int N=1e6+6; int a[N],v[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m=0,k=0; scanf("%d",&n); --n;
		rep(i,1,30) if (n>=(1<<i)) n-=1<<i,v[++k]=1<<i;
		if (n) v[++k]=n;
		printf("%d\n",k); sort(v+1,v+1+k);
		v[0]=1; rep(i,1,k) printf("%d ",v[i]-v[i-1]);
		putchar('\n');
	}
	return 0;
}