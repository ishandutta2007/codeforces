#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M=(int) 1e9+7;

int add(int a, int b)
{
        a+=b;
        if (a>=M) return a-M;
        if (a<0) return a+M;
        return a;
}

int mul(int a, int b)
{
        return a*(ll) b%M;
}

int pw(int a, int b)
{
        int r=1;
        while (b)
        {
                if (b&1)
                        r=mul(r, a);
                a=mul(a, a);
                b/=2;
        }
        return r;
}

int dv(int a, int b)
{
        return mul(a, pw(b, M-2));
}

const int N=(int) 2e5+7;
int n, sol[N], dp[N], cnt[N];
vector<int> g[N];

void dostuff(int a, int p=-1)
{
        dp[a]=1;
        for (auto &b : g[a])
                if (b!=p)
                {
                        int valb=cnt[b]?0:dp[b];
                        if (add(valb, 1)==0)
                        {
                                cnt[a]++;
                        }
                        else
                        {
                                dp[a]=mul(dp[a], add(valb, 1));
                        }
                }
}

void dfs(int a, int p=-1)
{
        for (auto &b : g[a])
                if (b!=p)
                        dfs(b, a);
        dostuff(a, p);
}

void rer(int a, int p)
{
        int valp=cnt[p]?0:dp[p];
        if (add(valp, 1)==0)
        {
                cnt[a]--;
        }
        else
        {
                dp[a]=dv(dp[a], add(valp, 1));
        }

        int vala=cnt[a]?0:dp[a];
        if (add(vala, 1)==0)
        {
                cnt[p]++;
        }
        else
        {
                dp[p]=mul(dp[p], add(vala, 1));
        }
}

void solve(int a, int p=-1)
{
        sol[a]=cnt[a]?0:dp[a];
        for (auto &b : g[a])
        {
                if (b!=p)
                {
                        rer(a, b);
                        solve(b, a);
                        rer(b, a);
                }
        }
}

mt19937 rng((long long) (new char));

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        cin>>n;
        for (int a=2; a<=n; a++)
        {
                int b;
                cin>>b;
                g[a].push_back(b);
                g[b].push_back(a);
        }

        for (int i=1; i<=n; i++)
        {
                sol[i]=-1;
        }


        dfs(1, -1);
        solve(1, -1);

        for (int i=1; i<=n; i++)
        {
                cout<<sol[i]<<" ";
        }
        cout<<"\n";




        return 0;
}