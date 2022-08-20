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
	ll b,d,s; cin >> b >> d >> s;
	b--, d--, s--;
	b *= 3, d *= 3, s *= 3;
	ll ans1 = max(max(b+1,d+2),s+3);
	ll ans2 = max(max(b+3,d+1),s+2);
	ll ans3 = max(max(b+2,d+3),s+1);
	cout << min(min(ans1,ans2),ans3) - (b+d+s)/3-3;
}