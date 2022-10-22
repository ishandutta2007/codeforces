#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 20;

ll n, a[MAXN], b[MAXN];
ll ans = 0;
map<pair<ll, ll>, ll>	mp;
map<ll, ll>	mp1, mp2;

int main(){
	scanf("%I64d", &n);
	for (ll i = 0; i < n; i++){
		scanf("%I64d %I64d", &a[i], &b[i]);
		ans -= mp[{a[i], b[i]}]++;
		ans += mp1[a[i]]++;
		ans += mp2[b[i]]++;
	}

	printf("%I64d\n", ans);
	return	0;
}