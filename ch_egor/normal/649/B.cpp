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

int n, m, k;
int a, b, c;

void have(int p, int &n1, int& m1, int& k1)
{
	p -= 1;
	k1 = p%k;
	p -= k1;
	p /= k;
	m1 = p%m;
	n1 = p / m;
}

int my_abs(int x)
{
	return (x > 0) ? x : -x;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d %d", &n, &m, &k);
	scanf("%d %d", &a, &b);

	int q, w, e;
	int r, t, y;
	have(a, q, w, e);
	have(b, r, t, y);

	//cout << q << " " << w << " " << e << endl;
	//cout << r << " " << t << " " << y << endl;

	int dp;
	int answer = INF;
	if (q == r)
	{
		dp = my_abs(w - t);
		answer = min(10 + dp, dp * 5);
	}
	else
	{
		answer = min(my_abs(q - r), n - my_abs(q - r)) * 15;
		answer += min(10 + w, 5 * w);
		answer += min(10 + t, 5 * t);
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}