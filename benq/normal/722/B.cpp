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
	int n; cin >> n;
	vi p(n);
	F0R(i,n) cin >> p[i];
	
	string x;
	getline(cin,x);
	F0R(i,n) {
	    getline(cin,x);
	    int c = 0;
	    for (char j: x) if ( j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u' || j == 'y') c++;
	    // cout << c << "\n";
	    if (c != p[i]) {
	        cout << "NO";
	        return 0;
	    }
	}
	cout << "YES";
}