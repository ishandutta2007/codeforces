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

int n,m;

set<string> res[2];
set<string> ok[2];

vector<string> A[2];
set<string> remaining[2];

inline string tostr(int a) {
	string s = "";
	while(a) {
		s += char(a%10 + '0');
		a/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}

vector<string> C,D;

int main() {
	srand(time(0));
	fio;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string s;
		int type;
		cin >> s >> type;
		A[type].pb(s);
	}
	for(int i = 1; i <= (int)A[1].size(); ++i) {
		ok[1].insert(tostr(i));
	}
	for(int i = (int)A[1].size()+1; i <= n; ++i) {
		ok[0].insert(tostr(i));
	}
	for(int t = 0; t < 2; ++t) {
		for(int i = 0; i < A[t].size(); ++i) {
			if(ok[t].count(A[t][i])) {
				ok[t].erase(A[t][i]);
				A[t][i] = "";
			} else if(ok[!t].count(A[t][i])) {
				ok[!t].erase(A[t][i]);
				res[!t].insert(A[t][i]);
			}
		}
	}
	for(int t = 0; t < 2; ++t) {
		for(int i = 0; i < A[t].size(); ++i) {
			if(A[t][i] == "") continue;
			remaining[t].insert(A[t][i]);
		}
	}

	while(res[0].size() != 0 || res[1].size() != 0 || ok[0].size() != 0 || ok[1].size() != 0) {
		for(int t = 0; t < 2; ++t) {
			if(res[t].size() && ok[!t].size()) {
				string s = *res[t].begin();
				string r = *ok[!t].begin();
				ok[!t].erase(ok[!t].begin());
				res[t].erase(res[t].begin());
				remaining[!t].erase(s);
				// cout << "move " << s << " " << r << "\n";
				C.pb(s);
				D.pb(r);
				ok[t].insert(s);
				goto skp;
			}
		}
		for(int t = 0; t < 2; ++t) {
			if(ok[t].size()) {
				string s = *remaining[t].begin();
				string r = *ok[t].begin();
				// cout << "move " << s << " " << r << "\n";
				C.pb(s);
				D.pb(r);
				remaining[t].erase(remaining[t].begin());
				ok[t].erase(ok[t].begin());
				goto skp;
			}
		}
		//dead lock
		for(int t = 0; t < 2; ++t) {
			if(res[t].size()) {
				string rnd = "......";
				do {
					for(int i = 0; i < 6; ++i) {
						rnd[i] = rand()%26 + 'a';
					}
				} while(remaining[0].count(rnd) || remaining[1].count(rnd));
				string s = *res[t].begin();
				// cout << "move " << s << " " << rnd << "\n";
				res[t].erase(res[t].begin());
				ok[t].insert(s);
				remaining[!t].erase(s);
				remaining[!t].insert(rnd);
				C.pb(s);
				D.pb(rnd);
				goto skp;
			}
		}
		skp:;
	}
	cout << C.size() << "\n";
	for(int i = 0; i < C.size(); ++i) {
		cout << "move " << C[i] << " " << D[i] << endl;
	}
}