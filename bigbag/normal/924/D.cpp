#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

struct Frac
{
	LL a, b;

	Frac(LL a, LL b)
	{
		this->a = a;
		this->b = b;
	}
	Frac(){}

	bool operator <(const Frac& f) const
	{
		LL x = a * f.b;
		LL y = b * f.a;

		return x < y;
	}

	bool operator ==(const Frac& f) const
	{
		LL x = a * f.b;
		LL y = b * f.a;
		return x == y;
	}
};

const int MAX = 100100;

struct Fen
{
	int A[MAX];
	int n;

	void init(int n)
	{
		this->n = n;
	}

	void add(int x, int val)
	{
		for (; x < n; x = x | (x + 1))
		{
			A[x] += val;
		}
	}

	int get(int x)
	{
		int res = 0;
		for (; x >= 0; x = (x & (x + 1)) - 1)
		{
			res += A[x];
		}
		return res;
	}

	int get(int l, int r)
	{
		return get(r) - get(l-1);
	}
} F;

int S[MAX], V[MAX];

pair<Frac, int> A[MAX];

int P[MAX];
int Q[MAX];

LL getInv(int n)
{
	LL res = 0;
	F.init(n);
	int ind = n - 1;
	while(ind >= 0)
	{
		int st = ind;
		Frac f = A[ind].first;
		while(ind >= 0 && A[ind].first == f)
		{
			int v = P[ind];
			int val = F.get(v-1);
			res += val;
			ind--;
		}

		FOR (i, ind + 1, st + 1)
		{
			int v = P[i];
			F.add(v, 1);
		}
	}
	return res;
}

LL getEq(int n)
{
	LL res = 0;
	LL cnt = 1;
	FOR (i, 1, n)
	{
		if (A[i].first == A[i-1].first)
		{
			cnt++;
		}
		else
		{
			res += cnt * (cnt - 1) / 2;
			cnt = 1;
		}
	}

	res += cnt * (cnt - 1) / 2;
	return res;
}

int main()
{
//	freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n, w;
	scanf("%d%d", &n, &w);
	FOR (i, 0, n)
	{
		scanf("%d%d", &S[i], &V[i]);

		A[i] = MP(Frac(abs(S[i]), abs(V[i] - w)), i);
	}

	sort(A, A+n);

	LL res = 0;
	res += getEq(n);

	if (w == 0)
	{
		cout<<res<<endl;
		return 0;
	}

	int sz = 0;

	FOR (i, 0, n)
	{
		P[i] = A[i].second;
		if (i == 0) Q[P[i]] = sz++;
		else
		{
			if (A[i].first == A[i-1].first) Q[P[i]] = Q[P[i-1]];
			else Q[P[i]] = sz++;
		}
	}

	FOR (i, 0, n)
	{
		A[i] = MP(Frac(abs(S[i]), abs(V[i] + w)), i);
	}

	sort(A, A+n);

	res += getEq(n);

	FOR (i, 0, n)
	{
		int cur = Q[A[i].second];
		P[i] = cur;
	}

	res += getInv(n);
	cout<<res<<endl;

}