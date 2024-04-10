#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e6+3, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    int n,m;
    scanf ("%d %d",&n,&m);
    vector<int> a(n+1), eds(n+1), aidx(MN), b;
    for (int i = 1; i <= n; i++) scanf ("%d",&a[i]), aidx[a[i]] = i;
    for (int i = 1; i <= m; i++) {
		int c;
		scanf ("%d",&c);
		if (aidx[c]) b.push_back(aidx[c]);
	}
	int m0 = b.size(), ret = 0; vector<int> bidx(MN);
	for (int i = 0; i < m0; i++) b.push_back(b[i]), bidx[b[i]] = i;
	auto lst = [&] (int aa) {return aa == 1 ? n : aa-1;};
	auto ree = [&] (int aa) {return aa <= 0 ? aa + n : aa;};
	for (int i = 0; i < b.size(); i++) {
		eds[b[i]] = eds[lst(b[i])] + 1;
		while (eds[b[i]] > 1 && bidx[ree(b[i]-eds[b[i]]+1)]+m0-1 < i) --eds[b[i]];
		ret = max(ret,eds[b[i]]);
	}
    printf ("%d\n",ret);
    return 0;
}