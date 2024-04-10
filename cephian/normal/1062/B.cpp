#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	map<int,int> f;
	int sqf = 1;
	int ops = 0;
	for(int i = 2; i <= n; ++i) {
		int p = 0;
		while(n%i == 0) {
			++p;
			n /= i;
		}
		int q = 0;
		while((1<<q) < p)
			++q;
		if(p != 0) {
			sqf *= i;
			ops = max(ops, q);
			f[i] = p;
		}
	}
	for(auto x : f) {
		if(x.second != (1<<ops)) {
			++ops;
			break;
		}
	}
	cout << sqf << " " << ops << "\n";
}