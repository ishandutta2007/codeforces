#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int n, c1=0;
vi odds, evens;

/*void genprimes() {
	FOR(i,2,2000000) {
		bool x = true;
		F0R(j,p.size()) {
			if (i % p[j] == 0) {
				x = false;
				break;
			}
			if (p[j]*p[j]>i) break;
		}
		if (x) p.pb(i);
	}
}*/

bool is_prime(int k) {
	FOR(i,2,sqrt(k)+1) {
		if (k % i == 0) return 0;
	}
	return 1;
}

int main() {
	cin >> n;
	F0R(i,n) {
		int x;
		cin >> x;
		if (x == 1) {
			c1++;
		} else if (x % 2 == 0) evens.pb(x);
		else odds.pb(x);
	}
	
	if (c1 >= 2) {
		F0R(i,evens.size()) {
			if (is_prime(evens[i]+1)) {
				cout << (c1+1) << endl;
				F0R(i,c1) cout << 1 << " ";
				cout << evens[i];
				return 0;
			}
		}
		cout << c1 << endl;
		F0R(i,c1) cout << 1 << " ";
	} else {
		if (c1 == 1) odds.pb(1);
		sort(evens.begin(), evens.end() );
		evens.erase( unique(evens.begin(), evens.end() ), evens.end() );
		sort(odds.begin(), odds.end() );
		odds.erase( unique(odds.begin(), odds.end() ), odds.end() );
		F0R(i,odds.size()) {
			F0R(j,evens.size()) {
				if (is_prime(odds[i]+evens[j])) {
					cout << 2 << endl << odds[i] << " " << evens[j];
					return 0;
				}
			}
		}
		cout << 1 << endl;
		if (odds.size()) cout << odds[0];
		else cout << evens[0];
	}
	return 0;
}