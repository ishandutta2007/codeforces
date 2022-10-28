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
#include<assert.h>
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
vector<char> st, ed;
char ret[5];
int main()
{
	int i, n, now_i = 1, now_j = 1, mid_i, mid_j;
	cin >> n;
	for (i = 1; i < n; i++)
	{
		printf("? %d %d %d %d\n", now_i, now_j + 1, n, n);
		fflush(stdout);
		scanf("%s", ret);
		if (ret[0] == 'Y')
		{
			now_j++;
			st.push_back('R');
		}
		else
		{
			now_i++;
			st.push_back('D');
		}
	}
	mid_i = now_i, mid_j = now_j;
	now_i = n, now_j = n;
	for (i = 1; i < n; i++)
	{
		printf("? %d %d %d %d\n", 1, 1, now_i -1, now_j);
		fflush(stdout);
		scanf("%s", ret);
		if (ret[0] == 'Y')
		{
			now_i--;
			ed.push_back('D');
		}
		else
		{
			now_j--;
			ed.push_back('R');
		}
	}
	assert(now_i == mid_i && now_j == mid_j);
	printf("! ");
	reverse(ed.begin(), ed.end());
	for (i = 0; i < st.size(); i++)
		printf("%c", st[i]);
	for (i = 0; i < ed.size(); i++)
		printf("%c", ed[i]);
	fflush(stdout);
	return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/