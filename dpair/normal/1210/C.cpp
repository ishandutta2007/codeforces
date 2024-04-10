#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MOD 1000000007
using namespace std;
typedef long long LL;
template <typename T>
inline void read(T &x)
{
    x = 0;
    int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48)
    {
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48)
    {
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
template <typename T>
inline void fprint(T x)
{
    if(x < 0)
    {
        putchar(45);
        x = -x;
    }
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}
int n, k;
int head[1000010], cnt, nxt[2000010], e[2000010];
LL val[1000010];
LL gcd(LL x, LL y)
{
	return y? gcd(y, x % y) : x;
}
inline void add(int u, int v)
{
	nxt[++ cnt] = head[u];
	head[u] = cnt;
	e[cnt] = v;
}
LL ans = 0;
void dfs(int x, int pre, vector <pair<LL, LL> > v)
{
	vector <pair <LL, LL> > p;
	if(!pre) p.push_back(make_pair(val[x], 1ll));
	else
	{
		for (register int i = 0;i < v.size();i ++)
		{
			LL tmp = gcd(v[i].first, val[x]);
			if(p.empty() || p.back().first != tmp)
			{
				p.push_back(make_pair(tmp, v[i].second));
			}
			else
			{
				p.back().second += v[i].second;
			}
		}
		if(p.back().first != val[x]) p.push_back(make_pair(val[x], 1ll));
		else p.back().second ++;
	}
	for (register int i = 0;i < p.size();i ++)
	{
		ans += p[i].first * p[i].second;
		ans %= MOD;
	}
	for (register int i = head[x];i;i = nxt[i])
	{
		if(e[i] == pre) continue;
		dfs(e[i], x, p);
	}
}

int main()
{
	read(n);
	for (register int i = 1;i <= n;i ++) read(val[i]);
	for (register int i = 1;i < n;i ++)
	{
		int u, v;
		read(u);read(v);
		add(u, v);
		add(v, u);
	}
	vector <pair<LL, LL> > v;	
	dfs(1, 0, v);
	fprint(ans);
}