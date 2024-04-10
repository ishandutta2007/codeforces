#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///#define int long long

const int N=(int) 2e5+7;
const int K=17;
int n, k, a[N], dp[1<<K], f[N][K+1], nxt[N][K];
bool pot[N][K];
string s;
bool act[N];

bool ok(int len)
{
        if (len*k>n)
                return 0;
        for (int i=len; i<=n; i++)
        {

                for (int j=0;j<k;j++)
                {
                        int good=f[i][j]-f[i-len][j]+f[i][k]-f[i-len][k];
                        if (good==len)
                        {
                                pot[i][j]=1;
                        }
                        else
                        {
                                pot[i][j]=0;
                        }
                }
        }
        for (int i=n; i>=1; i--)
        {
                for (int j=0; j<k; j++)
                        if (pot[i][j])
                                nxt[i][j]=i;
                        else
                                nxt[i][j]=nxt[i+1][j];
        }
        for (int i=0; i<(1<<k); i++)
                dp[i]=N,
                act[i]=0;
        dp[0]=0;
        act[0]=1;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
                int mask=q.front(), i=dp[mask];
                q.pop();
                act[mask]=0;
                if (i+len-1>n)
                        continue;
                for (int j=0; j<k; j++)
                {
                        if (mask&(1<<j))
                                continue;
                        int nmask=mask+(1<<j);
                        int i2=nxt[i+len][j];
                        if (i2 && i2<dp[nmask])
                        {
                                dp[nmask]=i2;
                                if (!act[nmask])
                                {
                                        act[nmask]=1;
                                        q.push(nmask);
                                }
                        }
                }
        }
        return dp[(1<<k)-1]<=n;
}

signed main()
{
       /// freopen ("input", "r", stdin);
        ios::sync_with_stdio(0); cin.tie(0); /// NOT just for aesthetics this time


        cin>>n>>k>>s;
        for (int i=1; i<=n; i++)
        {
                char ch=s[i-1];
                if (ch=='?')
                        a[i]=k;
                else
                        a[i]=ch-'a';
                f[i][a[i]]++;
                for (int x=0; x<=k; x++)
                        f[i][x]+=f[i-1][x];
        }

        int l=1, r=n, sol=0;

        while (l<=r)
        {
                int mid=(l+r)/2;
                if (ok(mid))
                {
                        sol=mid;
                        l=mid+1;
                }
                else
                        r=mid-1;
        }

        cout<<sol<<"\n";

        return 0;
}


/**

**/