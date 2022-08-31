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
	int n, n1, n2; cin >> n >> n1 >> n2;
	if (n1>n2) swap(n1,n2);
	double ans = 0;
	vi a(n);
	F0R(i,n) cin >> a[i];
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	F0R(i,n1) ans += double(a[i])/n1;
	FOR(i,n1,n1+n2) ans += double(a[i])/n2;
	cout << fixed << setprecision(9) << ans;
	return 0;
}