#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2345];  
int n;  
int main()  
{  
    ll x,y;  
    cin>>n;
    //f[0]  
    memset(dp,0x3f3f3f3f,sizeof(dp));  
    dp[0]=0;  
    for(int i=1;i<=n;i++)  
    {  
        cin>>x>>y; 
        x++;  
        for(int j=n;j>=0;j--)  
        {  
        	if(j>=x)  dp[j]=min(dp[j],dp[j-x]+y);  
            else  dp[j]=min(dp[j],y);  
        }  
    }  
   	cout<<dp[n]<<endl;  
    return 0;  
}