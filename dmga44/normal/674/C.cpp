#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-6)
//#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

//typedef long long ll;
//typedef complex<ll> point;

ld cross(point a, point b) { return imag(conj(a) * b); } ///a_x*b_y-b_x*a_y

ld dot(point a, point b) { return real(conj(a) * b); } /// a_x*b_x+a_y*b_y

ld area2(point a, point b, point c) { return cross(b - a, c - a); }

namespace std
{
	bool operator<(const point &a, const point &b)
	{
		return real(a) < real(b) || (real(a) == real(b) && imag(a) < imag(b));
	}
}

const ld oo = 0x3f3f3f3f3f3f3f3f;

struct hull : vector<ppi>
{
    hull() : m(0) {}
    int m;
    void add_point(ppi p)
    {
        for (int s = size(); s > 1; --s)
            if (area2(at(s - 2).f, at(s - 1).f, p.f) < 0) break;
            else pop_back();
        push_back(p);
        m=min(m,(int)(size()-1));
    }

    pdi max_dot(point p)
    {
        while(m<(size()-1) && dot(at(m).f,p)<dot(at(m+1).f,p))
            m++;
        return pdi(dot(at(m).f, p),at(m).s);
    }
};

ld S[MAXN],s[MAXN],d[MAXN];
pdi dp[MAXN];
ld t[MAXN];
int n,k;

void solve(ld cost)
{
    hull h;
    for(int j=1;j<=n;j++)
    {
        h.add_point(ppi(point(s[j-1],-(dp[j-1].f-S[j-1])-s[j-1]*d[j-1]),dp[j-1].s));
        pdi xxx=h.max_dot(point(d[j],1));
        dp[j]=pdi(-xxx.first+S[j]+cost,xxx.second+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> t[i];
        s[i+1]=s[i]+t[i];
        d[i+1]=d[i]+1.0/t[i];
        S[i+1]=S[i]+(s[i+1]/t[i]);
    }

    dp[0]=pdi(0,0);
    ld l=0,r=1e15;
    while(r-l>n*eps)
    {
        ld mid=(l+r)/2;
        solve(mid);
        if(dp[n].second>k)
            l=mid;
        else
            r=mid;
    }

    cout.precision(15);
    cout << fixed;
    solve(l);
    db(dp[n].first-(l*k))

    return 0;
}
/**
4 2
100 3 5 7
**/