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
long double PI = 4*atan(1);

int n, n1, key[100001];
ll r,h, ans=0, seg[200001];
vector<pair<ll,int>> volumes;
vector<ll> v2;

ll query(int l, int r) {  // sum on interval [l, r)
  ll res = 0;
  for (l += (n1-1), r += (n1-1); l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res,seg[l++]);
    if (r&1) res = max(res,seg[--r]);
  }
  return res;
}

void modify(int ind, ll val) {
	ind += (n1-1);
	if (seg[ind]<val) {
		seg[ind] = val;
		ind /= 2;
		while (ind > 0) {
			seg[ind] = max(seg[2*ind],seg[2*ind+1]);
			ind /= 2;
		}
	}
}

int main() {
	cin >> n;
	F0R(i,n) {
		scanf("%d%d",&r,&h);
		volumes.pb(mp(r*r*h,i+1));
		v2.pb(r*r*h);
	}
	sort(volumes.begin(), volumes.end());
	ll c;
	n1 = 1;
	for(int i = 0; i < volumes.size();) {
		c = volumes[i].f;
		while (i<volumes.size() && volumes[i].f == c) {
			key[volumes[i].s] = n1;
			i++;
		}
		n1++;
	}
	n1--;
	FOR(i,1,n+1) modify(key[i],query(1,key[i])+v2[i-1]);
	cout << fixed << setprecision(10) << (long double)(seg[1]*PI);
	return 0;
}