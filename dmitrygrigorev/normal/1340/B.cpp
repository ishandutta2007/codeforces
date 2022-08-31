#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<string> kek = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
bool dp[2107][2107];

bool submask(string &s, string &t) {
	for (int i = 0; i < 7; ++i) {
		if (s[i] == '0' && t[i] == '1') return false;
	}
	return true;
}

int cnt(string &s) {
	int x = 0;
	for (int i = 0; i < s.size(); ++i) if (s[i] == '1') x++;
	return x;
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<string> arr;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		arr.push_back(s);
	}

	dp[0][0] = true;

	for (int i = n-1; i >= 0; i--) {

		vector<int> price(10, -1);
		for (int j = 0; j < 10; ++j) {
			if (submask(kek[j], arr[i])) {
				price[j] = cnt(kek[j]) - cnt(arr[i]);
			}
		}

		for (int was = 0; was <= k; ++was) {
			if (!dp[n-i-1][was]) continue;
			for (int j = 0; j < 10; ++j) {
				if (price[j] == -1) continue;
				dp[n-i][was+price[j]] = true;
			}
		}
	}

	if (!dp[n][k]) {
		cout << "-1";
		exit(0);
	}

	int now = k;

	for (int i = 0; i < n; ++i) {
		vector<int> price(10, -1);
		for (int j = 0; j < 10; ++j) {
			if (submask(kek[j], arr[i])) {
				price[j] = cnt(kek[j]) - cnt(arr[i]);
			}
		}
		
		for (int j = 9; j >= 0; j--) {
			if (price[j] == -1) continue;
			if (now - price[j] < 0) continue;
			if (!dp[n-i-1][now-price[j]]) continue;
			cout << j;
			now -= price[j];
			break;
		}

	}


}