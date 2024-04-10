#include<bits/stdc++.h>
using namespace std;
double dp[10005][1005];
int main()
{
	int k,q;
	cin>>k>>q;
	dp[0][0]=1.;
	for(int i=1;i<=10000;i++){
		for(int j=1;j<=k;j++)
		dp[i][j]=(dp[i-1][j] * j + dp[i-1][j-1] * (k-j+1))/k;
	}
	int n;
	while(q--){
		cin>>n;
		int i=1;
		int ans=0;
		while(dp[i][k]*2000 + 1e-7 < n )
		{
			i++;
		}
		cout<<i<<endl;	
	}
	return 0;
}
/*
3 5
1
4
20
50
300

3
3
3
3
3
*/