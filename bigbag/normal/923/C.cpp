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

const int MAX = 300300;
const int LEN = 32;

struct node
{
	int to[2];
	int val;

	void init()
	{
		FILL(to, -1);
		val = 0;
	}
};

vector<node> A;

void init()
{
	A.clear();
	A.PB(node());
	A.back().init();
}

void add(int x, int val)
{
	int v = 0;
	RFOR(i, LEN, 0)
	{
		int cur = (x & (1<<i)) > 0;
		if (A[v].to[cur] == -1)
		{
			A[v].to[cur] = SZ(A);
			A.PB(node());
			A.back().init();
		}

		int to = A[v].to[cur];
		v = to;
		A[v].val += val;
	}
}

int get(int x)
{
	int res = 0;
	int v = 0;

	RFOR(i, LEN, 0)
	{
		int cur = (x & (1<<i)) > 0;

		int to = A[v].to[cur];
		if (to == -1 || A[to].val == 0) cur ^= 1;

		to = A[v].to[cur];
		v = to;

		if (cur) res += 1<<i;
	}

	return res;
}

int B[MAX];
int P[MAX];
int R[MAX];

int main()
{
//	freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n;
	scanf("%d", &n);
	FOR (i, 0, n)
	{
		scanf("%d", &B[i]);
	}

	FOR (i, 0, n)
	{
		scanf("%d", &P[i]);
	}

	init();
	FOR (i, 0, n)
	{
		add(P[i], 1);
	}

	FOR (i, 0, n)
	{
		R[i] = get(B[i]);
		add(R[i], -1);

		R[i] ^= B[i];
	}

	FOR (i, 0, n)
	{
		printf("%d ", R[i]);
	}
	printf("\n");
}