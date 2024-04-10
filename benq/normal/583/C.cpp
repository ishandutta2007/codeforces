#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int table[500][500], cur;
map<int,int> y;
vi x, ans;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	int n;
	cin >> n;
	F0R(i,n*n) {
		int a;
		cin >> a;
		if (y[a] == 0) x.pb(a);
		y[a] ++;
	}
	sort(x.begin(),x.end());
	cur = x.size()-1;
	while (cur > -1) {
		if (y[x[cur]] > 0) {
			ans.pb(x[cur]);
			y[x[cur]] --;
			F0R(i,ans.size()) {
				y[gcd(ans[i],x[cur])] -= 2;
			}
		} else cur--;
	}
	F0R(i,ans.size()) cout << ans[i] << " ";
	return 0;
}