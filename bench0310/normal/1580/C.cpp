#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int K=400;
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> z(n+1,{0,0});
    for(int i=1;i<=n;i++) cin >> z[i][0] >> z[i][1];
    vector<int> d(m+2,0);
    vector<array<int,2>> queries(m+1,{0,0});
    vector<int> mv[n+1];
    for(int i=1;i<=m;i++)
    {
        auto &[o,a]=queries[i];
        cin >> o >> a;
        mv[a].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        auto [x,y]=z[i];
        if(x+y<=K) continue;
        int sz=mv[i].size();
        for(int j=0;j<sz;j+=2)
        {
            int a=mv[i][j];
            int b=(j+1<sz?mv[i][j+1]:m+1);
            for(int t=a;t+x<=b;t+=(x+y))
            {
                d[t+x]++;
                d[min(b,t+x+y)]--;
            }
        }
    }
    int now=0;
    vector<int> in(n+1,0);
    vector cnt(K+1,vector(K+1,int(0)));
    for(int t=1;t<=m;t++)
    {
        auto [o,a]=queries[t];
        auto [x,y]=z[a];
        now+=d[t];
        for(int i=2;i<=K;i++) now+=cnt[i][t%i];
        if(x+y<=K)
        {
            if(o==1)
            {
                cnt[x+y][(t+x)%(x+y)]++;
                cnt[x+y][t%(x+y)]--;
                in[a]=t;
            }
            else
            {
                int u=in[a];
                cnt[x+y][(u+x)%(x+y)]--;
                cnt[x+y][u%(x+y)]++;
                int r=(t-u)%(x+y);
                if(r>=x) now--;
            }
        }
        cout << now << "\n";
    }
    return 0;
}