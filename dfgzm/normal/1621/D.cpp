#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=510;
const ll inf=1e18;
int i,j,k,n,m,T,c[maxn][maxn];ll dp[maxn][maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=2*n;i++)
			for(j=1;j<=2*n;j++)c[i][j]=read();
		ll ans=0,sum=inf;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)ans+=c[i][j]+c[i+n][j+n];

		printf("%lld\n",min(min(min(c[1][n+1],c[1][2*n]),min(c[n][n+1],c[n][2*n])),min(min(c[n+1][1],c[2*n][1]),min(c[n+1][n],c[2*n][n])))+ans);
	}
	return 0;
}