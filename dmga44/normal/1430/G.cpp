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
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
//#define eps (1e-9)
//const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)
const double eps = 1e-9, oo = numeric_limits<double>::infinity();

typedef vector<double> vec;
typedef vector<vec> mat;

vec simplexMethodPD(mat &A, vec &b, vec &c)
{
	int n = c.size(), m = b.size();
	mat T(m + 1, vec(n + m + 1));
	vector<int> base(n + m), row(m);

	for(int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
			T[j][i] = A[j][i];
		T[j][n + j] = 1;
		base[row[j] = n + j] = 1;
		T[j][n + m] = b[j];
	}

	for (int i = 0; i < n; ++i)
		T[m][i] = c[i];

	while (1)
	{
		int p = 0, q = 0;
		for (int i = 0; i < n + m; ++i)
			if (T[m][i] <= T[m][p])
				p = i;

		for (int j = 0; j < m; ++j)
			if (T[j][n + m] <= T[q][n + m])
				q = j;

		double t = min(T[m][p], T[q][n + m]);

		if (t >= -eps)
		{
			vec x(n);
			for (int i = 0; i < m; ++i)
				if (row[i] < n) x[row[i]] = T[i][n + m];
			// x is the solution
			return x; // optimal
		}

		if (t < T[q][n + m])
		{
			// tight on c -> primal update
			for (int j = 0; j < m; ++j)
				if (T[j][p] >= eps)
					if (T[j][p] * (T[q][n + m] - t) >=
						T[q][p] * (T[j][n + m] - t))
						q = j;

			if (T[q][p] <= eps)
				return {}; // primal infeasible
		}
		else
		{
			// tight on b -> dual update
			for (int i = 0; i < n + m + 1; ++i)
				T[q][i] = -T[q][i];

			for (int i = 0; i < n + m; ++i)
				if (T[q][i] >= eps)
					if (T[q][i] * (T[m][p] - t) >=
						T[q][p] * (T[m][i] - t))
						p = i;

			if (T[q][p] <= eps)
				return {}; // dual infeasible
		}

		for (int i = 0; i < m + n + 1; ++i)
			if (i != p) T[q][i] /= T[q][p];

		T[q][p] = 1; // pivot(q, p)
		base[p] = 1;
		base[row[q]] = 0;
		row[q] = p;

		for (int j = 0; j < m + 1; ++j)
			if (j != q)
			{
				double alpha = T[j][p];
				for (int i = 0; i < n + m + 1; ++i)
					T[j][i] -= T[q][i] * alpha;
			}
	}

	return {};
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vec c(n);
    vec b;
    mat A;
    vec row(n);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        c[u]+=w;
        c[v]-=w;
        b.push_back(-1);
        A.push_back(row);
        A[i][u]=-1;
        A[i][v]=1;
    }

    vec res=simplexMethodPD(A,b,c);
    for(int i=0;i<n;i++)
        cout << (int)res[i] << ' ';
    cout << '\n';

    return 0;
}