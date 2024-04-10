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
char s[200005], t[200005];
int main()
{
	int n, m, i, j, len;
	cin >> n >> m;
	len = m - n + 1;
	if (len < 0)
	{
		printf("NO\n");
		return 0;
	}
	scanf("%s%s", s + 1, t + 1);
	for (i = 1; i <= n; i++)
	{
		if (s[i] == '*')
		{
			j = i + len;
			break;
		}
		else if(s[i] != t[i])
		{
			j = -1;
			break;
		}
	}
	if (i == n + 1)
	{
		if (n == m)
		{
			printf("YES\n");
		}
		else
			printf("NO\n");
		return 0;
	}
	if(j==-1)
	{
		printf("NO\n");
		return 0;
	}
	for (i = i + 1; i <= n; i++, j++)
		if (s[i] != t[j])
			break;
	if (i > n)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/