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
	int n,b,d,cur=0,ans=0; cin >> n >> b >> d;
	F0R(i,n) {
		int a; cin >> a;
		if (a>b) continue;
		cur += a;
		if (cur>d) cur = 0, ans++;
	}
	cout << ans;
	return 0;
}