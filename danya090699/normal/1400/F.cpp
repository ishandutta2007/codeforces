#include <bits/stdc++.h>
using namespace std;
const int sz=1e4, inf=1e9;
int ne[sz][10], go[sz][10], bad[sz], n=1;
vector <int> st;
int x;
void dfs(int su)
{
    if(su==x)
    {
        int ok=0;
        for(int a=0; a<st.size(); a++)
        {
            int q=0;
            for(int b=a; b<st.size(); b++)
            {
                q+=st[b];
                if(x!=q and x%q==0)
                {
                    ok=1;
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok)
        {
            int v=0;
            for(int a=0; a<st.size(); a++)
            {
                int sy=st[a];
                if(!ne[v][sy]) ne[v][sy]=n++;
                v=ne[v][sy];
            }
            bad[v]=1;
        }
    }
    else
    {
        for(int a=1; a+su<=x and a<=9; a++)
        {
            st.push_back(a);
            dfs(su+a);
            st.pop_back();
        }
    }
}
void dfs2(int v)
{
    for(int a=1; a<=9; a++)
    {
        st.push_back(a);
        for(int b=0; b<=st.size(); b++)
        {
            int u=0, ok=1;
            for(int c=b; c<st.size(); c++)
            {
                if(ne[u][st[c]]) u=ne[u][st[c]];
                else
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
            {
                go[v][a]=u;
                break;
            }
        }
        if(ne[v][a]) dfs2(ne[v][a]);
        st.pop_back();
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s>>x;

    dfs(0), dfs2(0);

    int dp[n], dp2[n];
    for(int a=0; a<n; a++) dp[a]=inf, dp2[a]=inf;
    dp[0]=0;
    for(int a=0; a<s.size(); a++)
    {
        int sy=s[a]-'0';
        for(int b=0; b<n; b++)
        {
            dp2[b]=min(dp2[b], dp[b]+1);
            int to=go[b][sy];
            if(!bad[to]) dp2[to]=min(dp2[to], dp[b]);
        }
        for(int b=0; b<n; b++) dp[b]=dp2[b], dp2[b]=inf;
    }
    int an=inf;
    for(int a=0; a<n; a++) an=min(an, dp[a]);
    cout<<an;
}