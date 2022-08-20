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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k,a,b; cin >> n >> k >> a >> b;
	if (a >= b) {
		if ((a+b)/(b+1)>k) cout << "NO";
		else {
			vi x(b+1);
			F0R(i,a) x[i % (b+1)] ++;
			F0R(i,b+1) {
				F0R(j,x[i]) cout << 'G';
				if (i != b) cout << 'B';
			}
		}
	} else {
		if ((b+a)/(a+1)>k) cout << "NO";
		else {
			vi x(a+1);
			F0R(i,b) x[i % (a+1)] ++;
			F0R(i,a+1) {
				F0R(j,x[i]) cout << 'B';
				if (i != a) cout << 'G';
			}
		}
	}
	return 0;
}