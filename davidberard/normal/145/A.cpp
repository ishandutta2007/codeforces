#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int s4, s7, t4, t7;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s, t; cin >> s >> t;
	for(int i=0;i<s.size();++i) {
		if(s[i] != t[i]) {
			(s[i] == '4' ? ++s4 : ++s7);
			(t[i] == '4' ? ++t4 : ++t7);
		}
	}
	cout << min(s4, t4) + abs(s4-t4) << endl;
	return 0;
}