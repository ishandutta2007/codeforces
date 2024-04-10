#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = 60;

struct State
{
	int value;
	long long mask;

	State(int _value, long long _mask) : value(_value), mask(_mask) {}

	bool operator < (const State &A) const
	{
		if (value != A.value) return value < A.value;
		return mask < A.mask;
	}
};

map <long long, int> gr[N + 1];

int solve(State s)
{
	if (s.value == 0) return 0;
	if (gr[s.value].count(s.mask) ) return gr[s.value][s.mask];

	long long turns = 0LL;

	for (int i = 1; i <= s.value; i++)
	{
		if (s.mask & (1LL << i) ) continue;
		turns |= (1 << solve(State(s.value - i, s.mask | (1LL << i) ) ) );
	}

	int ans = 0;
	while (turns & (1LL << ans) ) ans++;

//	eprintf("value = %d, mask = %lld, ans = %d\n", s.value, s.mask, ans);
	return gr[s.value][s.mask] = ans;
}

void init()
{
	for (int i = 1; i <= N; i++)
		solve(State(i, 0LL) );
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	init();

	int n;
	scanf("%d", &n);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		ans ^= gr[x][0LL];
	}
//	eprintf("%d\n", ans);

	printf(ans ? "NO\n" : "YES\n");

	return 0;
}