#include<bits/stdc++.h>
#define rep(i,a,b) for(R int i=a;i<=b;i++)
#define R register
#define endl putchar('\n')
const int N=500005,inf=0x3f3f3f3f;
using namespace std;

int n,a[N],nw,mn;
const int p[2]={1000000007,1000000009};

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		a[0]=inf,mn=0;
		rep(i,1,n) scanf("%d",&a[i]),mn=a[mn]>a[i]?i:mn;
		if(mn!=1) {
			printf("%d\n",n);
			printf("%d %d %d %d\n",1,mn,a[mn],a[1]),swap(a[1],a[mn]);
		} else printf("%d\n",n-1);
		rep(i,2,n) {
			printf("%d %d %d %d\n",1,i,a[1],p[nw]);
			nw^=1;
		}
	}
	return 0;
}