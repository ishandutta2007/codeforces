#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
using namespace std;
const int N=1e6+6; int b[N][3],k;
void go(int x,int y,int z){
	b[++k][0]=x,b[k][1]=y,b[k][2]=z;
}
signed main(){
	int n,s=0; scanf("%d",&n);
	rep(i,1,n){ int x; scanf("%d",&x),s^=x; }
	if (n%2==0&&s){ puts("NO"); return 0; }
	if (n%2==0) --n;
	for (int i=1;i<=n-2;i+=2) go(i,i+1,i+2);
	for (int i=1;i<n-2;i+=2) go(i,i+1,n);
	printf("YES\n%d\n",k);
	rep(i,1,k) printf("%d %d %d\n",b[i][0],b[i][1],b[i][2]);
	return 0;
}