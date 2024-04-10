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
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(4e5+5)

string s[MAXN];
vector<int> g2[MAXN];

struct graph
{
	int n;
	vector<vector<int>> adj;
    vector<int> f;

	graph(int n) : n(n), adj(n),f(n) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
		g2[v].push_back(u);
		f[v]++;
	}

	vector<int>& operator[](int u) { return adj[u]; }
};

vector<vector<int>> scc_gabow(graph &adj)
{
	int n = adj.n;

	vector<vector<int>> scc;
	vector<int> S, B, I(n);

	function<void(int)> dfs = [&](int u)
	{
		B.push_back(I[u] = S.size());
		S.push_back(u);

		for (int v : adj[u])
			if (!I[v]) dfs(v);
			else while (I[v] < B.back()) B.pop_back();

		if (I[u] == B.back())
		{
			scc.push_back({});
			for (B.pop_back(); I[u] < S.size(); S.pop_back())
			{
				scc.back().push_back(S.back());
				I[S.back()] = n + scc.size();
			}
		}
	};

	for (int u = 0; u < n; ++u)
		if (!I[u]) dfs(u);

	return scc; // in reverse topological order
}

int n,m;

int trans(int i,int j)
{
    return i*m+j;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> s[i];

    vector<int> a(m);
    int sum=0;
    for(int i=0;i<m;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    if(sum==0)
    {
        db(0)
        return 0;
    }

    graph g(n*m);
    for(int i=0;i<n;i++)
        for(int j=1;j<m;j++)
            if(s[i][j]=='#' && s[i][j-1]=='#')
            {
                g.add_edge(trans(i,j),trans(i,j-1));
                g.add_edge(trans(i,j-1),trans(i,j));
            }
    for(int i=1;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='#' && s[i-1][j]=='#')
            {
                g.add_edge(trans(i,j),trans(i-1,j));
                g.add_edge(trans(i-1,j),trans(i,j));
            }


    for(int i=1;i<n;i++)
        for(int j=0;j<m;j++)
            if((s[i][j]=='.' && s[i-1][j]=='#') || g.f[trans(i-1,j)])
                g.add_edge(trans(i-1,j),trans(i,j));

    for(int i=0;i<n;i++)
        for(int j=1;j<m;j++)
        {
            if(s[i][j-1]=='#' && s[i][j]=='.' && g.f[trans(i,j)])
                g.add_edge(trans(i,j),trans(i,j-1));
            if(s[i][j]=='#' && s[i][j-1]=='.' && g.f[trans(i,j-1)])
                g.add_edge(trans(i,j-1),trans(i,j));
        }

    vector<vector<int>> sccs=scc_gabow(g);

    vector<int> scc(n*m);
    for(int i=0;i<sccs.size();i++)
        for(auto u : sccs[i])
            scc[u]=i;
    int cant_scc=sccs.size();
    vector<pii> rep(cant_scc,pii(-1,-1));
    for(int i=0;i<m;i++)
        if(a[i])
        {
            int act=a[i];
            for(int j=n-1;1;j--)
            {
                if(s[j][i]=='#')
                    act--;
                if(!act)
                {
                    if(rep[scc[trans(j,i)]]==pii(-1,-1))
                        rep[scc[trans(j,i)]]=pii(i,i);
                    else
                        rep[scc[trans(j,i)]]=pii(rep[scc[trans(j,i)]].f,i);
                    break;
                }
            }
        }

//    for(auto p : rep)
//        cout << p.f << ' ' << p.s << '\n';
//    db("xxx")
    vector<bool> mk(cant_scc);
    vector<bool> mk2(cant_scc);
    for(int i=cant_scc-1;i>=0;i--)
    {
        if(mk2[i] || rep[i]==pii(-1,-1))
            continue;
        queue<int> q;
        q.push(i);
        mk2[i]=1;
        mk[i]=1;
//        cout << i << ' ';
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto v : sccs[u])
                for(auto w : g[v])
                    if(scc[w]!=u && !mk2[scc[w]])
                    {
                        q.push(scc[w]);
                        mk2[scc[w]]=1;
                    }
        }
    }
//    cout << '\n';

    vector<pip> ts1;
    int cont=0;
    for(int i=0;i<rep.size();i++)
    {
        if(mk[i])
        {
            int mi=m;
            int ma=0;
            for(int u : sccs[i])
                if(s[u/m][u%m]=='#')
                {
                    mi=min(mi,u%m);
                    ma=max(ma,u%m);
                }
            ts1.push_back(pip(mi,pii(ma,i)));
        }
        else
            ts1.push_back(pip(-1,pii(-1,i)));
    }
    sort(all(ts1));
    for(int i=0;i<rep.size();i++)
    {
        if((ts1[i].f==-1 && ts1[i].s.f==-1) || !mk[ts1[i].s.s])
        {
            rep[ts1[i].s.s]=pii(-1,-1);
            continue;
        }
        rep[ts1[i].s.s]=pii(cont,cont);
        cont++;
    }
//    for(auto p : rep)
//        cout << p.f << ' ' << p.s << '\n';
//    db("xxx")

    for(auto vn : sccs)
    {
        if(pii(-1,-1)==rep[scc[vn[0]]])
            continue;
        for(auto u : vn)
            for(auto v : g2[u])
            {
                if(scc[u]==scc[v])
                    continue;
                if(rep[scc[v]]==pii(-1,-1))
                    rep[scc[v]]=rep[scc[u]];
                else
                    rep[scc[v]]=pii(min(rep[scc[v]].f,rep[scc[u]].f),max(rep[scc[v]].s,rep[scc[u]].s));
            }
    }

    int ans=0;
    vector<pii> ts;
    for(int i=0;i<sccs.size();i++)
        if(rep[i]!=pii(-1,-1))
            ts.push_back(pii(rep[i].f,-rep[i].s));

    sort(all(ts));

//    for(int i=0;i<ts.size();i++)
//        cout << ts[i].f << ' ' << -ts[i].s << '\n';

    int last=-1;
    int pos=0;
    while(pos<ts.size())
    {
        if(ts[pos].f>last)
        {
            last=-ts[pos].s;
            pos++;
            ans++;
        }
        else
        {
            int n_last=last;
            while(pos<ts.size() && ts[pos].f<=last+1)
            {
                n_last=max(n_last,(int)-ts[pos].s);
                pos++;
            }
//            cout << n_last << ' ' << last << '\n';
            if(n_last>last)
                ans++;
            last=n_last;
        }
//        db("")
//        cout << pos << ' ' << last << '\n';
    }
    db(ans)

    return 0;
}
/**
3 6
..#..#
......
#####.
1 1 2 1 1 1

**/