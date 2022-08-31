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

string a,b;
int x[100000], y[100000];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> a >> b;
	int ans = 0, l = -1, r = b.length();
	F0R(i,b.length()) {
		if (i) x[i] = x[i-1];
		else x[i] = -1;
		x[i] ++;
		while (x[i] < a.length() && a[x[i]] != b[i]) x[i] ++;
		if (x[i] < a.length()) if (i+1 > ans) {
			ans = i+1;
			l = i;
			r = b.length();
		}
	}
	F0Rd(i,b.length()) {
		if (i < b.length()-1) y[i] = y[i+1];
		else y[i] = a.length();
		y[i] --;
		while (y[i] >= 0 && a[y[i]] != b[i]) y[i] --;
		if (y[i] >= 0) if (b.length()-i > ans) {
			ans = b.length()-i;
			l = -1;
			r = i;
		}
		//cout << i << " " << y[i] << "\n";
	}
	int high = 0;
	F0R(low,b.length()) {
		high = max(high,low+1);
		while (high < b.length() && x[low] >= y[high]) high++;
		if (x[low] < y[high]) if (low+1+(int)b.length()-high > ans) {
			ans = low+1+(int)b.length()-high;
			l = low, r = high;
		}
	}
	string z = "";
	if (l>-1) z += b.substr(0,l+1);
	if (r<b.length()) z += b.substr(r,b.length()-r);
	if (z.length() == 0) z = '-';
	cout << z;
}