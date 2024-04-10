#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
#define SIZE 1000000
typedef long long ll;
ll m[1000][1000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	int ren[SIZE];
	void init()
	{
		for (int i = 0; i<SIZE; i++)
		{
			par[i] = i;
			ran[i] = 0;
			ren[i] = 1;
		}
	}
	int find(int a)
	{
		if (a == par[a])return a;
		else return par[a] = find(par[a]);
	}
	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)return;
		if (ran[a]>ran[b])
		{
			par[b] = a;
			ren[a] += ren[b];
		}
		else
		{
			par[a] = b;
			ren[b] += ren[a];
		}
		if (ran[a] == ran[b])ran[b]++;
	}
};
unionfind uf;
typedef pair<ll, ll>pii;
typedef pair<ll, pii>pi3;
ll ans[1000][1000];
ll cnt;
int mx, my;
void dfs(int x, int y, ll mi)
{
	if (cnt == 0)return;
	if (ans[x][y] != 0)return;
	ans[x][y] = mi;
	cnt--;
	for (int i = 0; i < 4; i++)
	{
		if (0 <= x + dx[i] && x + dx[i] < mx && 0 <= y + dy[i] && y + dy[i] < my)
		{
			if (m[x + dx[i]][y + dy[i]] >= mi)dfs(x + dx[i], y + dy[i], mi);
		}
	}
}
int main()
{
	ll gen;
	scanf("%d%d%I64d", &mx, &my, &gen);
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			scanf("%I64d", &m[i][j]);
			if (m[i][j] == gen)
			{
				printf("YES\n");
				for (int k = 0; k < mx; k++)
				{
					for (int l = 0; l < my; l++)
					{
						if (l != 0)printf(" ");
						if (i != k || j != l)printf("0");
						else printf("%d", m[i][j]);
					}
					printf("\n");
				}
				return 0;
			}
		}
	}
	vector<pi3>vec;
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my - 1; j++)
		{
			vec.push_back(make_pair(min(m[i][j], m[i][j + 1]), make_pair(i*my + j, i*my + j + 1)));
		}
	}
	for (int i = 0; i < mx - 1; i++)
	{
		for (int j = 0; j < my; j++)
		{
			vec.push_back(make_pair(min(m[i][j], m[i + 1][j]), make_pair(i*my + j, (i + 1)*my + j)));
		}
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	uf.init();
	ll sx = -1, sy = -1;
	for (int i = 0; i < vec.size(); i++)
	{
		uf.unite(vec[i].second.first, vec[i].second.second);
		if ((ll)uf.ren[uf.find(vec[i].second.first)] * vec[i].first >= gen && (gen%vec[i].first) == 0)
		{
			sx = vec[i].second.first / my, sy = vec[i].second.first%my;
			if (m[sx][sy] != vec[i].first)sx = vec[i].second.second / my, sy = vec[i].second.second%my;
			break;
		}
	}
	if (sx == -1)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	cnt = gen / m[sx][sy];
	dfs(sx, sy, m[sx][sy]);
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			if (j != 0)printf(" ");
			printf("%I64d", ans[i][j]);
		}
		printf("\n");
	}
}