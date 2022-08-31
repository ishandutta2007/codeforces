#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int ans = 0, bal = 0;
	for (int i = 0; i < s.size(); ++i) {
		int N = bal;
		if (s[i] == '(') N++;
		else N--;
		if (N < 0) ans++;
		if (N==0 && bal < 0) ans++;
		bal = N;
	}

	if (bal != 0) {
		cout << -1;
		exit(0);
	}
	cout << ans;

}