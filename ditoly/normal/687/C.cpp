#include<bits\stdc++.h>  
using namespace std;  
  
int dp[505][505];  
vector<int>ans;  
int main()  
{  
    int n,k;  
    scanf("%d%d",&n,&k);  
    dp[0][0]=1;  
    for(int i = 1;i<=n;i++)  
    {  
         int c;  
         scanf("%d",&c);  
         for(int j = 500;j>= 0;j--)  
             for(int k = 0;k<=j;k++)  
             {  
                 dp[j][k]|=dp[j][k];  
                 if(j>=c)  
                     dp[j][k]|=dp[j-c][k];  
                 if(k>=c && j>=c)  
                     dp[j][k]|=dp[j-c][k-c];  
             }  
    }  
    for(int i = 0;i<=500;i++)  
        if(dp[k][i])  
            ans.push_back(i);  
    cout << ans.size() << endl;  
    for(int i = 0;i<ans.size();i++)  
        cout << ans[i] << " ";  
    cout << endl;  
}