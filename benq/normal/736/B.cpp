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

bool isprime(int n) {
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) return 0;
        if (i*i>n) return 1;
    }
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	if (n == 2) cout << 1;
	else if (n % 2 == 0) cout << 2;
	else {
		if (isprime(n)) cout << 1;
		else if (isprime(n-2)) cout << 2;
		else cout << 3;
	}
	return 0;
}