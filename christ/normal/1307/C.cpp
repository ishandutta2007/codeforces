#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 1e5+2, MOD = 1e9+7, LOG = 15;
#define all(x) (x).begin(),(x).end()
ll cnt[26];
char s[MN];
int main() {
	scanf ("%s",s);
	int n = strlen(s);
	auto go = [&] (char a, char b) {
		ll f = 0, ret = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == b) ret += f;
			if (s[i] == a) ++f;
		}
		return ret;
	};
	ll ret = 0;
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = 'a'; b <= 'z'; b++) {
			ret = max(ret,go(a,b));
		}
	}
	for (int i = 0; i < n; i++) {
		ret = max(ret,++cnt[s[i]-'a']);
	}
	printf ("%lld\n",ret);
    return 0;
}