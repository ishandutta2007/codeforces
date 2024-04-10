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
char a[N], b[N];
int c[2][2];
int main()
{
	int n, i;
	LL ans;
	cin >> n;
	scanf("%s%s", a + 1, b + 1);
	for (i = 1; i <= n; i++)
	{
		c[a[i] - 48][b[i] - 48]++;
	}
	ans = (LL)c[0][0] * (c[1][0] + c[1][1]) + (LL)c[1][0] * c[0][1];
	cout << ans << endl;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/