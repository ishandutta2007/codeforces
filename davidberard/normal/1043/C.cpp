#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	char lowestChar = 'z'+1;
	string s;
	cin >> s;
	vector<int> ans(s.size(), 0);
	for(int i=0;i<s.size();++i)
	{
		char c = s[i];
		if(c < lowestChar) {
			ans[i] = 1;
			lowestChar = c;
		} else if(c == lowestChar) {
			ans[i-1] ^= 1;
			ans[i] = 1;
		}
	}
	for(auto& x : ans) cout << x << " ";
	cout << endl;
	return 0;
}