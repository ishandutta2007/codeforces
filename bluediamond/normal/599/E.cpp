#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=13;
const int Q=100;
int n, m, q, e[N][2], x[Q], y[Q], lca[Q];
ll dp[1<<N][N][2];
bool santa[1<<N][N];
bool act[N];
vector<int> g[N];
vector<int> restr[N];
bool need[N][N];
int bb[1<<N];

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

       // freopen ("input", "r", stdin);

        for (int m=0; m<(1<<N); m++)
        {
                for (int i=0; i<N; i++)
                {
                        if (m&(1<<i))
                                bb[m]=i;
                }
        }

        cin>>n>>m>>q;
        for (int i=0; i<m; i++)
        {
                cin>>e[i][0]>>e[i][1];
                e[i][0]--;
                e[i][1]--;
                g[e[i][0]].push_back(e[i][1]);
                g[e[i][1]].push_back(e[i][0]);
                need[e[i][0]][e[i][1]]=1;
                need[e[i][1]][e[i][0]]=1;
        }
        for (int i=0; i<q; i++)
        {
                cin>>x[i]>>y[i]>>lca[i];
                x[i]--;
                y[i]--;
                lca[i]--;
                restr[lca[i]].push_back(i);
        }
        for (int mask=1; mask<(1<<n); mask++)
        {
                vector<int> nodes;
                for (int i=0; i<n; i++)
                        if (mask&(1<<i))
                        {
                                act[i]=1;
                                nodes.push_back(i);
                        }
                        else
                        {
                                act[i]=0;
                        }
                for (auto &root : nodes)
                {
                        for (int fe=0; fe<=1; fe++)
                        {
                                /// compute dp[mask][root]
                                ll &sol=dp[mask][root][fe];


                                bool aredif=0;
                                bool ok=1;
                                for (auto &i : restr[root])
                                {
                                        if (fe)
                                        {
                                                ok&=(act[x[i]]);
                                                ok&=(act[y[i]]);
                                        }
                                        if (act[x[i]] && act[y[i]])
                                        {
                                                aredif|=(x[i]!=root && y[i]!=root);
                                        }
                                }

                                vector<int> others;

                                for (auto &i : g[root])
                                {
                                        if (!act[i])
                                                others.push_back(i);
                                }

                                bool init=ok;

                                if (fe)
                                {
                                        
                                        if (root==0)
                                        {
                                                if ((int) others.size()>0) ok=0;
                                        }
                                        else
                                        {
                                                if ((int) others.size()>1) ok=0;
                                                if ((int) others.size()==1) santa[mask][root]=1;
                                        }
                                }


                                if (!ok)
                                        continue;

                                if (mask==(1<<root))
                                {
                                       // if (!aredif)
                                        {
                                                sol++;
                                        }
                                        continue;
                                }

                                int othermask=mask-(1<<root);

                                int big=bb[othermask];
                                vector<int> subs;

                                {
                                        int cop=othermask-(1<<big);
                                        while (cop)
                                        {
                                                subs.push_back(cop);
                                                cop=(cop-1)&(othermask-(1<<big));
                                        }
                                        subs.push_back(0);
                                        /// add big to them
                                        for (auto &it : subs)
                                                it+=(1<<big);
                                }

                                for (auto &lastmask : subs)
                                {
                                        int kek=othermask-lastmask;
                                        vector<int> bits;
                                        for (int node=0; (1<<node)<=lastmask; node++)
                                        {
                                                if (lastmask&(1<<node))
                                                {
                                                        bits.push_back(node);
                                                }
                                        }
                                        for (auto &vec : bits)
                                        {
                                                ok=1;
                                                /// check vecini
                                                for (auto &j : bits)
                                                {
                                                        if (j!=vec && need[j][root])
                                                        {
                                                                ok=0;
                                                        }
                                                }
                                                if (!ok) continue;
                                                /// check lca stuff
                                                for (auto &i : restr[root])
                                                {
                                                        if (x[i]!=root && y[i]!=root)
                                                        {
                                                                bool xx=!!(lastmask&(1<<x[i]));
                                                                bool yy=!!(lastmask&(1<<y[i]));
                                                                if (xx && yy) ok=0;
                                                        }
                                                }
                                                if (!ok) continue;
                                                if (santa[lastmask][vec])
                                                {
                                                        if (!need[root][vec]) continue;
                                                }
                                                sol+=dp[lastmask][vec][1]*dp[mask-lastmask][root][0];
                                        }
                                }
                        }
                        /// selectez grupul ultimului

                }
        }
    //    cout<<"sol = "<<dp[(1<<1)+(1<<2)+(1<<3)][1][1]<<"\n";
       // cout<<dp[(1<<1)+(1<<2)+(1<<3)][1]<<"\n";

      //  return 0;
        cout<<dp[(1<<n)-1][0][1]<<"\n";
}