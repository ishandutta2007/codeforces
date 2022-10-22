#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> PL;
#define fi first
#define se second
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int T,n,a[505][505];
void sol(){
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n+n;i++)for(int j=1;j<=n+n;j++){
		scanf("%d",&a[i][j]);
		if(i>n&&j>n)ans+=a[i][j],a[i][j]=0;
	}
	int mn=2e9;
	mn=min(a[n+1][1],mn);
	mn=min(a[n+1][n],mn);
	mn=min(a[n+n][1],mn);
	mn=min(a[n+n][n],mn);
	mn=min(a[1][n+1],mn);
	mn=min(a[n][n+1],mn);
	mn=min(a[1][n+n],mn);
	mn=min(a[n][n+n],mn);
	printf("%lld\n",ans+mn);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}