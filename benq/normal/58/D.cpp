#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

char d;
int n, tot = 0;
set<string> m[11], ans;

int main() {
	cin >> n;
	F0R(i,n) {
		string x; cin >> x; 
		m[x.length()].insert(x);
		tot += x.length();
	}
	cin >> d;
	tot /= (n/2);
	FOR(i,1,tot/2+1) {
		if (i == tot-i) {
			while (m[i].size()) {
				string z = *m[i].begin();
				m[i].erase(m[i].begin());
				z += (d+*m[i].begin());
				m[i].erase(m[i].begin());
				ans.insert(z);
			}
		} else {
			while (m[i].size()) {
				ans.insert(min(*m[i].begin()+d+*m[tot-i].begin(),*m[tot-i].begin()+d+*m[i].begin()));
				m[i].erase(m[i].begin());
				m[tot-i].erase(m[tot-i].begin());
			}
		}
	}
	for (auto a: ans) cout << a << "\n";
}