#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5 + 2, LOG = 17, INF = 1e8;
char s[MN], t[MN];
int need[20][20], freq[20];
void solve () {
	int n; memset(need,0,sizeof need); memset(freq,0,sizeof freq);
	scanf ("%d",&n);
	scanf ("%s\n%s",s+1,t+1);
	for (int i = 1; i <= n; i++) {
		if (s[i] > t[i]) return (void) printf ("-1\n");
		need[s[i]-'a'][t[i]-'a']++; ++freq[s[i]-'a'];
	}
	int ans = 0;
	for (int i = 0; i < 20; i++) if (freq[i]){
		int wot = 0;
		for (int j = i+1; j < 20; j++) if (need[i][j]) {
			wot = j; break;
		}
		if (wot) {
			++ans; int add = 0;
			for (int j = wot; j < 20; j++) need[wot][j] += need[i][j], add += need[i][j];
			freq[wot] += add;
		}
	}
	printf ("%d\n",ans);
}
int main () { 
	int _t = 1;
	scanf ("%d",&_t);
	while (_t--) solve();
    return 0;
}
//aab --> bcc
//