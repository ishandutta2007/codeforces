#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

void myReplace(std::string& str, const std::string& oldStr, const std::string& newStr) {
  std::string::size_type pos = 0u;
  if((pos = str.find(oldStr, pos)) != std::string::npos){
     str.replace(pos, oldStr.length(), newStr);
  }
}

bool all_same(const vector<string>& s) {
	for(int i = 1; i < (int)s.size(); ++i)
		if(s[i] != s[i-1]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<string> a(n), b(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];

	vector<string> before, after;
	vector<string> suff, pref;
	for(int i = 0; i < n; ++i) {
		int l = -1, r = -1;
		for(int j = 0; j < (int)a[i].size(); ++j) {
			if(a[i][j] != b[i][j]) {
				if(l == -1) l = j;
				r = j;
			}
		}
		if(l == -1) continue;
		suff.push_back(a[i].substr(r+1));
		string tmp = a[i].substr(0, l);
		reverse(tmp.begin(),tmp.end());
		pref.push_back(tmp);

		before.push_back(a[i].substr(l, r-l+1));
		after.push_back(b[i].substr(l, r-l+1));
	}

	if(!all_same(before) || !all_same(after)) {
		cout << "NO\n";
	} else {
		// verify it works
		string A = before[0];
		string B = after[0];

		//longest suff
		string sf = "", pf = "";
		for(int j = 0; ; ++j) {
			bool ok = true;
			for(int i = 0; ok && i < (int)before.size(); ++i) {
				if(j >= (int) suff[i].size()) {
					ok = false;
				}
				if(i > 0 && suff[i][j] != suff[i-1][j])
					ok = false;
			}
			if(!ok) break;
			sf += suff[0][j];
		}
		//longest pref
		for(int j = 0; ; ++j) {
			bool ok = true;
			for(int i = 0; ok && i < (int)before.size(); ++i) {
				if(j >= (int) pref[i].size()) {
					ok = false;
				}
				if(i > 0 && pref[i][j] != pref[i-1][j])
					ok = false;
			}
			if(!ok) break;
			pf += pref[0][j];
		}
		reverse(pf.begin(), pf.end());
		A = pf + A + sf;
		B = pf + B + sf;

		for(int i = 0; i < n; ++i) {
			myReplace(a[i], A, B);

			if(a[i] != b[i]) {
				cout << "NO\n";
				return 0;
			}
		}

		cout << "YES\n";
		cout << A << "\n" << B << endl;
	}




}