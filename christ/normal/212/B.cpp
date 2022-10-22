#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e6+3, MOD = 1e9+7;
char s[MN], t[30];
ll ret[26 * MN];
int lst[26];
int main() {
	scanf ("%s",s+1); int ind = 0;
	int n = strlen(s+1);
	set<pii,greater<pii>> st;
    double tot;
	for (int i = 1; i <= n; i++)  {
		int cur = s[i]-'a';
		st.erase({lst[cur],cur});
		st.insert({lst[cur] = i,cur});
		ll msk = 0;
		for (pii j : st) {
			if (i < n && j.second == s[i+1]-'a') break;
			ret[ind++] = (msk |= 1LL << j.second);
		}
	}
    sort(ret,ret+ind);
	int q;
	scanf ("%d",&q);
	while (q--) {
		scanf ("%s",t);
		int len = strlen(t); ll msk = 0;
		for (int i = 0; i < len; i++) msk |= 1LL << (t[i]-'a');
		printf ("%d\n",upper_bound(ret,ret+ind,msk)-lower_bound(ret,ret+ind,msk));
	}
    return 0;
}