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
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int w[N], sum[N], cnt[N], n, rel[4097][105];
char str[13];
int get_mask(char *str)
{
	int s = 0, j;
	for (j = 0; j < n; j++)
		if (str[j] == '1')
			s |= 1 << j;
	return s;
}
int main()
{
	int m, q, k, i, s, j;
	cin >> n >> m >> q;
	for (i = 0; i < n; i++)
		scanf("%d", &w[i]);
	k = 1 << n;
	for (s = 0; s < k; s++)
	{
		for (i = 0; i < n; i++)
			if (!(s & (1 << i)))
				sum[s] += w[i];
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%s", str);
		s = get_mask(str);
		cnt[s] ++;
	}
	for (s = 0; s < k; s++)
	{
		for (j = 0; j < k; j++)
			if (sum[j^s] <= 100)
				rel[s][sum[j^s]] += cnt[j];
		for (j = 1; j <= 100; j++)
			rel[s][j] += rel[s][j - 1];
	}
	for (i = 1; i <= q; i++)
	{
		int ans = 0, lim;
		scanf("%s%d", str, &lim);
		s = get_mask(str);
		printf("%d\n", rel[s][lim]);
	}
	return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/