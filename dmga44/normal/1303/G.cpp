#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 150005

vector<int> g[MAXN],nodes;
ll a[MAXN],sons[MAXN][2];
bool mk1[MAXN],mk2[MAXN];
ll res;

typedef complex<ll> point;

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

const ll oo = 0x3f3f3f3f3f3f3f3f;

struct dynamic_hull
{
	dynamic_hull() : hulls() {}

	void add_point(point p)
	{
		hull h;
		h.add_point(p);

		for (hull &_h : hulls)
			if (_h.empty())
			{
				h.swap(_h);
				break;
			}
			else h = merge(h, _h), _h.clear();

		if (!h.empty()) hulls.emplace_back(h);
	}

	ll max_dot(point p)
	{
		ll best = -oo;

		for (hull &h : hulls)
			if (!h.empty()) best = max(best, h.max_dot(p));

		return best;
	}

private:
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

	static hull merge(const hull &a, const hull &b)
	{
		hull h;
		size_t i = 0, j = 0;

		while (i < a.size() && j < b.size())
			if (a[i] < b[j]) h.add_point(a[i++]);
			else h.add_point(b[j++]);

		while (i < a.size()) h.add_point(a[i++]);

		while (j < b.size()) h.add_point(b[j++]);

		return h;
	}

	vector<hull> hulls;
};

void dfs(int u)
{
    mk1[u]=1;
    sons[u][0]=1;
    nodes.push_back(u);
    for(auto v : g[u])
        if(!mk1[v] && !mk2[v])
        {
            dfs(v);
            sons[u][0]+=sons[v][0];
            sons[u][1]=max(sons[v][0],sons[u][1]);
        }
}

vector<pii> t1,t2;

void dfs1(int u,ll ac1,ll acs,ll ac2,ll level)
{
    level++;
    ac2+=a[u]*level;
    acs+=a[u];
    ac1+=acs;
    nodes.push_back(u);
    t1.push_back(pii(ac1,level+1));
    t2.push_back(pii(ac2,acs));

    mk1[u]=1;
    for(auto v : g[u])
        if(!mk1[v] && !mk2[v])
            dfs1(v,ac1,acs,ac2,level);
}

void solve(int u)
{
    dfs(u);

    int cent=-1,cant=nodes.size()/2;
    for(auto v : nodes)
    {
        if(cent==-1 && sons[v][0]>=cant && sons[v][1]<=cant)
            cent=v;
        mk1[v]=0;
        sons[v][0]=sons[v][1]=0;
    }
    nodes.clear();

//    db(cent)
    mk2[cent]=1;
    dynamic_hull dp1,dp2;
    dp1.add_point(point(a[cent],1));
    dp2.add_point(point(0,0));
    for(auto v : g[cent])
    {
        if(mk2[v])
            continue;
        dfs1(v,a[cent],a[cent],0,0);

//        for(auto y : t1)
//            cout << "t1 " << y.first << ' ' << y.second << '\n';
//        for(auto y : t2)
//            cout << "t2 " << y.first << ' ' << y.second << '\n';

        for(auto y : t1)
            res=max(res,y.first+dp2.max_dot(point(1,y.second)));
        for(int i=0;i<t2.size();i++)
        {
            t2[i].second-=a[cent];
            auto y=t2[i];
            res=max(res,y.first+dp1.max_dot(point(1,y.second)));
            dp2.add_point(point(t2[i].first,t2[i].second));
        }
        for(auto y : t1)
            dp1.add_point(point(y.first,y.second));

        t1.clear();
        t2.clear();
        for(auto vv : nodes)
            mk1[vv]=0;
        nodes.clear();
    }

    for(auto y : g[cent])
        if(!mk2[y])
            solve(y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=0;i<n;i++)
        cin >> a[i];

    solve(0);

    db(res)

    return 0;
}
/**
4
4 2
3 2
4 1
1 3 3 7

2
1 2
1 2
**/