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

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

string gg = "aeiouy";

int n;
int arrn[105];
string arr[105];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arrn[i];
	scanf("\n");
	for (int i = 0; i < n; ++i)
		getline(cin, arr[i]);

	int ans;
	for (int i = 0; i < n; ++i)
	{
		//cout << arr[i] << endl;
		ans = 0;
		string ww = "";
		arr[i] += " ";
		for (int j = 0; j < arr[i].size(); ++j)
		{
			if (arr[i][j] == ' ' && ww != "")
			{
				int cnt = 0;
				for (int k = 0; k < ww.size(); ++k)
				{
					if (gg.find(ww[k]) != string::npos)
					{
						++cnt;
					}
				}
				ans += cnt;
				ww = "";
			}
			else
			{
				ww += arr[i][j];
			}
		}
		//cout << ans << endl;
		if (ans != arrn[i])
		{
			printf("NO");
			return 0;
		}
	}

	printf("YES");

	fclose(stdin);
	fclose(stdout);

	return 0;
}