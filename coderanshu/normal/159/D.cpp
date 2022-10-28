#include<iostream>
using namespace std;

#define ll      long long

const int N=2001;

ll dp[N];
bool is[N][N];

int main()
{
    string s;
    cin>>s;
    ll ans=0;

    int n=s.size();

    for(int i=0;i<n;++i)
        is[i][i]=true;
    for(int j=2;j<=n;++j)
    {
        for(int i=0;i<n;++i)
        {
            if(i+j>n)
                break;
            is[i][i+j-1]=(s[i]==s[i+j-1]) && (j==2 || is[i+1][i+j-2]);
        }
    }
    dp[0]=0;
    for(int i=1;i<=n;++i)
    {
        dp[i]+=dp[i-1];
        for(int j=1;j<=i;++j)
        {
            dp[i]+=is[j-1][i-1];
            ans+=is[j-1][i-1]*dp[j-1];
        }
    }
    cout<<ans<<'\n';
}