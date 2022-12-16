#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int dsum(int x) {
	int ans = 0;
	while(x>0) {
		ans += x%10;
		x /= 10;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	vector<int> answers;
	for(int i=max(N-100, 0);i<N+10;++i) {
		if(i+dsum(i) == N) {
			answers.push_back(i);
		}
	}
	cout << answers.size() << "\n";
	for(int vv : answers) {
		cout << vv << "\n";
	}
	return 0;
}