#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string s;
	string t;
	cin >> s;
	t = s;
	reverse(t.begin(), t.end());
	if(t != s) {
		cout << s.size() << endl;
		return 0;
	}
	bool allsame = true;
	for(int i=0;i<s.size();++i) {
		if(s[i] != s[0]) {
			allsame = false;
			break;
		}
	}
	if(allsame) {
		cout << 0 << endl;
		return 0;
	} else {
		cout << s.size()-1 << endl;
	}
	return 0;
}