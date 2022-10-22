#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

typedef long long ll;

const ll MAXN = 5e5 + 10;

ll n, k;
multiset<ll>	st;

int main(){
	scanf("%I64d %I64d", &n, &k);
	while (k--)
		st.insert(0);

	for (ll i = 0; i < n; i++){
		ll a, b;	scanf("%I64d %I64d", &a, &b);
		
		ll v = *st.begin();
		st.erase(st.begin());
		v = max(v, a);
		printf("%I64d\n", v + b);
		st.insert(v + b);
	}
	return	0;
}