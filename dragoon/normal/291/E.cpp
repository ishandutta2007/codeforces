#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

typedef __int64 LL;

int parent[200005], pos[200005], len[200005];
char s[400005];
char pattern[300005];
int nextP[300005][26];
int n;
int fail[300005], plen;
LL ans;
int at[100005];

vector<int> V[100005];

void input()
{
	int i, j;

	scanf("%d", &n);

	j = 0;
	for(i = 2; i <= n; i++)
	{
		scanf("%d", &parent[i]);

		V[ parent[i] ].push_back( i );

		pos[i] = j;
		scanf("%s", s + j);
		len[i] = strlen(s + j);
		j += len[i] + 1;
	}

	scanf("%s", pattern + 1);
	plen = strlen(pattern + 1);
}

void process_pattern()
{
	int now, i, j;

	now = fail[0] = fail[1] = 0;
	if(plen > 1) 
	{
		nextP[1][pattern[1]-'a'] = 1;
		nextP[1][pattern[2]-'a'] = 2;
	}
	nextP[0][pattern[1]-'a'] = 1;

	for(i = 2; i <= plen; i++)
	{
		while(now && pattern[now+1] != pattern[i])
			now = fail[now];

		if(pattern[now+1] == pattern[i])
			now = fail[i] = now + 1;
		else
			now = fail[i] = 0;

		for(j = 0; j < 26; j++)
			nextP[i][j] = nextP[now][j];

		if(i < plen) nextP[i][ pattern[i+1] - 'a' ] = i + 1;
	}
}

int process(int pre, int node)
{
	int i, j, now = pre;
	for(i = pos[node], j = 0; j < len[node]; j++, i++)
	{
		now = nextP[now][ s[i]-'a' ];

		if(now == plen) 
		{
			ans++;
			now = fail[now];
		}
	}

	return now;
}

void solve()
{
	queue<int> Q;
	int sz, u, v, i;

	ans = 0;

	at[1] = 0;
	Q.push(1);

	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();

		sz = V[u].size();
		for(i = 0; i < sz; i++)
		{
			v = V[u][i];
			at[v] = process(at[u], v);
			Q.push( v );
		}
	}
}

void output()
{
	printf("%I64d\n", ans);
}

int main()
{
	input();
	process_pattern();
	solve();
	output();

	return 0;
}