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
int main()
{
	int n, m, k, i;
	cin >> n;
	m = int(sqrt(n - 0.5)) + 1;
	//debug(m);
	for (i = 1; i <= n/m * m; i++)
	{
		k = (i - 1) / m;
		//debug(k);
		printf("%d ", n - (k + 1) * m + (i-1) % m + 1);
	}
	int st = i;
	for(;i<=n;i++)
		printf("%d ", i - st + 1);
	return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/