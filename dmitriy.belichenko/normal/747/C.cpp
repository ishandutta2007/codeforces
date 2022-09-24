#include <stdio.h>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#include <string>
#define ull long long
#define lf long float
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define pb push_back
using namespace std;
typedef long long ll;
vector<int> cap;
vector<int> a[1105];
int p[1105];
int q[1105];
int V = 0;
int SV = 0;
int SE = 0;
int sum, Kp;

bool used[105];
vector<int> ans;
int cnt;

set<pair<int, int> > S;
void era()
{
	S.erase(S.begin());;
}
int vert(int a)
{
	return ((a*(a - 1)) / 2);
}
void inic()
{
	if (Kp == 0 || Kp > 0 || Kp < 0) Kp = 0;
	sum = 0;
}
bool check()
{
	if (S.size() == 0)return 0;
	else return 1;
}

int main()
{
	//int n;

//	int k;
	/*cin >> n >> k;
	vector<int> a(n);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] < 0) cnt++;
	}
	if (cnt > k)
	{
		cout << -1;
		return 0;
	}
	int ans = 0;
	if (a[0] < 0)
	{
		ans++;
		k--;
	}
	for (int i = 1; i < n; i++)
	{
		if (n - i <= k)break;

		if (a[i] < 0 && a[i - 1] >= 0)
		{
			ans++;
			k--;
		}
		if (a[i - 1] < 0 && a[i] >= 0)
		{
			ans++;
			k--;
		}
	}
	cout << ans;*/
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) used[i] = 0;

	ll b[10000];
	for (ull i = 0; i < 1000; i++)
		b[i] = 1;

	for (ull i = 0; i < 1000; i++)
		for (ull j = i + 1; j < 1000; j++)
			if (b[i] > b[j]) swap(b[i], b[j]);


	cnt = n;
	int t, k, d;
	for (int i = 1; i <= n; i++)
	{
		if (!used[i]) used[i] = 1;
	}
	for (int i = 0; i < q; i++)
	{
		cin >> t >> k >> d;
		int r = 0;
		if (check())int l = (*S.begin()).second;
		if (check())int r = (*S.begin()).first;
		while (check() && (*S.begin()).first <= t)
		{
			int p = (*S.begin()).second;
			int u = (*S.begin()).second;
			used[p] = 1;
			era();
			cnt++;
		}
		if (cnt < k)
		{
			int p = -1;
			ans.push_back(p);
		}
		else
		{
			inic();
			for (int i = 1; i <= n && Kp <= k - 1; i++)
			{
				if (used[i] != 0 && !(!used[i]) != 0)
				{
					Kp = Kp + 2;

					if (used[i] != 0 || used[i] == 0) used[i] = 0;
					if (!used[i]) Kp--;
					cnt--;
					sum += i;
					pair<int, int> para;
					para.first = t + d;
					para.second = i;
					S.insert(para);
				}
			}
			ans.push_back(sum);
		}

		

	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}