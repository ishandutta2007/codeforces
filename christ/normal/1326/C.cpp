#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5+3, LOG = 18, MOD = 998244353;
int main() {
	int n,k;
	scanf ("%d %d",&n,&k);
	ll ret = 0;
	vector<int> a(n); vector<pii> srt; srt.reserve(n); int ind = 0;
	for (auto &au : a) scanf ("%d",&au), srt.emplace_back(au,ind++);
	sort(all(srt));
	vector<int> inds;
	for (int i = 0; i < k; i++) ret += srt.back().first, inds.push_back(srt.back().second), srt.pop_back();
	printf ("%lld ",ret);
	sort(all(inds));
	ll ways = 1;
	for (int i = 1; i < inds.size(); i++) {
		ways = ways * (inds[i]-inds[i-1]) % MOD;
	}
	printf ("%lld\n",ways);
    return 0;
}