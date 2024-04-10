#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> amt(5, 0);
	for(auto& x : v) {
		cin >> x;
		amt[x]++;
	}
	int cnt = amt[4];
	amt[4] = 0;
	int threeone = min(amt[3], amt[1]);
	amt[3] -= threeone;
	amt[1] -= threeone;
	cnt += threeone;
	cnt += amt[3];
	amt[3] = 0;
	int twotwo = amt[2]/2;
	amt[2] -= twotwo*2;
	cnt += twotwo;
	if(amt[2] == 1) {
		++cnt;
		amt[2]--;
		amt[1] -= min(amt[1], 2);
	}
	cnt += (amt[1]+3)/4;
	cout << cnt << endl;

	return 0;
}