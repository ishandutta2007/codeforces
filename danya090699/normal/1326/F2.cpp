#include <bits/stdc++.h>
using namespace std;
const int sz=18;
int sm[sz][sz], n;
long long dp[1<<sz][sz], su[1<<sz];
vector <int> st(1, 1), sp[sz+1];
map <vector <int>, long long> ma;
void dfs(int h)
{
    if(h<n)
    {
        if(st.size()==1 or (st.back()<st[st.size()-2]))
        {
            for(int a=0; a<sp[h+1].size(); a++)
            {
                int mask=sp[h+1][a];
                su[mask]=0;
                for(int i=0; i<n; i++)
                {
                    if(mask&(1<<i))
                    {
                        dp[mask][i]=0;
                        for(int j=0; j<n; j++)
                        {
                            if(!sm[i][j]) dp[mask][i]+=dp[mask-(1<<i)][j];
                        }
                        su[mask]+=dp[mask][i];
                    }
                }
            }
            st.back()++, dfs(h+1), st.back()--;
        }
        for(int a=0; a<sp[h+1].size(); a++)
        {
            int mask=sp[h+1][a];
            su[mask]=0;
            for(int i=0; i<n; i++)
            {
                if(mask&(1<<i))
                {
                    dp[mask][i]=su[mask-(1<<i)];
                    su[mask]+=dp[mask][i];
                }
            }
        }

        st.push_back(1), dfs(h+1), st.pop_back();
    }
    else
    {
        for(int a=0; a<n; a++) ma[st]+=dp[(1<<n)-1][a];
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            char sy;
            cin>>sy;
            sm[a][b]=sy-'0';
        }
    }
    for(int a=0; a<n; a++) dp[1<<a][a]=1, su[1<<a]=1;
    for(int mask=0; mask<(1<<n); mask++) sp[__builtin_popcount(mask)].push_back(mask);
    dfs(1);
    long long an[1<<(n-1)];
    for(int mask=0; mask<(1<<(n-1)); mask++)
    {
        vector <int> ve(1, 1);
        for(int i=0; i<n-1; i++)
        {
            if(mask&(1<<i)) ve.push_back(1);
            else ve.back()++;
        }
        sort(ve.begin(), ve.end(), greater <int>());
        an[mask]=ma[ve];
    }
    for(int i=n-2; i>=0; i--)
    {
        for(int mask=0; mask<(1<<(n-1)); mask++)
        {
            if(mask&(1<<i)) an[mask]-=an[mask-(1<<i)];
        }
    }
    for(int mask=0; mask<(1<<(n-1)); mask++) printf("%lld ", an[mask]);
}