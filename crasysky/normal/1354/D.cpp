#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=2e6+6; int a[N];
int main(){
	int n,q; scanf("%d%d",&n,&q);
	rep(i,1,n+q) scanf("%d",&a[i]);
	int l=1,r=n;
	while (l<=r){
		int m=l+r>>1,c=0;
		rep(i,1,n+q){
			if (1<=a[i]&&a[i]<=m) ++c;
			if (a[i]<1&&-a[i]<=c) --c;
		}
		if (c) r=m-1; else l=m+1;
	}
	printf("%d\n",r+1<=n?r+1:0);
	return 0;
}