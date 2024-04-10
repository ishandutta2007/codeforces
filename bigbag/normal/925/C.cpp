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
typedef vector<LL> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MAX = 62;

int getBit(LL a)
{
	int res = 0;
	while(a)
	{
		a /= 2;
		res++;
	}
	return res - 1;
}

VI A[MAX];

VI solve(VI& a)
{
	FOR (i, 0, MAX)
	{
		A[i].clear();
	}

	FOR (i, 0, SZ(a))
	{
		int b = getBit(a[i]);
		A[b].PB(a[i]);
	}

	LL cur = 0;
	VI res;
	FOR (it, 0, SZ(a))
	{
		int ind = -1;
		FOR (i, 0, MAX)
		{
			if (cur & (1ll<<i)) continue;
			if (A[i].empty()) continue;
			ind = i;
			break;
		}


		if (ind == -1) return VI();

//		cout<<cur<<' '<<ind<<' '<<A[ind].back()<<endl;

		cur ^= A[ind].back();
		res.PB(A[ind].back());
		A[ind].pop_back();
	}

	return res;
}

bool check(VI a)
{
	int cur = 0;
	FOR (i, 0, SZ(a))
	{
		if ((cur ^ a[i]) <= cur) return false;
		cur ^= a[i];
	}

	return true;
}

void print(VI a)
{
	cout<<SZ(a)<<": ";
	FOR (i, 0, SZ(a))
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
}

VI gen(int n)
{
	while(true)
	{
//		cout<<"=="<<endl;
		VI a;
		FOR (i, 0, n)
		{
			a.PB(rand() % 1023 + 1);
		}

		sort(ALL(a));
		a.erase(unique(ALL(a)), a.end());

//		print(a);

		VI b;
		b.PB(a[0]);
		bool ok = true;
		FOR (i, 1, SZ(a))
		{
			b.PB(a[i] ^ a[i-1]);
			if (b.back() == 0)
			{
				ok = false;
				break;
			}
		}

		if (!ok) continue;

	//	print(b);


		return b;
	}
}

int main()
{
//	freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

//	while(true)
//	{
////		cout<<"--------"<<endl;
//		int n = 100;
//		VI a = gen(n);
////		cout<<"*"<<endl;
////		print(a);
//		VI res = solve(a);
//		print(res);
//		if (res.empty() || !check(res))
//		{
//
//			throw -1;
//		}
//	}

	int n;
	VI a;
	scanf("%d", &n);
	FOR (i, 0, n)
	{
		LL x;
		scanf("%I64d", &x);
		a.PB(x);
	}

	VI res = solve(a);
	if (res.empty()) printf("No\n");
	else
	{
		printf("Yes\n");
		FOR (i, 0, SZ(res))
		{
			printf("%I64d ", res[i]);
		}
	}
	printf("\n");

//	cout<<check(res)<<endl;
}