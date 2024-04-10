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

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;

int n;
vector<int> answer;
vector<int> add;
vector<int> last1;

bool is_prime(int x)
{
	if (x == 2)
	{
		return true;
	}

	for (int i = 2; i*i <= x; ++i)
	{
		if (x%i == 0)
		{
			return false;
		}
	}

	return true;
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	if (n == 1)
	{
		printf("0");
	}
	else
	{
		for (int i = 2; i <= n; ++i)
		{
			if (is_prime(i))
			{
				answer.push_back(i);
			}
		}

		add.resize(answer.size());

		for (int i = 0; i < add.size(); ++i)
		{
			add[i] = 1;
		}

		int k;
		int cnt;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 0; j < answer.size(); ++j)
			{
				k = i;
				cnt = 0;
				while (k%answer[j] == 0)
				{
					++cnt;
					k /= answer[j];
				}

				add[j] = max(add[j], cnt);
			}
		}

		int ad;
		for (int i = 0; i < answer.size(); ++i)
		{
			ad = answer[i];
			for (int j = 0; j < add[i]; ++j)
			{
				last1.push_back(ad);
				ad *= answer[i];
			}
		}

		printf("%d\n", (int)last1.size());
		for (int i = 0; i < last1.size(); ++i)
		{
			printf("%d ", last1[i]);
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}