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
int a[N];
int main()
{
	int n, b,c,d,e, sc;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> b >> c >> d >> e;
		a[i] = b + c + d + e;
		a[i] = -a[i];
	}
	sc = a[1];
	sort(a + 1, a + 1 + n);
	printf("%d\n", lower_bound(a + 1, a + 1 + n, sc) - a);
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/