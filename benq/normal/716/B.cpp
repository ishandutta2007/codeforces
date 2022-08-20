#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

string s; 
int cur[26];

bool ok(int start) {
	F0R(i,26) cur[i] = 0;
	FOR(i,start,start+26) {
		if (s[i] == '?') continue;
		cur[s[i]-'A'] ++;
		if (cur[s[i]-'A']>1) return 0;
	}
	return 1;
}

void fill() {
	F0R(i,s.length()) if (s[i] == '?') s[i] = 'A';
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> s;
	// cout << s.length() << "\n";
	if (s.length()<26) {
		cout << -1;
		return 0;
	}
	F0R(i,s.length()-25) {
		// cout << s[i] << " " << ok(i) << "\n";
		if (ok(i)) {
			int nex = 0;
			FOR(j,i,i+26) if (s[j] == '?') {
				while (cur[nex] == 1) nex++;
				cur[nex]++;
				s[j] = 'A'+nex;
			}
			fill();
			cout << s;
			return 0;
		}
	}
	cout << -1;
}