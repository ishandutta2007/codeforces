// David Berard
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int link = 0, pearl = 0;
	for(int i=0;i<s.size();++i) {
		if(s[i] == '-') ++ link;
		else ++ pearl;
	}
	if(pearl == 0 || link%pearl == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}