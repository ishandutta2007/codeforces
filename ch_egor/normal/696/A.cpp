#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int q;
map<int64, int64> up;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &q);

	set<int64> t1, t2;
	int type;
	int64 a, b, c;
	while (q--)
	{
		scanf("%d %lld %lld", &type, &a, &b);

		t1.clear();
		t2.clear();

		int64 gg = a;
		while (gg != 0)
		{
			t1.insert(gg);
			gg /= 2;
		}
		gg = b;
		while (t1.find(gg) == t1.end())
		{
			gg /= 2;
		}

		if (type == 1)
		{
			scanf("%lld", &c);

			while (a != gg)
			{
				up[a] += c;
				a /= 2;
			}
			while (b != gg)
			{
				up[b] += c;
				b /= 2;
			}
		}
		else
		{
			int64 answer = 0;
			while (a != gg)
			{
				answer += up[a];
				a /= 2;
			}
			while (b != gg)
			{
				answer += up[b];
				b /= 2;
			}

			printf("%lld\n", answer);
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}