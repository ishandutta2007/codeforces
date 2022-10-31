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

int main() {
	fio;
	int n;
	string s;
	int p;
	cin >> n >> p >> s;
	bool ok = true;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == '.') {
			if(i+p < s.size() && s[i+p] != '.') {
				ok = false;
				s[i] = '1' ^ '0' ^ s[i+p];
			} else if(i >= p) {
				ok = false;
				s[i] = '1' ^ '0' ^ s[i-p];
			} else
				s[i] = '0';
		}
		if(i >= p) {
			ok &= s[i] == s[i-p];
		}
	}
	if(ok) cout << "No\n";
	else cout << s << "\n";
}