#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vector<vector<int>> subs;

int main() {
	string s;
	cin >> s;
	set<int> need_0;
	set<int> ok;
	bool pass = true;
	for(int i = 0; pass && i < s.size(); ++i) {
		if(s[i] == '0') {
			if(need_0.size()) {
				int t = *need_0.begin();
				need_0.erase(t);
				ok.insert(t);
				subs[t].push_back(i);
			} else {
				ok.insert(subs.size());
				subs.push_back({i});
			}
		} else {
			if(!ok.size()) {
				pass = false;
			} else {
				int t = *ok.begin();
				ok.erase(t);
				need_0.insert(t);
				subs[t].push_back(i);
			}
		}
	}

	if(need_0.size())
		pass = false;

	if(pass) {
		cout << subs.size() << "\n";
		for(const auto& x : subs) {
			cout << x.size() << " ";
			for(int y : x) {
				cout << y+1 << " ";
			}
			cout << "\n";
		}
	} else {
		cout << "-1\n";
	}
}