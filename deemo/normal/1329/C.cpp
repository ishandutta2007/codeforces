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
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
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

const int MAXN = 22;

int n, m, a[1<<MAXN];
int sec[1<<MAXN], sz;

bool go(int v, int de) {
	if (a[v] == 0) 
		return de > m+1;

	int c = a[v<<1] > a[v<<1^1]? v<<1: v<<1^1;

	int temp = a[c];
	if (go(c, de + 1)) {
		a[v] = temp;
		return true;
	}
	return false;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i <= (1<<n+1); i++)
		a[i] = 0;
	for (int i = 1; i < 1<<n; i++)
		cin >> a[i];

	sz = 0;
	int cur = 1;
	int de = 1;
	for (int i = (1<<m); i < (1<<n); i++) {
		while(!go(cur, de)) {
			cur++;
			if ((1<<de) <= cur) de++;
		}
		sec[sz++] = cur;
	}
	ll ans = 0;
	for (int i = 1; i < 1<<m; i++)
		ans += a[i];
	cout << ans << "\n";
	for (int i = 0; i < sz; i++)
		cout << sec[i] << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}