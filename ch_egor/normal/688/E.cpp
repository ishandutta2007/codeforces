#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 505;

int n, k;
vector<int> answer;
int arr[MAX_N];
bool dp[MAX_N];
vector<int> lasts[MAX_N];
bool usedd[MAX_N][MAX_N];
bool used[MAX_N];
queue<int> now;
int prev_of[MAX_N];
int at_of[MAX_N];
bool good[MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);
	reverse(arr, arr + n);

	memset(good, 0, sizeof(good));


	for (int i = 0; i <= k; ++i)
	{
		memset(dp, 0, sizeof(dp));
		dp[0] = true;

		for (int j = 0; j < n; ++j)
		{
			for (int m = i; m >= 0; --m)
			{
				if (m - arr[j] >= 0 && dp[m - arr[j]] && !dp[m])
				{
					dp[m] = true;
					prev_of[m] = m - arr[j];
					at_of[m] = j;
				}
			}
		}

		prev_of[0] = -1;
		memset(used, 0, sizeof(used));
		for (int j = i; j != 0; j = prev_of[j])
		{
			used[at_of[j]] = true;
		}

		//cout << i << " " << dp[i] << endl;

		if (dp[i])
		{
			memset(dp, 0, sizeof(dp));
			dp[i] = true;

			for (int j = 0; j < n; ++j)
			{
				for (int m = k; m >= 0; --m)
				{
					if (!used[j] && m - arr[j] >= 0 && dp[m - arr[j]] && !dp[m])
					{
						dp[m] = true;
						prev_of[m] = m - arr[j];
						at_of[m] = j;
					}
				}
			}
		}

		if (dp[k])
		{
			good[i] = true;
			answer.push_back(i);
		}
	}

	for (int _ = 0; _ < 40; ++_)
	{
		random_shuffle(arr, arr + n);

		for (int i = 0; i <= k; ++i)
		{
			if (good[i]) continue;
			memset(dp, 0, sizeof(dp));
			dp[0] = true;

			for (int j = 0; j < n; ++j)
			{
				for (int m = i; m >= 0; --m)
				{
					if (m - arr[j] >= 0 && dp[m - arr[j]] && !dp[m])
					{
						dp[m] = true;
						prev_of[m] = m - arr[j];
						at_of[m] = j;
					}
				}
			}

			prev_of[0] = -1;
			memset(used, 0, sizeof(used));
			for (int j = i; j != 0; j = prev_of[j])
			{
				used[at_of[j]] = true;
			}

			//cout << i << " " << dp[i] << endl;

			if (dp[i])
			{
				memset(dp, 0, sizeof(dp));
				dp[i] = true;

				for (int j = 0; j < n; ++j)
				{
					for (int m = k; m >= 0; --m)
					{
						if (!used[j] && m - arr[j] >= 0 && dp[m - arr[j]] && !dp[m])
						{
							dp[m] = true;
							prev_of[m] = m - arr[j];
							at_of[m] = j;
						}
					}
				}
			}

			if (dp[k])
			{
				good[i] = true;
				answer.push_back(i);
			}
		}
	}

	//memset(usedd, 0, sizeof(usedd));
	//memset(dp, 0, sizeof(dp));
	//dp[0] = true;

	//for (int j = 0; j < n; ++j)
	//{
	//	for (int m = k; m >= 0; --m)
	//	{
	//		if (m - arr[j] >= 0 && dp[m - arr[j]])
	//		{
	//			if (!dp[m])
	//			{
	//				for (int i = 0; i < n; ++i)
	//				{
	//					usedd[m][i] = usedd[m - arr[j]][i];
	//				}
	//				usedd[m][j] = true;
	//			}
	//			dp[m] = true;
	//			if (m - arr[j] == 14)
	//			{
	//				cout << m << endl;
	//			}

	//			if (usedd)
	//			lasts[m].push_back(m - arr[j]);
	//		}
	//	}
	//}

	////for (int i = 0; i < n; ++i)
	////{
	////	for (int j = 0; j <= k; ++j)
	////	{
	////		if (j - arr[i] >= 0 && dp[j] && dp[j - arr[i]] && !usedd[j][i])
	////		{
	////			lasts[i].push_back(j - arr[i]);
	////			if (j - arr[i] == 9)
	////			{
	////				cout << j << " ";
	////				cout << usedd[j][i] << endl;
	////			}
	////		}
	////	}
	////}

	////for (int i = 0; i <= k; ++i)
	////{
	////	for (int j = 0; j < n; ++j)
	////	{
	////		cout << usedd[i][j] << " ";
	////	}
	////	cout << endl;
	////}

	//memset(used, 0, sizeof(used));

	//now.push(k);
	//int v;
	//while (!now.empty())
	//{
	//	v = now.front();
	//	now.pop();
	//	answer.push_back(v);

	//	for (int i = 0; i < n; ++i)
	//	{
	//		if (usedd[v][i])
	//		{
	//			answer.push_back(v - arr[i]);
	//			if (!used[v - arr[i]])
	//			{
	//				now.push(v - arr[i]);
	//			}
	//		}
	//	}

	//	for (int i = 0; i < lasts[v].size(); ++i)
	//	{
	//		if (!used[lasts[v][i]])
	//		{
	//			used[lasts[v][i]] = true;
	//			now.push(lasts[v][i]);
	//		}
	//	}
	//}

	////reverse(arr, arr + n);

	////for (int i = 0; i <= k; ++i)
	////{
	////	lasts[i].clear();
	////}
	////memset(usedd, 0, sizeof(usedd));
	////memset(dp, 0, sizeof(dp));
	////dp[0] = true;

	////for (int j = 0; j < n; ++j)
	////{
	////	for (int m = k; m >= 0; --m)
	////	{
	////		if (m - arr[j] >= 0 && dp[m - arr[j]])
	////		{
	////			if (!dp[m])
	////			{
	////				for (int i = 0; i < n; ++i)
	////				{
	////					usedd[m][i] = usedd[m - arr[j]][i];
	////				}
	////				usedd[m][j] = true;
	////			}
	////			dp[m] = true;
	////			lasts[m].push_back(m - arr[j]);
	////		}
	////	}
	////}

	//////for (int i = 0; i < n; ++i)
	//////{
	//////	for (int j = 0; j <= k; ++j)
	//////	{
	//////		if (j - arr[i] >= 0 && dp[j] && dp[j - arr[i]] && !usedd[j][i])
	//////		{
	//////			lasts[i].push_back(j - arr[i]);
	//////			if (j - arr[i] == 9)
	//////			{
	//////				cout << j << " ";
	//////				cout << usedd[j][i] << endl;
	//////			}
	//////		}
	//////	}
	//////}

	//////for (int i = 0; i <= k; ++i)
	//////{
	//////	for (int j = 0; j < n; ++j)
	//////	{
	//////		cout << usedd[i][j] << " ";
	//////	}
	//////	cout << endl;
	//////}

	////memset(used, 0, sizeof(used));

	////now.push(k);
	////v;
	////while (!now.empty())
	////{
	////	v = now.front();
	////	now.pop();
	////	answer.push_back(v);

	////	for (int i = 0; i < n; ++i)
	////	{
	////		if (usedd[v][i])
	////		{
	////			answer.push_back(v - arr[i]);
	////			if (!used[v - arr[i]])
	////			{
	////				now.push(v - arr[i]);
	////			}
	////		}
	////	}

	////	for (int i = 0; i < lasts[v].size(); ++i)
	////	{
	////		if (!used[lasts[v][i]])
	////		{
	////			used[lasts[v][i]] = true;
	////			now.push(lasts[v][i]);
	////		}
	////	}
	////}

	answer.push_back(0);
	answer.push_back(k);
	sort(answer.begin(), answer.end());
	answer.resize(unique(answer.begin(), answer.end()) - answer.begin());
	printf("%d\n", (int)answer.size());
	for (int i = 0; i < answer.size(); ++i)
	{
		printf("%d ", answer[i]);
	}


	fclose(stdin);
	fclose(stdout);

	return 0;
}