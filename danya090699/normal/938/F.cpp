#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10;
bool dp[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), k=0;
    while((1<<(k+1))<=n) k++;
    int q=n-((1<<k)-1);
    dp[0][0]=1;
    char an[q];
    for(int a=0; a<=q; a++)
    {
        for(int b=0; b<(1<<k); b++)
        {
            if(dp[a][b])
            {
                for(int c=0; c<k; c++) if((b&(1<<c))==0) dp[a][b+(1<<c)]=1;
            }
        }
        if(a<q)
        {
            char be='z';
            for(int b=0; b<(1<<k); b++)
            {
                if(dp[a][b]) be=min(be, s[a+b]);
            }
            an[a]=be;
            for(int b=0; b<(1<<k); b++)
            {
                if(dp[a][b] and s[a+b]==be) dp[a+1][b]=1;
            }
        }
    }
    for(int a=0; a<q; a++) cout<<an[a];
}