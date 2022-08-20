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

ll MOD = 1000000007;
int n,m,y,sum, z[1000000];
vi x;
string p;

ll pow(int k) {
	ll p = 26, ans = 1;
	F0R(i,20) {
		if (k & 1) ans = ans*p % MOD;
		p = p*p % MOD;
		k /= 2;
	}
	return ans;
}

void genz() {
	int L = 0, R = 0;
	FOR(i,1,p.length()) {
		if (i > R) {
			L = R = i;
	   		while (R < p.length() && p[R-L] == p[R]) R++;
	   		z[i] = R-L; R--;
	 	} else {
			int k = i-L;
			if (z[k] < R-i+1) z[i] = z[k];
			else {
				L = i;
	     		while (R < p.length() && p[R-L] == p[R]) R++;
	     		z[i] = R-L; R--;
	   		}
		}
	}
}

int main() {
	cin >> n >> m >> p;
	F0R(i,m) {
		cin >> y;
		x.pb(y);
	}
	genz();
	if (x.size() == 0) {
		cout << pow(n);
		return 0;
	}
	F0R(i,x.size()-1) {
		if (x[i+1]-x[i] >= p.length()) sum += p.length();
		else {
			int k = x[i+1]-x[i];
			if (z[k]+k == p.length()) sum += (x[i+1]-x[i]);
			else {
				cout << 0;
				return 0;
			}
		}
	}
	sum += p.length();
	cout << pow(n-sum);
	return 0;
}