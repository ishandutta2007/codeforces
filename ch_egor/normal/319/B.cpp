#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 2 * 100 * 1000 + 228;

int n;
int arr[MAX_N];
int ans[MAX_N];
vector<int> st;

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	int t;
	//scanf("%d", &t);
	t = 1;
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		memset(ans, 0, sizeof(int) * (n + 1));
		for (int i = n - 1; i >= 0; --i)
		{
			int cnt = 0;
			while (!st.empty() && arr[st.back()] < arr[i]) 
			{
				cnt = max(cnt + 1, ans[st.back()]);
				ans[i] = cnt;
				st.pop_back();
			}
			st.push_back(i);
		}
		int an = 0;
		for (int i = 0; i < n; ++i)
			an = max(an, ans[i]);
		printf("%d\n", an);
	}

	return 0;
}