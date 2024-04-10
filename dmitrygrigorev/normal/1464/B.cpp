#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int check(string s, int a, int b, char wb, char tb) {

	int ans = 1e18;

	int sum = 0;
	int zeros = 0, ones = 0;

	for (auto x : s) {
		if (x == '?') x = wb;
		if (x == '0') {
			sum += ones * b;
			zeros++;
		}
		else {
			sum += zeros * a;
			ones++;
		}
	}


	int czeros = 0, cones = 0;

	for (int take = 0; take <= s.size(); ++take) {
		ans = min(ans, sum);
		if (take == s.size()) return ans;

		if (s[take] == '?') {
			if (wb == '0') {

				zeros--;

				sum -= cones * b;
				sum += czeros * a;
				sum -= ones * a;
				sum += zeros * b; 


				cones++;

			}

			else {
				ones--;
				sum -= czeros * a;
				sum += cones * b;

				sum -= zeros * b;
				sum += ones * a;

				czeros++;

			}
		}

		else {
			if (s[take] == '0') {
				zeros--;
				czeros++;
			}
			else {
				ones--;
				cones++;
			}
		}

	}

}

main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int a, b;
	cin >> a >> b;

	int ans = min(check(s, a, b, '1', '0'), check(s, a, b, '0', '1'));

	cout << ans;

}