#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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

vi divi, mood;
int n, ans = -MOD; 

bool test(int i) {
	vi ok(i);
	F0R(j,i) ok[j] = 0;
	F0R(j,n) ok[j % i] += mood[j];
	F0R(j,i) ans = max(ans,ok[j]);
}

int main() {
	cin >> n; mood.resize(n);
	F0R(i,n) cin >> mood[i];
	FOR(i,1,(n+1)/2) if ((n % i) == 0) divi.pb(i);
	for (int i: divi) test(i);
	cout << ans;
}