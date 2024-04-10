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
const int64 LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

struct point
{
	int64 x;
	int64 y;

	point(int64 _x, int64 _y)
	{
		x = _x;
		y = _y;
	}
};

int64 x;
vector<point> answer1;
vector<point> answer;

int64 cnt_p(point p)
{
	int64 answer = 0;
	while (p.x > 0 && p.y > 0)
	{
		answer += p.x*p.y;
		--p.x;
		--p.y;
	}

	return answer;
}

int64 gcd(int64 a, int64 b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%I64d", &x);

	int64 add;
	int64 to;
	
	for (int64 i = 1; i*i*i <= 9*x; ++i)
	{
		add = (i*(i + 1)) / 2;
		to = ((i*(i + 1)*(2 * i + 1))) / 6;
		if (to > x) break;

		if ((x - to) % add == 0)
		{
			answer.push_back(point(i, (x - to) / add + i));
		}
	}

	for (int i = (int)answer.size() - 1; i >= 0; --i)
	{
		if (answer[i].x != answer[i].y)
		{
			answer.push_back(point(answer[i].y, answer[i].x));
		}
	}

	//for (int64 i = 1; i <= x; ++i)
	//{
	//	for (int64 j = i; j <= x; ++j)
	//	{
	//		cout << i << " " << j << " " << cnt_p(point(i, j)) << endl;
	//		if (i == j)
	//		{
	//			cout << ((i*(i + 1)*(2 * i + 1))) / 6 << endl;;
	//		}
	//		//if (cnt_p(point(i, j)) == x)
	//		//{
	//		//	answer1.push_back(point(i, j));
	//		//}
	//	}
	//}

	printf("%d\n", (int)answer.size());
	for (int i = 0; i < answer.size(); ++i)
	{
		printf("%I64d %I64d\n", answer[i].x, answer[i].y);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}