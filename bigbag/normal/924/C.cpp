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

const int MAX = 100100;

int A[MAX];
int M[MAX];

int main()
{
//	freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n;
	scanf("%d", &n);
	FOR (i, 0, n)
	{
		scanf("%d", &A[i]);
	}

	FOR (i, 0, n)
	{
		M[i] = A[i];
		if (i) M[i] = max(M[i], M[i-1]);
	}

	RFOR(i, n, 1)
	{
		M[i-1] = max(M[i-1], M[i] - 1);
	}

	LL res = 0;
	FOR (i, 0, n)
	{
		res += M[i] - A[i];
	}

	cout<<res<<endl;
}