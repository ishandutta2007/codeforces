#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
//typedef complex<ld> point;
#define MAXN 2005
#define mod (ll)(1e9+7)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)

vector<pii> g[MAXN];
ll dp[MAXN][MAXN];

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

struct hull : vector<point>
{
    void add_point(point p)
    {
        for (int s = size(); s > 1; --s)
            if (area2(at(s - 2), at(s - 1), p) < 0) break;
            else pop_back();
        while(!empty() && back().imag()<=p.imag())
            pop_back();
        push_back(p);
    }
};

ll solve(point p,ll l,ll r)
{
//    cout << l << ' ' << r << '\n';
    ll d=p.real();
    ll base=(p.imag()+l*d)%mod;
    ll len=r-l+1;
    ll ss=((len*(len-1))/2)%mod;
    return (base*len+d*ss)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q,u,v,w;
    cin >> n >> m >> q;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v >> w;
        u--,v--;
        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
    }

    for(int i=0;i<=n;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=-oo;
    dp[0][0]=0;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            for(auto y : g[j])
            {
                int v=y.f;
                dp[i+1][v]=max(dp[i+1][v],dp[i][j]+y.s);
            }
        ll add=0;
        for(int j=0;j<n;j++)
            add=max(add,dp[i+1][j]);
        res=(res+add)%mod;
    }
//    db(res)

    vector<point> vs;
    for(int i=0;i<n;i++)
    {
        ll ma=0;
        for(auto y : g[i])
            ma=max(ma,y.s);
        if(dp[n][i]>=0)
            vs.push_back(point(ma,dp[n][i]));
    }

    sort(all(vs));

    hull vals;
    vals.clear();
    for(auto y : vs)
        vals.add_point(y);
//    db(vals.size())
//    for(auto y : vals)
//        cout << y.real() << ' ' << y.imag() << '\n';

    q-=n;
    int len=vals.size();
    ll last=0;
    for(int i=0;i<len-1;i++)
    {
        if(last==q)
            break;
        ll lim=last+1;
        for(int po=(1<<30);po;po>>=1)
            if(vals[i].real()*(lim+po)+vals[i].imag()>=vals[i+1].real()*(lim+po)+vals[i+1].imag())
                lim+=po;
        lim=min(lim,(ll)q);
        res=(res+solve(vals[i],last+1,lim))%mod;
        last=lim;
    }
    if(last!=q)
        res=(res+solve(vals[len-1],last+1,q))%mod;
    db(res)

    return 0;
}
/**
7 8 25
1 2 1
2 3 10
3 4 2
1 5 2
5 6 7
6 4 15
5 3 1
1 7 3

2 1 5
2 1 4

15 15 23
13 10 12
11 14 12
2 15 5
4 10 8
10 2 4
10 7 5
3 10 1
5 6 11
1 13 8
9 15 4
4 2 9
11 15 1
11 12 14
10 8 12
3 6 11

5 10 10000000
2 4 798
1 5 824
5 2 558
4 1 288
3 4 1890
3 1 134
2 3 1485
4 5 284
3 5 1025
1 2 649
**/