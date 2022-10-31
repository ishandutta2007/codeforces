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

const int N = 100;
ll t[N];

#define lld I64d

int main() {	
	int n,k;
	ll m;
	scanf("%d%d%lld",&n,&k,&m);
	for(int i = 0; i < k; ++i)
		scanf("%lld",t+i);
	sort(t,t+k);
	ll ans = 0;
	for(int all = 0; all <= n; ++all) {
		ll c = m, pts = 0;
		pts += (k+1) * all;
		for(int i = 0; i < k; ++i)
			c -= t[i]*all;
		if(c < 0) continue;
		for(int i = 0; i < k; ++i) {
			for(int j = all; j < n; ++j) {
				if(c-t[i] >= 0) {
					c -= t[i];
					++pts;
				} else goto skp;
			}
		}
		skp:;
		ans = max(ans,pts);
	}
	printf("%lld\n",ans);
}