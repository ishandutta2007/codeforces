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

const int MAX_NODE = 600 * 1000 + 228;

struct node
{
	int cnt;
	bool term;
	map<char, int> nx;
};

int n;
char st[MAX_NODE];
char cur_word[MAX_NODE];
char *cur_st = st;
node tr[MAX_NODE];
int cnt_node = 0;

int new_node()
{
	tr[cnt_node].term = false;
	tr[cnt_node].cnt = 0;
	tr[cnt_node].nx.clear();

	return cnt_node++;
}

inline void calc(int v)
{
	tr[v].cnt = tr[v].term;

	for (auto it = tr[v].nx.begin(); it != tr[v].nx.end(); ++it) 
	{
		tr[v].cnt += tr[it->second].cnt;
	}
}

void add_word(int v, char *st, int len, int ptr)
{
	if (len == ptr)
	{
		tr[v].term = 1;
	}
	else
	{
		if (tr[v].nx.find(st[ptr]) == tr[v].nx.end()) tr[v].nx[st[ptr]] = new_node();
		add_word(tr[v].nx[st[ptr]], st, len, ptr + 1);
	}

	calc(v);
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

	n = 0;
	while (fgets(cur_st, MAX_NODE, stdin) != NULL)
	{
		n += strlen(cur_st);
		cur_st += strlen(cur_st);
	}
	st[n] = '\0';

	int root = new_node();
	int cur_node = root;
	bool in_word = false;
	int last_sm = -1;
	int cur_len = 0;

	int ans = n;
	for (int i = 0; i < n; ++i)
	{
		if (!in_word && 'a' <= st[i] && st[i] <= 'z')
		{
			in_word = true;
			cur_node = root;
			last_sm = -1;
			cur_len = 1;
			cur_st[0] = st[i];
			
			if (tr[root].nx.find(st[i]) == tr[root].nx.end()) cur_node = -1;
			else cur_node = tr[root].nx[st[i]];

			if (cur_node != -1 && tr[cur_node].cnt == 1) last_sm = i;
		}
		else if (in_word && (st[i] < 'a' || st[i] > 'z'))
		{
			in_word = false;
			add_word(root, cur_st, cur_len, 0);
		}
		else if (in_word)
		{
			assert('a' <= st[i] && st[i] <= 'z');	
			cur_st[cur_len++] = st[i];
				
			if (cur_node != -1)
			{
				if (tr[cur_node].nx.find(st[i]) == tr[cur_node].nx.end()) cur_node = -1;
				else cur_node = tr[cur_node].nx[st[i]];
			}

			if (cur_node != -1)
			{
				if (tr[cur_node].cnt == 1 && last_sm == -1) last_sm = i;
				if (tr[cur_node].term && last_sm != -1) ans -= max(0, i - last_sm - 1);
			}
		}
	}
	
	printf("%d\n", ans);

	return 0;
}