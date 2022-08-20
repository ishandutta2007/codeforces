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

int p[1000001], par[1000001];
bitset<1000001> posi;
int n,k; 
vi siz;

bool sub(int k) {
	k = min(k,n-k);
	if (k == 0) return 1;
	map<int,int> s1;
	for (int i: siz) s1[i]++;
	posi[0] = 1;
	int cmax = 0;
	for (auto a: s1) {
		int pw = 1;
		for( ; pw <= a.s; a.s -= pw, pw <<= 1) posi |= posi << (a.f * pw);
		posi |= posi << (a.f * a.s);
	}
	if (posi[k]) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	FOR(i,1,n+1) cin >> p[i];
	FOR(i,1,n+1) if (par[i] == 0) {
		int sz = 0;
		int temp = i;
		while (par[temp] == 0) {
			par[temp] = i;
			temp = p[temp];
			sz++;
		}
		siz.pb(sz);
	}
	vi siz1 = siz; 
	int k1 = k, mx = 0;
	F0R(i,siz1.size()) while (siz1[i]>1 && k1) {
		siz1[i] -= 2, mx += 2, k1--;
	}
	F0R(i,siz1.size()) while (siz1[i]>0 && k1) {
		siz1[i] --, mx ++, k1--;
	}
	// cout << mx << "\n";
	if (sub(k)) cout << k << " " << mx;
	else cout << (k+1) << " " << mx;
}