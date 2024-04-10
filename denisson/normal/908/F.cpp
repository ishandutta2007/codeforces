#include <bits/stdc++.h>
                     
using namespace std;

typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n;
int a[300007];
ll ans = 0;
char c[300007];
vector<int> g[3];

int main(){
	srand(123);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> c[i];
    for (int i = 1; i < n; i++) if (a[i] <= a[i - 1]) assert(0);
    int f1 = 0, f2 = 0;
	for (int i = 0; i < n; i++){
		if (c[i] == 'R') f1 = 1;
		if (c[i] == 'B') f2 = 1;
		if (c[i] == 'G') g[0].pub(a[i]);
		else if (c[i] == 'R') g[1].pub(a[i]);
		else g[2].pub(a[i]);
	}
	if (f1 + f2 < 2){
		cout << a[n - 1] - a[0];
		exit(0);
	}
	if (g[0].size() == 0){
		ll now = 0;
		if (g[1].size()) now += g[1].back() - g[1][0];
		if (g[2].size()) now += g[2].back() - g[2][0];
		cout << now;
		exit(0);
	}
	if (g[1][0] < g[0][0]) ans += g[0][0] - g[1][0];
	if (g[1].back() > g[0].back()) ans += g[1].back() - g[0].back();

	if (g[2][0] < g[0][0]) ans += g[0][0] - g[2][0];
	if (g[2].back() > g[0].back()) ans += g[2].back() - g[0].back();

	int uk1 = 0, uk2 = 0;

	for (int i = 0; i + 1 < g[0].size(); i++){
		while(uk1 < g[1].size() && g[1][uk1] < g[0][i]) uk1++;
		while(uk2 < g[2].size() && g[2][uk2] < g[0][i]) uk2++;
		ll ma1 = 0, ma2 = 0;
		ll last = g[0][i];
		while(uk1 < g[1].size() && g[1][uk1] < g[0][i + 1]){
			ma1 = max(ma1, g[1][uk1] - last);
			last = g[1][uk1];
			uk1++;
		}
		ma1 = max(ma1, g[0][i + 1] - last);
		last = g[0][i];
		while(uk2 < g[2].size() && g[2][uk2] < g[0][i + 1]){
			ma2 = max(ma2, g[2][uk2] - last);
			last = g[2][uk2];
			uk2++;
		}
		ma2 = max(ma2, g[0][i + 1] - last);
		ll len = g[0][i + 1] - g[0][i];
		ans += min(len + len - ma1 + len - ma2, 2 * len);
	}
	cout << ans;
}