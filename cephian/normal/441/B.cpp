#include <algorithm>
#include <iostream>
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

int day[3005]={0},n,v;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n >> v;
	for(int i = 0; i < n; ++i) {
		int a,b;
		cin >> a >> b;
		day[a] += b;
	}
	int ans = 0;
	for(int d = 1; d < 3005; ++d) {
		int g = min(v,day[d-1]);
		int k = min(v-g,day[d]);
		ans += g+k;
		day[d] -= k;
	}
	cout << ans << "\n";
	return 0;
}