#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int dp[2010][2010],ok[2010][10];
string c[2010];
string num[10]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};

signed main()
{
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		for(int j=0;j<=9;j++){
			int cnt=0;
			for(int k=0;k<=6;k++){
				if(c[i][k]=='1'&&num[j][k]=='0'){
					cnt=-1;break;
				}
				if(c[i][k]=='0'&&num[j][k]=='1') cnt++;
			}
			ok[i][j]=cnt;
		}
	}
	dp[n+1][0]=1;
	for(int i=n;i>=1;i--){
		for(int j=0;j<=k;j++){
			for(int l=0;l<=9;l++){
				if(ok[i][l]==-1) continue;
				if(j>=ok[i][l]) dp[i][j]|=dp[i+1][j-ok[i][l]];
			}
		}
	}
	if(!dp[1][k]) cout<<-1<<endl;
	else{
		string ans="";
		int num=k;
		for(int i=1;i<=n;i++){
			for(int j=9;j>=0;j--){
				if(ok[i][j]==-1) continue;
				if(num>=ok[i][j]){
					if(dp[i+1][num-ok[i][j]]){
						ans+=char(j+'0');
						num-=ok[i][j];
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}