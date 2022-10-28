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
int cnt[27];
char s[N];
int main()
{
	int n, i, flag = 0;
	cin >> n;
	scanf("%s", s + 1);
	for (i = 1; i <= n; i++)
		cnt[s[i] - 97]++;
	for (i = 0; i < 26; i++)
		if (cnt[i] != 1 && cnt[i]!=0)
			flag++;
	if (flag == 0 && n >= 2)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/