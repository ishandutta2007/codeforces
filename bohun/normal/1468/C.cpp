#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int n, cash[500500], cnt;
set<int> A;
set<pair<int, int>> B;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	while (n--) {
		int t;
		cin >> t;

		if (t == 1) {
			cnt++;
			cin >> cash[cnt];
			A.insert(cnt);
			B.insert({cash[cnt], -cnt});
			continue;
		}

		int id;
		if (t == 2) 
			id = *A.begin();
		if (t == 3)
			id = -B.rbegin()->second;

		cout << id << " ";
		A.erase(id);
		B.erase({cash[id], -id});
	}
	return 0;
}