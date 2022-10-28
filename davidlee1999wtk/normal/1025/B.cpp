#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#include<functional>
#include<sstream>
#include<ctime>
#define INF 1000000000
#define fi first
#define se second
#define N 200005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
vector<int> ch[2];
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int cnt, p[N];
void fenj(int x)
{
	for(int i=2;i*i <=x; i++)
		if (x%i == 0)
		{
			p[++cnt] = i;
			while (x%i == 0)
				x /= i;
		}
	if (x != 1)
		p[++cnt] = x;
}

int main()
{
	int n, i, a, b, c, j, now = 1, pre = 0;
	cin >> n;
	cin >> a >> b;
	fenj(a);
	fenj(b);
	for (i = 1; i <= cnt; i++)
		ch[pre].push_back(p[i]);
	ch[pre].push_back(1);
	n--;
	sort(ch[pre].begin(), ch[pre].end());
	auto it = unique(ch[pre].begin(), ch[pre].end());
	ch[pre].erase(it, ch[pre].end());
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &b);
		for (j = 0; j < ch[pre].size(); j++)
		{
			c = ch[pre][j];
			ch[now].push_back(gcd(c, a));
			ch[now].push_back(gcd(c, b));
		}
		sort(ch[now].begin(), ch[now].end());
		auto it = unique(ch[now].begin(), ch[now].end());
		ch[now].erase(it, ch[now].end());
		ch[pre].clear();
		now ^= 1, pre ^= 1;
	}
	if (ch[pre].size() > 1)
		printf("%d\n", ch[pre][ch[pre].size() - 1]);
	else
		cout << -1 << endl;
	return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/