#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const ll M = 998244353;
const int N = 5005;
ll fct[N];
ll times[N] = {};


ll pw(ll a, ll b) {
	if(!b) return 1;
	if(b&1) return a*pw(a,b-1)%M;
	ll t = pw(a,b/2);
	return t*t%M;
}

int main() {
	fct[0] = 1;
	for(int i = 1; i < N; ++i)
		fct[i] = i * fct[i-1] % M;

	ll a[3],b[3] = {0,0,0};
	cin >> a[0] >> a[1] >> a[2];
	for(int i = 0; i < 3; ++i) {
		int j = (i+1)%3;
		for(int k = 0; k <= min(a[i],a[j]); ++k) {
			ll num = fct[a[i]] * fct[a[j]] % M;
			ll den = fct[a[i]-k] * fct[a[j]-k] % M * fct[k] % M;
			b[i] = (b[i] + num * pw(den,M-2)) % M;
		}
	}

	cout << b[0]*b[1]%M*b[2]%M << "\n";
}