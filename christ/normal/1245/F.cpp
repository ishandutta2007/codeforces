#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define unq(x) sort(all(x)); (x).erase(unique(all(x)),(x).end())
const int MN = 1e5+2, BASE = 131, MOD = 1e9+7;
ll dp[30][2][2][2];int l, r; //dp[bit][bad L][bad R][lt]
ll solve (int bit, bool badL, bool badR, bool lt) {
	if (bit < 0) return 1;
	ll &ret = dp[bit][badL][badR][lt];
	if (~ret) return ret;
	ret = 0; int cs = 3;
	if (badL && (l>>bit&1)) ret = (lt?solve(bit-1,1,badR && (r>>bit&1^1),1):0), cs = 1;
	else if (badR && (r>>bit&1^1)) ret = solve(bit-1,badL,1,lt) + (lt?solve(bit-1,0,1,1):0), cs = 2;
	else ret = solve(bit-1,badL,0,lt) + solve(bit-1,badL,badR,1) + (lt?solve(bit-1,0,0,1):0);
	//printf ("bit %d badL %d badR %d lt %d: %lld cs %d\n",bit,badL,badR,lt,ret,cs);
	return ret;
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) {
		scanf ("%d %d",&l,&r);
		memset(dp,-1,sizeof dp);
		printf ("%lld\n",solve(29,1,1,0) * 2 - (!l));
	}
    return 0;
}