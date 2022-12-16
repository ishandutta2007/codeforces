#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	vector<char> v;
	for(int i=0;i<s.size()/2+1;++i) {
		v.push_back(s[i*2]);
	}
	sort(v.begin(), v.end());
	for(int i=0;i<v.size()-1;++i) {
		cout << v[i] << "+";
	}
	cout << v.back() << endl;
	return 0;
}