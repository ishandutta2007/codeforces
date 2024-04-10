#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i,j,t,a[305][305];
void solve()
{
	int i,j;
	rep(i,n){
		rep(j,m){
			int s=(i>1)+(i<n)+(j>1)+(j<m);
			if(a[i][j]>s){
				puts("NO");
				return;
			}
			a[i][j]=s;
		}
	}
			puts("YES");
			rep(i,n){
				rep(j,m){
					printf("%d ",a[i][j]);
				}
				puts("");
			}
}
int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		rep(i,n){
			rep(j,m){
				scanf("%d",&a[i][j]);
			}
		}
		solve();
	}
	return 0;
}