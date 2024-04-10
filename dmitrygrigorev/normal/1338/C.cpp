#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int calc(int start, int pos) {

	int cnt = start;
	int ans = 2*start;

	while (cnt > 1) {
		if (pos < cnt/4) {
			cnt /= 4;
			pos %= cnt;
			continue;
		}
		if (pos < (2*cnt)/4) {
			ans += (2*cnt)/4;
			cnt /= 4;
			pos %= cnt;
			continue;
		}
		if (pos < (3*cnt)/4) {
			ans += (3*cnt)/4;
			cnt /= 4;
			pos %= cnt;
			continue;
		}
		ans += cnt/4;
		cnt /= 4;
		pos %= cnt;
		continue;
	}

	return ans;

}

main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		n--;

		int a = n/3, b = n%3;

		int start = 1;
		while (true) {
			if (start <= a) {
				a -= start;
				start *= 4;
			}
			else break;
		}

		if (b == 0) {
			cout << start+a << "\n";
			continue;
		}

		if (b == 1) {
			int res = calc(start, a);
			cout << res << "\n";
		}

		else {
			int res = calc(start, a);
			cout << ((start+a)^res) << "\n";
		}




	}

}