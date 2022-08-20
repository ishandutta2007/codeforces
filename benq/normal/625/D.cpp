#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
const int MOD = 1000000007;
double PI = 4*atan(1);

string x;
bool p = false;
int ori, final[100000];
vi n, n1, ans;
pii v[19];

void subtract (int x) {
	n[0] -= x;
	n[n.size()-1] -= x;
	int ind = n.size()-1;
	while (ind > 0 && n[ind]<0) {
		n[ind] += 10;
		n[ind-1] -= 1;
		if (n[ind] < 0) {
			n[ind] += 10;
			n[ind-1] -= 1;
		}
		ind--;
	}
}

bool test0() {
	F0R(i,n.size()) if (n[i] != 0) return false;
	return true;
}

void dp(int k) {
	while (n.size() > k) {
		n[1] += 10*n[0];
		n.erase(n.begin());
	}
	if (k == 1) {
		if (n[0] % 2 == 0) {
			ans.pb(n[0]);
			p = true;
		}
		return;
	}
	int last = n[n.size()-1];
	// cout << ori << " " << k << " " << last << endl;
	if (last+10 <= n[0]) last += 10;
	if (last > 18) return;
	if (0 <= n[0]-last && n[0]-last <= 2) {
		subtract(last);
		if (n[0] < 0) return;
		else if (n[0] > 1) return;
		
		ans.pb(last), n.erase(n.end()-1);
		if (k > 2) dp(k-2);
		else if (test0()) p = true;
	}
}

void finish() {
	F0R (i,(ori+1)/2) {
		if (ori % 2 == 1 && i == ori/2) final[i] = ans[i]/2;
		else final[i] = v[ans[i]].f, final[ori-1-i] = v[ans[i]].s;
		// cout << ans[i] << endl;
	}
	F0R(i,ori) cout << final[i];
}

int main() {
	cin >> x;
	F0R(i,x.length()) n.pb(int(x[i]-'0'));
	if (x.length() == 1 && x[0] == '1') {
		cout << 0;
		return 0;
	}
	
	F0R(i,19) {
		if (i % 2 == 0) v[i].f = i/2, v[i].s = i/2;
		else v[i].f = (i+1)/2, v[i].s = (i-1)/2;
	}
	// consider when it ends with 0, extra cases

	if (n[0] != 1) {
		ori = n.size();
		dp(ori);
		if (p) finish(); 
		else cout << 0;
	} else {
		n1 = n;
		if (n[n.size()-1] == 1) {
			ori = n.size();
			dp(ori);
			if (p) {
				finish();
				return 0;
			} 
		}
		n = n1, ans.clear();
		n[1] += 10*n[0], n.erase(n.begin());
		p = false, ori = n.size();
		dp(ori);
		if (p) {
			finish();
			return 0;
		} 
		cout << 0;
	}
	return 0;
}