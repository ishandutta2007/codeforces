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

const int MAX = 300300;

VI g[MAX];
int n;
int D[MAX];
int P[MAX];
bool U[MAX];
bool R[MAX];

void setR()
{
	FOR (i, 0, n)
	{
		R[i] = true;
	}
	R[n-1] = false;
	FOR (i, 0, SZ(g[n-1]))
	{
		int x = g[n-1][i];
		R[x] = false;
	}
}

VI get1()
{
	queue<int> q;
	q.push(0);

	FOR (i, 0, n)
	{
		D[i] = INF;
		P[i] = -1;
	}

	D[0] = 0;

	while(SZ(q))
	{
		int x = q.front();
		q.pop();

		FOR (i, 0, SZ(g[x]))
		{
			int to = g[x][i];
			if (D[to] > D[x] + 1)
			{
				D[to] = D[x] + 1;
				q.push(to);
				P[to] = x;
			}
		}
	}

	if (D[n-1] == INF) return VI();

	int x = n - 1;

	VI res;
	while(x != 0)
	{
		res.PB(x);
		x = P[x];
	}
	res.PB(0);
	reverse(ALL(res));
	return res;
}

VI get3()
{
	setR();
	if (!R[0]) return VI();

	FOR (i, 0, n)
	{
		U[i] = false;
	}

	FOR (i, 0, SZ(g[0]))
	{
		int to = g[0][i];
		U[to] = true;
	}
	U[0] = true;

	FOR (i, 0, SZ(g[0]))
	{
		int x = g[0][i];
		FOR (j, 0, SZ(g[x]))
		{
			int to = g[x][j];
			if (!U[to])
			{
				VI res;
				res.PB(0);
				res.PB(x);
				res.PB(to);
				res.PB(0);
				res.PB(n-1);
				return res;
			}
		}
	}

	return VI();
}

int used[MAX];

VI get4()
{
    memset(used, 0, sizeof(used));
    int cur = 0;
    FOR (i, 0, SZ(g[0]))
    {
        int x = g[0][i];
        if (!R[x]) continue;


        ++cur;
        FOR (j, 0, SZ(g[x])) {
            used[g[x][j]] = cur;
        }
        used[x] = cur;


        FOR (j, 0, SZ(g[x]))
        {
            int y = g[x][j];
            if (y == 0) continue;
            FOR (k, 0, SZ(g[y]))
            {
                int to = g[y][k];
                if (used[to] < cur)
                {
                    VI res;
                    res.PB(0);
                    res.PB(x);
                    res.PB(y);
                    res.PB(to);
                    res.PB(x);
                    res.PB(n-1);
                    return res;
                }
            }
        }
    }
    return VI();
}


void print(VI a)
{
	if (a.empty()) printf("-1\n");
	else
	{
		printf("%d\n", SZ(a) - 1);
		FOR (i, 0, SZ(a))
		{
			printf("%d ", a[i] + 1);
		}
		printf("\n");
	}
}

VI solve()
{
	VI a = get1();
	VI b = get3();
	VI c = get4();

//	print(a);
//	print(b);
//	print(c);

	if (b.empty()) b = c;

	if (b.empty()) return a;
	if (a.empty()) return b;

	if (SZ(a) < SZ(b)) return a;
	return b;
}


int main()
{
//	freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int m;
	scanf("%d%d", &n, &m);
	FOR (i, 0, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;

		g[x].PB(y);
		g[y].PB(x);
	}

	VI res = solve();
	print(res);

}