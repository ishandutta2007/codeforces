#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
const int MN = 1e5+2, BASE = 131, MOD = 1e9+7;
int n,a[MN],b[MN],bpos[MN],apos[MN]; bool done[MN];
bool neq() {
	for (int i = 1; i <= n; i++) if (a[i] != b[i]) return 1;
	return 0;
}
int main () {
	scanf ("%d",&n); int cnt = 0;
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]), apos[a[i]] = i;
	for (int i = 1; i <= n; i++) scanf ("%d",&b[i]), bpos[b[i]] = i, done[i] = a[i] == b[i], cnt += done[i];
	int ret = 0; vector<pii> yeet;
	while (cnt < n) {
		set<int> js;
		for (int i = 1; i <= n; i++) if (!done[i]) {
			js.insert(apos[b[i]]);
			auto it = js.upper_bound(i);
			if (it == js.end()) continue;
			int mnj = *it;
			if (bpos[a[mnj]] <= i && bpos[a[i]] >= mnj) {
				js.erase(it); js.erase(i);
				apos[a[i]] = mnj; apos[a[mnj]] = i;
				swap(a[i],a[mnj]);
				if (a[i] == b[i]) done[i] = 1, ++cnt;
				if (a[mnj] == b[mnj]) done[mnj] = 1,++cnt;
				ret += mnj - i; yeet.emplace_back(i,mnj);
			}
		}
	}
	printf ("%d\n",ret);
	printf ("%d\n",(int)yeet.size());
	for (auto &au : yeet) printf ("%d %d\n",au.first,au.second);
    return 0;
}