#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int n;
char st[400228];
int cnt[400];

char get(int x)
{
	if (x < 10) return x + '0';
	if (10 <= x && x < 36) return x - 10 + 'a';
	else return x - 36 + 'A';
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%d", &n);
	scanf("%s", st);

	for (int i = 0; i < n; ++i)
	{
		if ('0' <= st[i] && st[i] <= '9') ++cnt[st[i] - '0'];
		else if ('a' <= st[i] && st[i] <= 'z') ++cnt[st[i] - 'a' + 10];
		else if ('A' <= st[i] && st[i] <= 'Z') ++cnt[st[i] - 'A' + 36];
		else assert(false);
	}

	int tt = 52 + 10;

	for (int i = n; i >= 1; --i)
	{
		if (n % i != 0) continue;
		
		if (i % 2 == 0)
		{
			bool good = true;
			for (int j = 0; j < tt; ++j)
			{
				good &= (cnt[j] % 2 == 0);
			}

			if (good)
			{
				printf("%d\n", n / i);
				int ptr = 0;
				for (int p = 0; p < n / i; ++p)
				{
					string now = "";
					
					while (now.size() < i / 2)
					{
						while (!cnt[ptr]) ++ptr;
						while (cnt[ptr] && now.size() < i / 2)
						{
							cnt[ptr] -= 2;
							now += get(ptr);
						}
					}

					for (int j = 0; j < i / 2; ++j)
					{
						now += now[i / 2 - j - 1];
					}
					printf("%s ", now.c_str());
				}
				return 0;
			}
		}
		else
		{
			vector<int> bd;
			int cnt_bad = 0;
			for (int j = 0; j < tt; ++j)
			{
				if (cnt[j] % 2) bd.push_back(j);
				cnt_bad += cnt[j] % 2;
			}

			if (cnt_bad <= n / i && (n / i - cnt_bad) % 2 == 0)
			{
				printf("%d\n", n / i);
				int ptr = 0;
				for (int p = 0; p < cnt_bad; ++p)
				{
					string now = "";

					--cnt[bd[p]];

					while (now.size() < i / 2)
					{
						while (cnt[ptr] <= 1) ++ptr;
						while (cnt[ptr] >= 2 && now.size() < i / 2)
						{
							cnt[ptr] -= 2;
							now += get(ptr);
						}
					}

					now += get(bd[p]);
					for (int j = 0; j < i / 2; ++j)
					{
						now += now[i / 2 - j - 1];
					}
					printf("%s ", now.c_str());
				}

				for (int p = cnt_bad; p < n / i; p += 2)
				{
					while (!cnt[ptr]) ++ptr;

					cnt[ptr] -= 2;
					int aa = ptr;
					for (int gg = 0; gg < 2; ++gg)
					{
						string now = "";
					
						while (now.size() < i / 2)
						{
							while (cnt[ptr] <= 1) ++ptr;
							while (cnt[ptr] >= 2 && now.size() < i / 2)
							{
								cnt[ptr] -= 2;
								now += get(ptr);
							}
						}
						now += get(aa);
						for (int j = 0; j < i / 2; ++j)
						{
							now += now[i / 2 - j - 1];
						}
						printf("%s ", now.c_str());

						}
				}
				

				return 0;
			}
		}
	}

	assert(false);

	return 0;
}