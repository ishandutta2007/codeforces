#include<cstdio>
#include<algorithm>
#include<stack>
#define INF 987654321
using namespace std;
int main() {
	stack<int> st;
	int n;
	scanf("%d", &n);
	int e;
	int curspeed, limit=INF;
	bool pass=1;
	int ans = 0;
	int passcount = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &e);
		if (e == 1)
		{
			scanf("%d", &curspeed);
			if (curspeed > limit)
			{
				int cnt = 0;
				while (!st.empty() && st.top() < curspeed)
				{
					cnt++;
					st.pop();
				}
				ans += cnt;
			}
		}
		else if (e == 2)
		{
			if (!pass)
			{
				ans+=passcount;
				passcount = 0;
			}
		}
		else if (e == 3)
		{
			int x;
			scanf("%d", &x);
			st.push(x);
			limit = x;
			if (curspeed > limit)
			{
				int cnt = 0;
				while (!st.empty() && st.top() < curspeed)
				{
					cnt++;
					st.pop();
				}
				ans+=cnt;
			}
		}
		else if (e == 4)
		{
			pass = 1;
			passcount = 0;
		}
		else if (e == 5)
		{
			limit = INF;
			st.push(INF);
		}
		else
		{
			pass = 0;
			passcount++;
		}

	}
	printf("%d", ans);
}