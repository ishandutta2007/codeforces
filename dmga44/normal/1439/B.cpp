#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(2e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

set<int> g[MAXN];
bool ady[MAXN/30+5][MAXN/30+5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        for(int i=0;i<n;i++)
            g[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            g[u].insert(v);
            g[v].insert(u);
        }
        if(k>70)
        {
            vector<int> oks;
            for(int i=0;i<n;i++)
                if(g[i].size()>=k-1)
                    oks.push_back(i);
            vector<int> pos(n);
            for(int i=0;i<oks.size();i++)
            {
                pos[oks[i]]=i+1;
                for(int j=0;j<oks.size();j++)
                    ady[i][j]=0;
            }
            vector<int> cant(n);

            for(auto u : oks)
                for(auto v : g[u])
                    if(pos[v])
                    {
                        cant[u]++;
                        ady[pos[u]-1][pos[v]-1]=1;
                        ady[pos[v]-1][pos[u]-1]=1;
                    }

            queue<int>q;
            vector<bool> mk(n);
            for(int i=0;i<n;i++)
                if(cant[i]<k)
                {
                    mk[i]=1;
                    q.push(i);
                }

            bool clique=0;
            vector<int> ans;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                if(cant[u]<k-1)
                {
                    for(int i=0;i<oks.size();i++)
                        if(ady[i][pos[u]-1])
                        {
                            ady[i][pos[u]-1]=0;
                            ady[pos[u]-1][i]=0;
                            cant[oks[i]]--;
                            if(cant[oks[i]]<k && !mk[oks[i]])
                            {
                                mk[oks[i]]=1;
                                q.push(oks[i]);
                            }
                        }
                }
                else
                {
                    vector<int> ads;
                    for(int i=0;i<oks.size();i++)
                        if(ady[i][pos[u]-1])
                            ads.push_back(i);
                    clique=1;
                    for(auto u : ads)
                    {
                        for(auto v : ads)
                            if(u!=v)
                                clique&=ady[u][v];
                        if(!clique)
                            break;
                    }

                    if(clique)
                    {
                        ans=ads;
                        ans.push_back(pos[u]-1);
                        break;
                    }
                    for(int i=0;i<oks.size();i++)
                        if(ady[i][pos[u]-1])
                        {
                            ady[i][pos[u]-1]=0;
                            ady[pos[u]-1][i]=0;
                            cant[oks[i]]--;
                            if(cant[oks[i]]<k && !mk[oks[i]])
                            {
                                mk[oks[i]]=1;
                                q.push(oks[i]);
                            }
                        }
                }
            }

            if(clique)
            {
                cout << 2 << '\n';

                for(int i=0;i<ans.size();i++)
                {
                    ans[i]=oks[ans[i]];
                    cout << ans[i]+1 << ' ';
                }
                cout <<'\n';
                continue;
            }
            ans.clear();
            for(int i=0;i<n;i++)
                if(!mk[i])
                    ans.push_back(i);
            if(ans.size()>k)
            {
                cout << 1 << ' ' << ans.size() << '\n';
                for(int i=0;i<ans.size();i++)
                    cout << ans[i]+1 << ' ';
                cout <<'\n';
                continue;
            }
            else
                db(-1)
        }
        else
        {
            queue<int>q;
            vector<bool> mk(n);
            for(int i=0;i<n;i++)
                if(g[i].size()<k)
                {
                    mk[i]=1;
                    q.push(i);
                }

            bool clique=0;
            vector<int> ans;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                if(g[u].size()<k-1)
                {
                    for(auto v : g[u])
                    {
                        g[v].erase(u);
                        if(g[v].size()<k && !mk[v])
                        {
                            mk[v]=1;
                            q.push(v);
                        }
                    }
                }
                else
                {
                    ans.clear();
                    ans.push_back(u);
                    for(auto v : g[u])
                        ans.push_back(v);
                    clique=1;
                    for(auto u : ans)
                        for(auto v : ans)
                            if(u!=v)
                                clique&=g[u].count(v);

                    if(clique)
                        break;
                    for(auto v : g[u])
                    {
                        g[v].erase(u);
                        if(g[v].size()<k && !mk[v])
                        {
                            mk[v]=1;
                            q.push(v);
                        }
                    }
                }
            }

            if(clique)
            {
                cout << 2 << '\n';
                for(int i=0;i<ans.size();i++)
                    cout << ans[i]+1 << ' ';
                cout <<'\n';
                continue;
            }
            ans.clear();
            for(int i=0;i<n;i++)
                if(!mk[i])
                    ans.push_back(i);
            if(ans.size()>k)
            {
                cout << 1 << ' ' << ans.size() << '\n';
                for(int i=0;i<ans.size();i++)
                    cout << ans[i]+1 << ' ';
                cout <<'\n';
                continue;
            }
            else
                db(-1)
        }
    }

    return 0;
}
/**
3
5 9 4
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
10 15 3
1 2
2 3
3 4
4 5
5 1
1 7
2 8
3 9
4 10
5 6
7 10
10 8
8 6
6 9
9 7
4 5 4
1 2
2 3
3 4
4 1
1 3

1
5 9 4
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5

1
100 1 22
1 2
**/