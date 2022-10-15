#include <bits/stdc++.h>

using namespace std;


const int N=(int) 2e5+7;
const int K=(int) 1e6+7;
int n, q, s, d, a[N], mn[N], now, t[N], inv[K];
vector<int> rep[N];
vector<pair<int, int>> g[N];
bool pot[N];

int root(int a)
{
        if (t[a]==a)
                return a;
        return t[a]=root(t[a]);
}

void unite(int a, int b, int cost)
{
        g[a].push_back({b, cost});
        g[b].push_back({a, cost});

        a=root(a);
        b=root(b);

        if ((int) rep[a].size()<(int) rep[b].size())
                swap(a,b);


        t[b]=a;
        for (auto &x:rep[b])
                rep[a].push_back(x);
        rep[b].clear();
}


void prop(int i, int k)
{
        if (!pot[i])
                mn[i]=now;
        pot[i]=1;
        for (int j=1; j<=n; j++)
        {
                if (!pot[j] && k>=abs(d-abs(a[j]-a[i])))
                {
                        prop(j, k);
                }
        }
}

set<int> st;

int sa, sb, sc;

void upd(int a, int b, int c)
{
        if (c<sc)
                sa=a, sb=b, sc=c;
}

void upd(int i, int j)
{
        int c=abs(d-abs(a[i]-a[j]));
        upd(i, j, c);
}

void dfs(int a, int cur)
{
        mn[a]=cur;
        for (auto &it:g[a])
        {
                int b=it.first, ncur=max(cur, it.second);
                if (mn[b]==-1)
                        dfs(b, ncur);
        }
}

signed main()
{
       /// freopen ("input", "r", stdin);
        ios::sync_with_stdio(0); cin.tie(0); /// NOT just for aesthetics this time

        cin>>n>>q>>s>>d;
        for (int i=1; i<=n; i++)
        {
                cin>>a[i];
                mn[i]=-1;
                t[i]=i;
                rep[i]={i};
                st.insert(a[i]);
                inv[a[i]]=i;
        }
        /// cu cat k e mai mare cu atat pot sa ajung la mai multe :P

        pot[s]=1;
        mn[s]=0;

        while (1)
        {
                int comps=0;
                for (int i=1; i<=n; i++)
                        comps+=(t[i]==i);
                if (comps==1)
                        break;
              ///  cout<<"comps = "<<comps<<"\n";
                vector<vector<int>> edges;
                for (int i=1; i<=n; i++)
                {
                        if (rep[i].empty())
                                continue;
                        for (auto &x:rep[i])
                                st.erase(a[x]);

                        sa=sb=sc=(int) 1e9;

                        for (auto &x:rep[i])
                        {
                                int pos=a[x];
                                vector<int> pp={pos-d, pos+d};
                                for (auto &p : pp)
                                {
                                        auto it=st.lower_bound(p);
                                        if (it!=st.end())
                                        {
                                                upd(x, inv[*it]);
                                        }
                                        if (it!=st.begin())
                                        {
                                                it--;
                                                upd(x, inv[*it]);
                                        }
                                }
                        }
                        if (sc==(int) 1e9)
                        {
                             //   cout<<"lol : "<<(int)rep[i].size()<<" plus "<<(int)st.size()<<"\n";
                        }
                        assert(sc!=(int) 1e9);
                        edges.push_back({sa, sb, sc});

                        for (auto &x:rep[i])
                                st.insert(a[x]);
                }
                for (auto &vec : edges)
                {
                        if (root(vec[0])!=root(vec[1]))
                                unite(vec[0], vec[1], vec[2]);
                }
               /// cout<<"done\n";
        }

        dfs(s, 0);

        /**
        for (int i=1; i<=n; i++)
        {
                cout<<i<<" ---> "<<mn[i]<<"\n";
        }

        for (int i=1; i<=n; i++)
                cout<<root(i)<<" ";
        cout<<"\n";**/

        /**
        for (int k=1; k<K; k++)
        {
                now=k;
                for (int i=1; i<=n; i++)
                        if (pot[i])
                                prop(i, k);
        }**/

        for (int i=1; i<=n; i++)
        {
                assert(mn[i]!=-1);
              ///  cout<<i<<" : "<<mn[i]<<"\n";
        }

        while (q--)
        {

                int qs, k;
                cin>>qs>>k;
                cout<<((mn[qs]<=k)?"Yes":"No")<<"\n";
        }


        return 0;
}


/**

**/