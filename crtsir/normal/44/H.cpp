#include<bits/stdc++.h>
using namespace std;
string s;
long long ans,dp[51][12];
int x[51];
int main()
{
    cin>>s;
    bool can=1;
    x[51]=s[0]-'0';
    for(int i=0;i<10;i++)dp[0][i]++;
    for(int i=0;i<s.size();i++){
		x[i]=s[i]-'0';
		if(!i||!can)continue;
		if(fabs(s[i]-s[i-1])>1)can=0;
	}
	ans-=can;
	for(int i=1;i<s.size();i++)
    {
        for(int j=0;j<10;j++)
            if((x[i]+j)%2)
                dp[i][(x[i]+j)/2]+=dp[i-1][j],
                dp[i][(x[i]+j+1)/2]+=dp[i-1][j];
            else
                dp[i][(x[i]+j)/2]+=dp[i-1][j];
    }
    for(int i=0;i<10;i++)ans+=dp[s.size()-1][i];
    cout<<ans;
}