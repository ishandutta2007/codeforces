#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=35;
int n=30,m;
bool dp[N][N],s[N][N];
int a[N],b[N],na[N],nb[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		int x,y;cin>>x>>y;
		for(i=n-1;i>=0;i--) a[i+1]=(x>>i&1);
		for(i=n-1;i>=0;i--) b[i+1]=(y>>i&1);
		a[0]=b[0]=1;
		for(i=1;i<=n;i++){
			if(a[i]) na[i]=i;
			else na[i]=na[i-1];
			if(b[i]) nb[i]=i;
			else nb[i]=nb[i-1];
		}
		memset(dp,0,sizeof(dp));
		memset(s,0,sizeof(s));
		dp[0][0]=1;
		for(i=0;i<=n;i++) s[0][i]=1;
		for(i=1;i<=n;i++){
			if(!b[i]) continue;
			if(a[i]) dp[i][i]=dp[nb[i-1]][na[i-1]];
			for(j=i-1;j;j--)
				if(a[j]) dp[i][j]=s[nb[i-1]][j-1];
			for(j=1;j<=n;j++) s[i][j]=s[i][j-1]|dp[i][j];
		}
		if(dp[nb[n]][na[n]]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}