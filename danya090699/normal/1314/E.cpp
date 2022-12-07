#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
vector <int> st;
int n, k, an=0;
void dfs()
{
    vector <int> sp=st;
    reverse(sp.begin(), sp.end());
    for(int a=0; a<k-2; a++)
    {
        vector <int> sp2;
        while(sp.size())
        {
            for(int b=0; b<sp.back() and sp2.size()<=64; b++)
            {
                sp2.push_back(sp.size());
            }
            if(sp2.size()>64) break;
            sp.pop_back();
        }
        sp=sp2;
        if(sp.size()>64) break;
    }
    if(sp.size()<=64)
    {
        int su=0;
        for(int a=0; a<sp.size(); a++) su+=(a+1)*sp[a];

        if(su<=n)
        {
            an++;

            st.back()++, dfs(), st.back()--;

            st.push_back(st.back()), dfs(), st.pop_back();
        }
    }
}
main()
{
	//freopen("input.txt", "r", stdin);
	cin>>n>>k;
    if(k==1)
    {
        int dp[n+1][n+1], an=0;
        for(int a=0; a<=n; a++) for(int b=0; b<=n; b++) dp[a][b]=0;
        dp[0][1]=1;
        for(int a=0; a<=n; a++)
        {
            for(int b=1; b<=n; b++)
            {
                if(a)
                {
                    an=(an+dp[a][b])%mod;
                    if(a+1<=n and b+1<=n) dp[a+1][b+1]=(dp[a+1][b+1]+dp[a][b])%mod;
                }
                if(a+b<=n) dp[a+b][b]=(dp[a+b][b]+dp[a][b])%mod;
            }
        }
        cout<<an;
    }
    else if(k==2)
    {
        int dp[n+1][n+1], suf[n+1][n+1], an=0;
        for(int a=0; a<=n; a++) for(int b=0; b<=n; b++) dp[a][b]=0;
        dp[0][n]=1;
        for(int a=1; a<=n; a++)
        {
            int ma=n;
            if(a-1) ma=n/(a-1);
            for(int b=0; b<=n; b++)
            {
                suf[b][ma]=dp[b][ma], dp[b][ma]=0;
                for(int c=ma-1; c; c--)
                {
                    suf[b][c]=(suf[b][c+1]+dp[b][c])%mod;
                    dp[b][c]=0;
                }
            }
            for(int b=0; b<=n; b++)
            {
                for(int c=1; c*a<=b; c++) dp[b][c]=suf[b-c*a][c], an=(an+dp[b][c])%mod;
            }
        }
        cout<<an;
    }
    else
    {
        st.push_back(1);
        dfs();
        cout<<an;
    }
}