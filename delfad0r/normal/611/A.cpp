#include <bits/stdc++.h>

using namespace std;
int day[400];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int x;
	string s1, s2;
	cin >> x >> s1 >> s2;
	if(s2 == "week") {
		iota(day, day + 400, 5);
		int ans = 0;
		for(int i = 0; i < 366; ++i) {
			if((day[i] - x) % 7 == 0) ++ ans;
		}
		cout << ans << '\n';
	} else if (s2 == "month") {
		if(x == 30) cout << "11\n";
		else if(x == 31) cout << "7\n";
		else cout << "12\n";
	} else {
		abort();
	}
}