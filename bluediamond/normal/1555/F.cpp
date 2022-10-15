#include <bits/stdc++.h>

using namespace std;

const int Q=(int) 5e5+7;
const int N=(int) 3e5+7;
const int K=21;
int n, q, daata[Q][3], t[N], euler[2*N], top, lg[2*N], first[N], last[N], dep[N], pre[N], par[N], ll[N], rr[N], top2;
pair<int, int> rmq[2*N][K];
bool vis[N];
bool unites2[Q];
int unites[N];
vector<pair<int, int>> g[N];

int root(int a)
{
        if (t[a]==a)
                return a;
        else
                return t[a]=root(t[a]);
}

void unite(int a, int b)
{
        t[root(a)]=root(b);
}

void setup()
{
        for (int i=1; i<=n; i++)
                t[i]=i;
}

void addEdge(int a, int b, int x)
{
        g[a].push_back({b, x});
        g[b].push_back({a, x});
}

void dfs(int a)
{
        ll[a]=++top2;
        vis[a]=1;
        euler[++top]=a;
        first[a]=last[a]=top;

        for (auto &it:g[a])
        {
                int b=it.first;
                if (!vis[b])
                {
                        par[b]=a;
                        dep[b]=1+dep[a];
                        pre[b]=pre[a]^it.second;
                        dfs(b);
                        euler[++top]=a;
                        last[a]=top;
                }
        }
        rr[a]=++top2;
}

int lca(int a, int b)
{
        if (first[a]>last[b])
                swap(a, b);
        a=first[a];
        b=last[b];
        if (a>b)
        {
                cout<<"bad\n";
                exit(0);
        }
        int k=lg[b-a+1];
        return min(rmq[a][k], rmq[b-(1<<k)+1][k]).second;
}

int used[N], aib[2*N];

void add(int i, int x)
{
        while (i<=2*n) aib[i]+=x, i+=i&(-i);
}

int pref(int i)
{
        int sol=0;
        while (i)
        {
                sol+=aib[i];
                i-=i&(-i);
        }
        return sol;
}

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

      ///  freopen ("input", "r", stdin);

        cin>>n>>q;
        setup();
        for (int i=1; i<=q; i++)
        {
                cin>>daata[i][0]>>daata[i][1]>>daata[i][2];
                if (root(daata[i][0])!=root(daata[i][1]))
                {
                        unite(daata[i][0], daata[i][1]);
                        unites2[i]=1;
                        addEdge(daata[i][0], daata[i][1], daata[i][2]);
                }
        }

        for (int i=1; i<=n; i++)
        {
                if (!vis[i])
                        dfs(i);
        }

        for (int i=2; i<=top; i++)
                lg[i]=1+lg[i/2];

        for (int i=1; i<=top; i++)
                rmq[i][0]={dep[euler[i]], euler[i]};

        for (int k=1; (1<<k)<=top; k++)
                for (int i=1; i+(1<<k)-1<=top; i++)
                        rmq[i][k]=min(rmq[i][k-1], rmq[i+(1<<(k-1))][k-1]);


        for (int i=1; i<=q; i++)
        {
                int a, b, x;
                a=daata[i][0];
                b=daata[i][1];
                x=daata[i][2];
                if (unites2[i])
                {
                        cout<<"YES\n";
                        continue;
                }
                int cycle_value=pre[a]^pre[b]^x;
                if (cycle_value==0)
                {
                        cout<<"NO\n";
                        continue;
                }
                int c=lca(a, b);


                if (pref(ll[a])+pref(ll[b])-2*pref(ll[c])>0)
                {
                        cout<<"NO\n";
                        continue;
                }
                vector<int> aa, bb;

                while (a!=c) aa.push_back(a), a=par[a];
                while (b!=c) bb.push_back(b), b=par[b];
                for (auto &x : aa) add(ll[x], +1), add(rr[x], -1);
                for (auto &x : bb) add(ll[x], +1), add(rr[x], -1);

                cout<<"YES\n";
                //cout<<"???\n";

        }



        return 0;
}