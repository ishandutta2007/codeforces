#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 1e5 + 10;

int n, m, a[MAXN], sec[MAXN], ans[MAXN];

bool cmp(int u, int v){ return a[u] < a[v]; }

void solve() {
	cin >> n >> m;
	ll sm = 0;
	for (int i = 0; i < m; i++) cin >> a[i], sec[i] = i, sm += a[i];
	if (sm < n) {
		cout << "-1\n";
		exit(0);
	}
	int cur = n;
	for (int i = 0; i < m; i++) {
		int v = sec[i];
		ans[v] = cur - a[v];
		if (ans[v] < 0) {
			cout << "-1\n";
			return;
		}
		cur--;
	}
	int lst = 0;
	for (int i = m-1; ~i; i--) {
		int v = sec[i];
		if (ans[v] <= lst) break;
		ans[v] = lst;
		lst = ans[v] + a[v];
	}
	for (int i = 0; i < m; i++)
		cout << ans[i]+1 << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}