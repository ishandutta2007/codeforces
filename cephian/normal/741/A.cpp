#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 100;
int p[N],n;

set<int> un;

ll od(int start, int a) {
	if(start == a) return 1;
	return 1+od(start,p[a]);
}

ll gcd(ll a, ll b) {
	if(!b) return a;
	return gcd(b,a%b);
}

ll lcm(ll a, ll b) {
	return (a/gcd(a,b))*b;
}

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
		un.insert(p[i]);
	}
	if(un.size() != n) {
		cout << "-1\n";
		return 0;
	}
	ll ans = 1;
	for(int i = 0; i < n; ++i) {
		ll need = od(i,p[i]);

		if(need%2 == 0)
			need/=2;

		ans = lcm(ans,need);
	}
	cout << ans << "\n";
	return 0;
}