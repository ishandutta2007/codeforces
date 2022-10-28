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
char s[N];
bool del[N], vis[N];
int main()
{
	int k, n, now, res, i;
	cin >> n >> k;
	res = (n - k) / 2;
	now = 0;
	scanf("%s", s + 1);
	for (i = 1; i <= n; i++)
	{
		if (s[i] == '(')
		{
			now++;
			if (res > 0)
			{
				res--;
				vis[now] = 1;
				del[i] = 1;
			}
		}
		else
		{
			if (vis[now])
				del[i] = 1, vis[now] = 0;
			now--;
		}
	}
	for (i = 1; i <= n; i++)
		if (!del[i])
			printf("%c", s[i]);
	cout << endl;
	return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/