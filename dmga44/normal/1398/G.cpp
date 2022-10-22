#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

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
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
//typedef complex<ld> point;
//typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(2e18)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

struct point
{
	double x, y;
	point(double x = 0, double y = 0) : x(x), y(y) {}
};

point operator+(const point &a, const point &b) { return {a.x + b.x, a.y + b.y}; }
point operator-(const point &a, const point &b) { return {a.x - b.x, a.y - b.y}; }
point operator*(const point &a, const point &b) {
	return {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
}
point operator/(const point &a, double d) { return {a.x / d, a.y / d}; }

void fft(vector<point> &a, int sign = +1)
{
	int n = a.size();

	for (int i = 1, j = 0; i < n - 1; ++i)
	{
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);

		if (i < j) swap(a[i], a[j]);
	}

	double theta = 2 * atan2(0, -1) * sign;

	for (int m, mh = 1; (m = mh << 1) <= n; mh = m)
	{
		point wm(cos(theta / m), sin(theta / m)), w(1, 0);

		for (int i = 0; i < n; i += m, w = point(1, 0))
			for (int j = i, k = j + mh; j < i + mh; ++j, ++k, w = w * wm)
			{
				point x = a[j], y = a[k] * w;
				a[j] = x + y;
				a[k] = x - y;
			}
	}

	if (sign == -1)
		for (point &p : a) p = p / n;
}

vector<point> mul(vector<point> &a,vector<point> &b)
{
    int n=a.size();
    int m=b.size();
    int sum=n+m;
    while(sum!=(sum&-sum))
        sum+=(sum&-sum);
    while(a.size()<sum)
        a.push_back(point(0,0));
    while(b.size()<sum)
        b.push_back(point(0,0));

    fft(a,1);
    fft(b,1);

    vector<point> res(sum);
    for(int i=0;i<sum;i++)
        res[i]=a[i]*b[i];

    fft(res,-1);

    return res;
}

int res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x,y;
    cin >> n >> x >> y;
    vector<point> p1(x+1);
    vector<point> p2(x+1);
    for(int i=0;i<=x;i++)
        p1[i]=p2[i]=point(0,0);
    for(int i=0;i<n+1;i++)
    {
        int a;
        cin >> a;
        p1[a]=point(1,0);
        p2[x-a]=point(1,0);
    }

    for(int i=0;i<MAXN;i++)
        res[i]=-1;
    p1=mul(p1,p2);
    for(int i=x-1;i>=0;i--)
    {
        int v=p1[i].x+0.1;
        if(v)
        {
            v=(x-i+y)*2;
            for(int j=v;j<MAXN;j+=v)
                res[j]=v;
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        int l;
        cin >> l;
        cout << res[l] << ' ';
    }
    cout << '\n';

    return 0;
}
/**
3 10 5
0 3 5 10
6
24 30 14 16 18 10
**/