#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
typedef complex<ld> pt;


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	string f, s;
	cin >> f >> s;

	vector<string> choices;
	string ff = f;
	for(int i=0;i<f.length();++i) {

		string ss = s;
		for(int j=0;j<s.length();++j) {
			choices.push_back(ff + ss);
			ss = ss.substr(0, ss.length()-1);
		}
		ff = ff.substr(0, ff.length()-1);
	}

	sort(choices.begin(), choices.end());
	cout << choices[0] << endl;
	
	
	return 0;
}