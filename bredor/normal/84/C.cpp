//  228

#include <bits/stdc++.h>

#define ReadFile freopen("input.txt","r",stdin); 
#define WriteFile freopen("output.txt","w",stdout);
#define GIGA_MIND ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define M_PI 3.14159265358979323846
#define mod 1000000007
#define inf 100000000000000000
#define endl "\n"
#define sqr(x) (x)*(x)
#define point complex<ld>
using namespace std;
using ll = long long;
using lli = long long int;
using ld = long double;

const int N = 1e4 + 5;

int n,arr[N];
pair<int, pair<int, int>>pr[N];
int ans = 0;
void check(int v, int tx, int ty, int nm) {
	if (v < 1 || v > n) 
		return;
	int x = pr[v].first;
	int r = pr[v].second.first;
	tx -= x;
	if (sqr(tx) + sqr(ty) <= sqr(r)) 
	{
		if (arr[pr[v].second.second] == -1) 
		{
			arr[pr[v].second.second] = nm;
			++ans;
		}
	}

}
int main()
{
	GIGA_MIND
		cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> pr[i].first >> pr[i].second.first;
		pr[i].second.second = i;
		arr[i] = -1;
	}
	sort(pr + 1, pr + n + 1);
	int m; cin >> m;

	for (int i = 1; i <= m; i++)
	{
		int x, y; cin >> x >> y;

		int l = 1, r = n, mid;
		while (l < r)
		{
			mid = (l + r) / 2;

			if (x > pr[mid].first)
				l = mid + 1;
			else
				r = mid - 1;
		}
		mid = (l + r) / 2;
		check(mid, x, y, i);
		check(mid + 1, x, y, i);
		check(mid - 1, x, y, i);
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}