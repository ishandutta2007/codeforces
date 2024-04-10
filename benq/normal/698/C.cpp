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
#define endl "\n"

const int MOD = 1000000007;
double PI = 4*atan(1);

double p[20], ans[20], c[20], fac[20];
int n,k;

double eval(int x) {
	return (ans[x]*p[x]+1-pow(1-p[x],k));
}

double binom(int a, int b) {
	return fac[a]/fac[a-b]/fac[b];
}

void dp(double prob, int used, int num, int cur) {
	if (cur == n) {
		if (num >= k || num == 0) return;
		F0R(i,n) if ((used & (1<<i)) == 0 && p[i] != 0.0) {
			ans[i] += c[k-1-num]*pow(prob,k)/(1.0-prob);
		}
	} else {
		dp(prob+p[cur],used+(1<<cur),num+1,cur+1);
		dp(prob,used,num,cur+1);
	}
}

void pfac() {
	fac[0] = 1;
	FOR(i,1,20) fac[i] = i*fac[i-1];
	c[0] = 1;
	FOR(i,1,k-1) {
		F0R(j,i) {
			c[i] += c[j]*binom(n-k+i,i-j);
		}
		c[i] = 1-c[i];
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	cin >> n >> k;
	F0R(i,n) cin >> p[i];

	pfac();
	if (k == n) {
        F0R(i,n) {
			if (p[i] != 0.0) cout << 1;
			else cout << 0;
			cout << " ";
		}
		return 0;
	}
	dp(0.0,0,0,0);
	double sum = 0;
	cout << fixed << setprecision(10);
	F0R(i,n) {
		if (p[i] == 0.0) cout << 0;
		else {
			double k = eval(i);
			cout << k;
			sum += k;
		}
		cout << " ";
	}
	// cout << endl << sum;
}