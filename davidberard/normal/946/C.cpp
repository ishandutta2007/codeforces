#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	int nxt = 0;
	string scpy = s;
	for(int i=0;i<s.size() && nxt < 26;++i) {
		if(s[i] <= 'a'+nxt) {
			scpy[i] += 'a'+nxt-s[i];
			++nxt;
		}
	}
	if(nxt != 26)
		cout << -1 << endl;
	else
		cout << scpy << endl;

	return 0;
}