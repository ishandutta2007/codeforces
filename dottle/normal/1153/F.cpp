#include<bits/stdc++.h>
#define int long long
const int N=2005,mod=998244353; 
using namespace std;

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k%mod,mod-2);}

int f[N][N][2];

void add(int&x,int y){
	x+=y;if(x>=mod)x-=mod;
}

int frac(int n){
	int ans=1;for(int i=1;i<=n;i++)ans=ans*i%mod;return ans;
}

main(){
	ios::sync_with_stdio(false);
	int l,n,m;cin>>n>>m>>l;
	f[0][0][0]=l;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<2;k++)
				if(f[i][j][k]){
					add(f[i+1][j][k],f[i][j][k]);
					add(f[i][j+1][k],f[i][j][k]*(i-j)%mod);
					if(k==0&&i-j>=m)add(f[i][j][1],f[i][j][0]);
				}
	cout<<f[n][n][1]*gsc(2,n)%mod*frac(n)%mod*inv(frac(2*n+1))%mod;
}