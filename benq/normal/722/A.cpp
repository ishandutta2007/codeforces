#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int a,b,c; cin >> a;
	string x; cin >> x;
	b = stoi(x.substr(0,2)), c = stoi(x.substr(3,2));
	if (a == 24) {
	    if (b>23) x[0] = '0';
	} else {
	    if (b>12) {
	        if (x[1] == '0') x[0] = '1';
	        else x[0] = '0';
	    }
	    if (b == 0) x[1] = '1';
	}
	if (c>59) x[3] = '0';
	cout << x;
}