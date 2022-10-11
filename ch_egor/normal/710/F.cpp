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
#include <unordered_set>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 500 * 1000 + 5;
const int TABLE_LEN = (1 << 25);

struct node
{
	int hash;
	int len;
	int next;
};

int n;
int ptr = 0;
node buff1[MAX_N];
int htable[TABLE_LEN];
char st_buff[MAX_N];
int st_hash[MAX_N];
int pows[MAX_N];

inline int new_node(int hash, int len)
{
	buff1[ptr].hash = hash;
	buff1[ptr].len = len;
	buff1[ptr].next = -1;
	++ptr;

	return ptr - 1;
}

bool is_prime(int x)
{
	for (int i = 2; i*i <= x; ++i)
	{
		if (x % i == 0)
		{
			return false;
		}
	}

	return true;
}

inline int get_h(int x)
{
	return (((1ll * x * 228) >> 2) ^ 12342355) & 33554431;
}

void add_h(int hash, int len)
{
	int now = new_node(hash, len);

	int hash1 = get_h(hash);

	if (htable[hash1] == -1)
	{
		htable[hash1] = now;
	}
	else
	{
		int gg = htable[hash1];
		while (buff1[gg].next != -1)
		{
			gg = buff1[gg].next;
		}

		buff1[gg].next = now;
	}
}

void del_h(int hash, int len)
{
	//int now = new_node(hash, len);

	int hash1 = get_h(hash);

	if (htable[hash1] == -1)
	{
		assert(false);
	}
	else
	{
		int gg = htable[hash1];
		int last = -1;
		while (buff1[gg].hash != hash || buff1[gg].len != len)
		{
			last = gg;
			gg = buff1[gg].next;
		}

		if (last == -1)
		{
			htable[hash1] = buff1[gg].next;
		}
		else
		{
			buff1[last].next = buff1[gg].next;
		}
	}
}

bool check_h(int hash, int len)
{
	int hash1 = get_h(hash);

	if (htable[hash1] == -1)
	{
		return false;
	}
	else
	{
		int gg = htable[hash1];
		while (gg != -1 && (buff1[gg].hash != hash || buff1[gg].len != len))
		{
			gg = buff1[gg].next;
		}

		return gg != -1;
	}
}

unordered_set<int> lens;

int main()
{
	srand(time(0));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	int mod = 4;
	int q = 97;
	while (!is_prime(mod))
	{
		mod = 1000000000 + rand() % 200000000;
	}

	pows[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
	{
		pows[i] = (1ll * pows[i - 1] * q) % mod;
	}

	for (int i = 0; i < TABLE_LEN; ++i)
	{
		htable[i] = -1;
	}

	int type, hash_now, len;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %s", &type, &st_buff);
		len = strlen(st_buff);

		if (type != 3)
		{
			hash_now = 0;
			for (int i = 0; i < len; ++i)
			{
				hash_now = (1ll * hash_now * q + st_buff[i]) % mod;
			}

			//cout << "??" << hash_now << endl;

			if (type == 1)
			{
				add_h(hash_now, len);
				lens.insert(len);
			}
			else
			{
				del_h(hash_now, len);
			}
		}
		else
		{
			int64 answer = 0;

			st_hash[0] = 0;
			st_hash[1] = st_buff[0];

			for (int i = 2; i <= len; ++i)
			{
				st_hash[i] = (1ll * st_hash[i - 1] * q + st_buff[i - 1]) % mod;
			}

			for (int i = 1; i <= len; ++i)
			{
				for (auto it = lens.begin(); it != lens.end(); ++it)
				{
					if (i + *it - 1 <= len)
					{
						hash_now = (st_hash[i + *it - 1] - 1ll * st_hash[i - 1] * pows[*it]) % mod;
						if (hash_now < 0)
							hash_now += mod;

						answer += check_h(hash_now, *it);

						//cout << "DD " << hash_now << " " << *it << endl;

						//if (check_h(hash_now, *it))
						//{
						//	cout << "!!" << i << " " << *it << endl;
						//}
					}
				}
			}

			printf("%lld\n", answer);
			fflush(stdout);
		}
	}

	//fclose(stdin);
	//fclose(stdout);

	return 0;
}