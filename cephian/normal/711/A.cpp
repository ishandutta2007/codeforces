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

string s[1005];

int main() {	
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	bool ok = false;
	for(int i = 0; i < n; ++i) {
		if(s[i].substr(0,2) == "OO") {
			s[i][0] = s[i][1] = '+';
			ok = true;
			break;
		}
		if(s[i].substr(3,2) == "OO") {
			s[i][3] = s[i][4] = '+';
			ok = true;
			break;
		}
	}
	if(ok) {
		cout << "YES\n";
		for(int i = 0; i < n; ++i)
			cout << s[i] << "\n";
	}
	else cout << "NO\n";
}