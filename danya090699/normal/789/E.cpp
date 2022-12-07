#include <bits/stdc++.h>
using namespace std;
const int sz=1e3;
int main()
{
    //freopen("input.txt", "r", stdin);
    int k, n, ti=1;
    scanf("%d%d", &k, &n);
    bool go[sz+1];
    for(int a=0; a<=sz; a++) go[a]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        go[x]=1;
    }
    int dp[sz*2+1];
    queue <int> qu;
    for(int a=0; a<sz*2+1; a++) dp[a]=-1;
    for(int a=0; a<=sz; a++)
    {
        if(go[a])
        {
            int nu=a-k;
            qu.push(nu);
            dp[nu+sz]=ti;
        }
    }
    while(qu.size()!=0)
    {
        int q=qu.size();
        ti++;
        for(int a=0; a<q; a++)
        {
            int nu=qu.front();
            for(int b=0; b<=sz; b++)
            {
                int cu=nu+(b-k);
                if(go[b] and cu>=-sz and cu<=sz)
                {
                    if(dp[cu+sz]==-1)
                    {
                        dp[cu+sz]=ti;
                        qu.push(cu);
                    }
                }
            }
            qu.pop();
        }
    }
    cout<<dp[sz];
}