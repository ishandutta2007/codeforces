#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
 
const int MOD = 1000000007;

ll n,k;
pair<int,ll> x[1001][6720];
int num[15], mult[15], nums[1000][15], cur = 0;
vector<ll> a, p;

void prime_factorize() {
	ll k1 = k;
	mult[0] = 1;
	FOR(i,2,1000000) {
		while (k1 % i == 0) {
			k1 /= i;
			num[cur]++;
		}
		if (num[cur]) {
			p.pb(i);
			cur++;
			mult[cur] = mult[cur-1]*(num[cur-1]+1);
		}
		if (i*i>k1) break;
	}
	if (k1>1) {
		p.pb(k1);
		num[cur]++;
		cur++;
		mult[cur] = mult[cur-1]*2;
	}
	F0R(i,n) {
		ll temp = a[i];
		F0R(j,cur) 
			while (temp % p[j] == 0) {
				nums[i][j]++;
				temp /= p[j];
			}
	}
}

void dp(int cur1, ll left) {
	if (left == 0) {
		x[cur1][left] = mp(0,0);
		return;
	}
	if (cur1 == n) {
		x[cur1][left] = mp(MOD,0);
		return;
	}
	
	auto a1 = x[cur1+1][left];
	int t[15], newleft = 0;
	F0R(i,cur) t[i] = (left % mult[i+1])/mult[i];
	F0R(i,cur) {
		if (nums[cur1][i]>t[i]) t[i] = 0;
		else t[i] -= nums[cur1][i];
		newleft += mult[i]*t[i];
	}
	auto b1 = x[cur1+1][newleft];
	b1.f ++, b1.s += a[cur1];
	x[cur1][left] = min(a1,b1);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k; 
	// n = 1000, k = 963761198400;
	a.resize(n);
	F0R(i,n) {
		// a[i] = rand() % 1000000000000+1;
		cin >> a[i];
	}
	if (k == 1) {
		cout << 1 << "\n";
		int ind = 0;
		FOR(i,1,n) if (a[i]<a[ind]) ind=i;
		cout << (ind+1);
		return 0;
	}
	prime_factorize();
	for (int i = n; i >= 0; --i) F0R(j,mult[cur]) {
		dp(i,j);
		// cout << i << " " << j << " " << x[i][j].f << " " << x[i][j].s << "\n";
	}
	auto z = x[0][mult[cur]-1];
	if (z.f == MOD) {
		cout << -1;
		return 0;
	}
	cout << z.f << "\n";
	ll c = 0, left = mult[cur]-1;
	
	while (left) { // fix this
		auto a1 = x[c+1][left];
		int t[15], newleft = 0;
		F0R(i,cur) t[i] = (left % mult[i+1])/mult[i];
		F0R(i,cur) {
			if (nums[c][i]>t[i]) t[i] = 0;
			else t[i] -= nums[c][i];
			newleft += mult[i]*t[i];
		}
		auto b1 = x[c+1][newleft];
		b1.f ++, b1.s += a[c];
		if (b1 <= a1) {
			cout << (c+1) << " ";
			left = newleft;
		}
		c++;
	}
}