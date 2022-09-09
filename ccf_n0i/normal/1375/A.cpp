#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i,j,t,a[105],b[105];
/*void solve()
{
	int i,j,k;
	rep(i,n/2){
		b[i]=min(a[i],-a[i]);
		for(j=i+1;j<=i+n/2;j++){
			int x=min(a[j],-a[j]),y=max(a[j],-a[j]);
			if(x>=b[j-1]) b[j]=x; else if(y>=b[j-1]) b[j]=y; else break;
		}
		if(j>i+n/2){
			rep(k,n){
				printf("%d%c",((i<=k&&k<j)?b[k]:a[k]),(k==n?'\n':' '));
			}
			return;
		}
		b[i]=max(a[i],-a[i]);
		for(j=i+1;j<=i+n/2;j++){
			int x=max(a[j],-a[j]),y=min(a[j],-a[j]);
			if(x<=b[j-1]) b[j]=x; else if(y<=b[j-1]) b[j]=y; else break;
		}
		if(j>i+n/2){
			rep(k,n){
				printf("%d%c",((i<=k&&k<j)?b[k]:a[k]),(k==n?'\n':' '));
			}
			return;
		}
	}
}*/
int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		rep(i,n) scanf("%d",&a[i]);
		rep(i,n) printf("%d ",abs(a[i])*((i&1)?1:(-1)));
		puts("");
	}
	return 0;
}