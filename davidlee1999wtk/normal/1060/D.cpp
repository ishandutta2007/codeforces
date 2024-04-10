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
int l[N], r[N];
int main()
{
	int n, i;
	LL ans = 0;
	cin >> n;
	for (i = 1; i <= n; i++)
		scanf("%d%d", &l[i], &r[i]);
	sort(l + 1, l + 1 + n);
	sort(r + 1, r + 1 + n);
	for (i = 1; i <= n; i++)
		ans += max(l[i], r[i]);
	cout << ans+n << endl;
	return 0;
}
// davidlee1999WTK 2018/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/