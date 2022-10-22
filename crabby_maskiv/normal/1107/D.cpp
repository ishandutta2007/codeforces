#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5205;
const ll mod=1000000007;
ll n,m;
char c[N][N/4];
bool a[N][N];
int dp[N][N];
int main(){
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++) cin>>(c[i]+1);
    for(i=1;i<=n;i++){
    	for(j=1;j<=n;j++){
    		char ch=c[i][(j-1)/4+1];
    		if(ch<='9') a[i][j]=(ch-'0')&(1<<(3-(j-1)%4));
			else a[i][j]=(ch-'A'+10)&(1<<(3-(j-1)%4));
		}
	}
	for(i=n;i;i--){
		for(j=n;j;j--){
			if(i==n||j==n) dp[i][j]=1;
			else{
				if(a[i+1][j]!=a[i][j]||a[i][j+1]!=a[i][j]||a[i+1][j+1]!=a[i][j]){
					dp[i][j]=1;
					continue;
				}
				dp[i][j]=min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]))+1;
			}
		}
	}
	for(int k=n;k;k--){
		if(n%k==0){
			bool flag=1;
			for(i=1;i<=n;i+=k){
				for(j=1;j<=n;j+=k){
					if(dp[i][j]%k) flag=0;
				}
			}
			if(flag){
				cout<<k;
				return 0;
			}
		}
	}
    return 0;
}