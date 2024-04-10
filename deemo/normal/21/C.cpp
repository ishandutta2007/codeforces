#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

const ll max_n = 2e5 + 100;

ll n;
ll	vec[max_n];
ll p[max_n], ans;
map<ll, ll>	mp;

int main(){
	scanf("%I64d", &n);
	if (n < 3){
		printf("0\n");
		return 0;
	}
	for (ll i = 0; i < n; i++){
		scanf("%I64d", &vec[i]);
		p[i + 1] = p[i] + vec[i];
	}
	
	mp[p[1]]++;
	for (ll i = 2; i < n; i++){
		ll t = p[n] - p[i];
		if (t * 2 != p[i]){
			mp[p[i]]++;
			continue;
		}
	
		ans += mp[t];
		mp[p[i]]++;
	}
	printf("%I64d\n", ans);
	return 0;
}