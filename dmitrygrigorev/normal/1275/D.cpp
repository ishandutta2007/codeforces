#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	string x;
	cin >> x;
	int sum = 0;
	for (int i=0; i < x.size();++i) {
		sum += x[i] - '0';
	}
	if (sum % 3 != 0) {
		cout << "cyan\n";
		return;
	}
	int a = 0, b = 0;
	for (int i=0; i < x.size(); ++i) {
		int N = x[i] - '0';
		if (N==0) a++;
		if (N%2==0) b++;
	}
	if (a > 0 && b > 1) cout << "red\n";
	else cout << "cyan\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i=0; i < t; ++i) solve();

}