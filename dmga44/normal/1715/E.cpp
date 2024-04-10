#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper") // Enable AVX

/// UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
typedef pair<ll, ll> pii;
typedef pair<ld, ll> pdi;
typedef pair<ld, ld> pdd;
typedef pair<ld, pdd> pdp;
typedef pair<string, ll> psi;
typedef pair<ll, string> pls;
typedef pair<string, string> pss;
typedef pair<ll, pii> pip;
typedef pair<pii, pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point, int> ppi;
#define prec(n)        \
    cout.precision(n); \
    cout << fixed
const ll mod = (1e9 + 7);
const ld eps = (1e-9);
const ll oo = (ll)(1e18 + 5);
#define pi acos(-1)
#define MAXN (ll)(1e5 + 5)

ll cross(point a, point b) { return imag(conj(a) * b); } ///a_x*b_y-b_x*a_y

ll dot(point a, point b) { return real(conj(a) * b); } /// a_x*b_x+a_y*b_y

ll area2(point a, point b, point c) { return cross(b - a, c - a); }

namespace std
{
	bool operator<(const point &a, const point &b)
	{
		return real(a) < real(b) || (real(a) == real(b) && imag(a) < imag(b));
	}
}

struct dynamic_hull
{
	dynamic_hull() : hulls() {}

	void add_point(point p)
	{
		prev.push_back(p);
	}

	ll max_dot(point p)
	{
		return hulls.max_dot(p);
	}

	struct hull : vector<point>
	{
		void add_point(point p)
		{
			for (int s = size(); s > 1; --s)
				if (area2(at(s - 2), at(s - 1), p) < 0) break;
				else pop_back();
			push_back(p);
		}

		ll max_dot(point p)
		{
			int lo = 0, hi = (int) size() - 1, mid;

			while (lo < hi)
			{
				mid = (lo + hi) / 2;

				if (dot(at(mid), p) <= dot(at(mid + 1), p))
					lo = mid + 1;
				else hi = mid;
			}

			return dot(at(lo), p);
		}
	};
	
    void merge()
	{
		sort(all(prev));

        for(auto p : prev)
            hulls.add_point(p);
	}

	hull hulls,prev;
};

vector<pii> g[MAXN];

vector<ll> dijkstra(int n)
{
    vector<ll> dis(n,1e11);
    vector<bool> mk(n);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(pii(0,0));
    while(!pq.empty())
    {
        pii x=pq.top();
        pq.pop();

        int u=x.second;
        ll w=x.first;
        if(mk[u])
            continue;
        dis[u]=w;
        mk[u]=1;
        for(auto e : g[u])
            if(!mk[e.first])
                pq.push(pii(w+e.second,e.first));
    }
    return dis;
}

vector<ll> solve(vector<ll> act)
{
    int n=act.size();
    vector<ll> dis=act;
    vector<bool> mk(n);
    priority_queue<pii,vector<pii>,greater<pii>> pq;

    // for(int i=0;i<n;i++)
    //     cout << act[i] << ' ';
    // cout << '\n';

    dynamic_hull dp;
    for(ll i=0;i<n;i++)
        dp.add_point(point(-(act[i]+i*i),2*i));

    dp.merge();

    for(ll i=0;i<n;i++)
    {
        // cout << -dp.max_dot(point(i,1))+i*i << ' ' << i << '\n';
        pq.push(pii(-dp.max_dot(point(1,i))+i*i,i));
    }

    while(!pq.empty())
    {
        pii x=pq.top();
        pq.pop();

        int u=x.second;
        ll w=x.first;
        if(mk[u])
            continue;
        dis[u]=min(dis[u],w);
        mk[u]=1;
        for(auto e : g[u])
            if(!mk[e.first])
                pq.push(pii(w+e.second,e.first));
    }
    return dis;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
    }

    vector<ll> adv0=dijkstra(n);

    for(int i=0;i<k;i++)
        adv0=solve(adv0);

    for(int i=0;i<n;i++)
        cout << adv0[i] << ' ';
    cout << '\n';

    return 0;
}