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

int n,k, ans = 0;
vi a;

int main() {
	cin >> n >> k; a.resize(n);
	F0R(i,n) cin >> a[i];
	sort(a.begin(),a.end());
	F0R(i,a.size()) {
	    while (2*k < a[i]) k *= 2, ans ++;
	    k = max(k,a[i]);
	}
	cout << ans;
}