#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
string s;
stack<int>stk;
int dp[maxn];
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(') stk.push(i);      
        else
        {
            if(!stk.empty())
            {
                dp[i]=i+1 - stk.top();
                if(stk.top()>0)
                {
                	dp[i]+=dp[stk.top()-1];
				}    
                stk.pop();
            }
        }
    }
    
    int ans1=0,ans2=1;
    for(int i=0;i<s.size();i++)
    {
    //	cout<<"dp["<<i+1<<"]="<<dp[i]<<endl;
        if(dp[i]>ans1)
        {
            ans1=dp[i];
            ans2=1;
        }
        else if(dp[i]==ans1) ans2++;
    }
    
    if(ans1==0)  return 0*printf("0 1\n");
    else  return 0*printf("%d %d\n",ans1,ans2);

}