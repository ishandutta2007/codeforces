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
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

vector<int> g[MAXN];
int cantf[MAXN];
int cantp[MAXN];
int backs[MAXN];
bool mk[MAXN];
int n,k;

vector<vector<int>> scc_gabow(vector<int>* adj)
{
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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    int root=0;
    vector<int> pre(n);
    for(int i=0;i<n;i++)
    {
        int p;
        cin >> p;
        pre[i]=p;
        if(p==0)
        {
            root=i;
            continue;
        }
        p--;
        g[p].push_back(i);
    }

    for(int i=0;i<n;i++)
        backs[i]=-1;
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin >> x >> y;
        x--,y--;
        g[x].push_back(y);
        cantp[x]++;
        cantf[y]++;
        backs[x]=y;
    }

    int es=0;
    vector<int> ts;
    for(int i=0;i<n;i++)
        if(!cantf[i] && cantp[i])
            ts.push_back(i);

    vector<int> points(n);
    for(int i=0;i<n;i++)
        points[i]=i;
    for(auto y : ts)
    {
        int u=y;
        vector<int> ps;
        ps.push_back(u);
        while(backs[u]!=-1)
        {
            u=backs[u];
            ps.push_back(u);
            es++;
        }
        for(auto y : ps)
            points[y]=ps.back();
    }
    if(es!=k)
    {
        db(0)
        return 0;
    }
    for(auto y : ts)
    {
        int u=y;
        vector<int> ps;
        ps.push_back(u);
        mk[u]=1;
        while(backs[u]!=-1)
        {
            u=backs[u];
            mk[u]=1;
            ps.push_back(u);
        }
        for(auto y : ps)
        {
            if(pre[y] && !mk[pre[y]-1])
                g[points[pre[y]-1]].push_back(ps[0]);
        }
        for(auto y : ps)
            mk[y]=0;
    }

    vector<vector<int>> res;
    res=scc_gabow(g);
    reverse(all(res));
    if(res.size()==n)
    {
        mk[0]=1;
        bool ok=1;
        vector<int> rres;
        for(auto y : res)
        {
//            for(auto v : y)
//                cout << v << ' ';
//            cout << '\n';
            if(mk[y[0]+1])
                continue;
            ok&=(mk[pre[y[0]]]);
            mk[y[0]+1]=1;
            int u=y[0];
            rres.push_back(u);
            while(backs[u]!=-1)
            {
                u=backs[u];
                ok&=(mk[pre[u]]);
                mk[u+1]=1;
                rres.push_back(u);
            }
        }
        if(ok)
        {
            for(auto y : rres)
                cout << y+1 << ' ';
            cout << '\n';
        }
        else
            db(0)
    }
    else
        db(0)

    return 0;
}