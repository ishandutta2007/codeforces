#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

bool test(char a, char b) {
	if (a>b) swap(a,b);
	if (a == 'A' && b == 'A') return true;
	if (a == 'b' && b == 'd') return true;
	if (a == 'H' && b == 'H') return true;
	if (a == 'I' && b == 'I') return true;
	if (a == 'M' && b == 'M') return true;
	if (a == 'O' && b == 'O') return true;
	if (a == 'o' && b == 'o') return true;
	if (a == 'p' && b == 'q') return true;
	if (a == 'T' && b == 'T') return true;
	if (a == 'U' && b == 'U') return true;
	if (a == 'V' && b == 'V') return true;
	if (a == 'v' && b == 'v') return true;
	if (a == 'W' && b == 'W') return true;
	if (a == 'w' && b == 'w') return true;
	if (a == 'X' && b == 'X') return true;
	if (a == 'x' && b == 'x') return true;
	if (a == 'Y' && b == 'Y') return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string x; cin >> x;
	F0R(i,(x.length()+1)/2) {
		if (!test(x[i],x[x.length()-1-i])) {
			cout << "NIE";
			return 0;
		}
	}
	cout << "TAK";
	return 0;
}