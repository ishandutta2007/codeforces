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

int n,m, l = 0; 

int eval(vi x) {
	int sum = 0;
	F0R(i,n) {
		int cmin = x[i];
		sum += cmin;
		FOR(j,i+1,n) {
			cmin = min(cmin,x[j]);
			sum += cmin;
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	vector<vi> k;
	vi cur;
	FOR(i,1,n+1) cur.pb(i);
	do {
		int temp = eval(cur);
		if (l<temp) {
			l = temp;
			k.clear();
			k.pb(cur);
		} else if (temp == l) {
			k.pb(cur);
		}
	} while (next_permutation(cur.begin(),cur.end()));
	sort(k.begin(),k.end());
	// cout << l << "\n";
	F0R(i,n) cout << k[m-1][i] << " ";
	/*vi ans(n);
	if (n % 2 == 1) ans[n/2] = n;
	m --;
	for (int i = n/2-1; i >= 0; --i) {
		if (m % 2 == 0) ans[i] = 2*i+1, ans[n-1-i] = 2*i+2;
		else ans[n-1-i] = 2*i+1, ans[i] = 2*i+2;
	}
	F0R(i,n) cout << ans[i] << " ";*/
}