#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

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
		for (; x < n; x = x | (x +1 ))
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
		int res = get(r);
		res -= get(l-1);
		return res;
	}
} F1, F2;

char S[MAX];
char T[MAX];

int C1[MAX];
int C2[MAX];

bool solve(int a, int b, int c, int d)
{
	int s1 = F1.get(a, b);
	int s2 = F2.get(c, d);

	if (s1 % 2 != s2 % 2) return false;
	if (s1 > s2) return false;

	int cnt1 = C1[b];
	int cnt2 = C2[d];

	cnt1 = min(cnt1, b - a + 1);
	cnt2 = min(cnt2, d - c + 1);

	if (s1 == s2)
	{
		if (cnt1 < cnt2) return false;
		if (cnt1 % 3 == cnt2 % 3) return true;
		return false;
	}

	if (s1 == 0)
	{
		if (cnt1 == cnt2) return false;
	}

	if (cnt1 < cnt2) return false;
	return true;
}

int main()
{
//	freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	scanf("%s", S);
	scanf("%s", T);

	int n = strlen(S);
	int m = strlen(T);

	F1.init(n);
	F2.init(m);

	FOR (i, 0, n)
	{
		if (S[i] == 'C' || S[i] == 'B') F1.add(i, 1);
	}

	FOR (i, 0, m)
	{
		if (T[i] == 'C' || T[i] == 'B') F2.add(i, 1);
	}

	if (S[0] == 'A') C1[0] = 1;
	else C1[0] = 0;
	FOR (i, 1, n)
	{
		C1[i] = C1[i-1];
		if (S[i] == 'A') C1[i]++;
		else C1[i] = 0;
	}

	if (T[0] == 'A') C2[0] = 1;
	else C2[0] = 0;
	FOR (i, 1, m)
	{
		C2[i] = C2[i-1];
		if (T[i] == 'A') C2[i]++;
		else C2[i] = 0;
	}

	int q;
	scanf("%d", &q);

	FOR (i, 0, q)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a--;
		b--;
		c--;
		d--;

		if (solve(a, b, c, d)) printf("1");
		else printf("0");
	}
	printf("\n");

}