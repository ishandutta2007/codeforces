#include <bits/stdc++.h>
#define minus dkjgfdgf
#define plus dkg
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int K = 500007;
int plus[2*K+1];
int minus[2*K+1];

void solve() {

	string s;
	cin >> s;

	for (int i = -s.size(); i <= s.size(); ++i) {
		plus[i+K] = 0;
		minus[i+K] = 0;
	}

	int balance = 0;
	for (auto x : s) {
		int code = 1;
		if (x == '1') code = -1;

		if (code == 1) plus[balance + K]++;
		else minus[balance + K]++;

		balance += code;
	}


	int now = K;
	while (plus[now] || minus[now]) {

		if (!plus[now] || (plus[now] == 1 && minus[now] && balance + K > now)) {
			minus[now]--;
			cout << '1';
			now--;
		}

		else {
			plus[now]--;
			cout << '0';
			now++;
		}
	}

	cout << '\n';

}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}