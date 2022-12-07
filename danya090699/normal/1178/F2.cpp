#include <bits/stdc++.h>
using namespace std;
const int mod=998244353, sz=5e3+10;
vector <int> sv[sz];
int l[sz], r[sz];
void wrong()
{
    cout<<0;
    exit(0);
}
int dfs(int v)
{
    int N=sv[v].size(), an=1;

    for(int a=0; a<N; a++)
    {
        int ne=sv[v][a];
        an=(1ll*an*dfs(ne))%mod;
    }

    int yk=0;
    while(yk<N)
    {
        vector <int> ar;
        int lg=l[sv[v][yk]];
        while(yk<N and l[sv[v][yk]]==lg)
        {
            ar.push_back(sv[v][yk]), lg=r[sv[v][yk]]+1, yk++;
        }

        int n=ar.size();

        int dp[n+1][n+1], dp2[n+1][n+1];
        for(int a=0; a<=n; a++) dp[a][a]=1, dp2[a][a]=1;
        for(int a=1; a<=n; a++)
        {
            for(int l=0; l+a<=n; l++)
            {
                int r=l+a, mi=1e9, ll, rr;
                for(int b=l; b<r; b++)
                {
                    if(ar[b]<mi) mi=ar[b], ll=b, rr=b+1;
                }
                dp[l][r]=(1ll*dp2[l][ll]*dp2[rr][r])%mod;

                dp2[l][r]=0;
                for(int b=l; b<=r; b++) dp2[l][r]=(dp2[l][r]+1ll*dp[l][b]*dp[b][r])%mod;
            }
        }

        an=(1ll*an*dp[0][n])%mod;
    }



    //cout<<v<<" "<<(1ll*an*dp[0][n])%mod<<"\n";

    //return (1ll*an*dp[0][n])%mod;

    return an;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[m];
    for(int a=0; a<=n; a++) l[a]=-1;
    vector <int> st;
    st.push_back(0);
    for(int a=0; a<m; a++)
    {
        scanf("%d", &ar[a]);
        if(l[ar[a]]==-1) l[ar[a]]=a;
        r[ar[a]]=a;
    }
    for(int a=0; a<m; a++)
    {
        int x=ar[a];
        if(l[x]==a)
        {
            if(st.back()<x)
            {
                sv[st.back()].push_back(x);
                st.push_back(x);
            }
            else wrong();
        }
        if(st.back()!=x) wrong();
        if(r[x]==a)
        {
            if(st.back()==x) st.pop_back();
            else wrong();
        }
    }
    cout<<dfs(0);
}