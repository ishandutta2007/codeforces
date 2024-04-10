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
	ll n, ans = 0;
	char s;
	cin >> n >> s;
	if (n % 4 == 3 || n % 4 == 0) n -= 2;
	ans += (n/4)*16;
	n = n % 4;
	if (n == 2) ans += 7;
	if (s == 'f') ans ++;
	else if (s == 'e') ans += 2;
	else if (s == 'd') ans += 3;
	else if (s == 'a') ans += 4;
	else if (s == 'b') ans += 5;
	else ans += 6;
	cout << ans;
}