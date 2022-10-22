#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAX = 500 + 30;
const ll INF = 1e18;

ll n;
ll a[MAX][MAX];
ll q[MAX];
bool del[MAX];
vector<ll>	ans;

ll get(){
	ll ret = 0;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			if (!del[i] && !del[j])	ret += a[i][j];
	return	ret;
}

int main(){
	scanf("%I64d", &n);
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			scanf("%I64d", &a[i][j]);
	for (ll i = 0; i < n; i++){
		scanf("%I64d", &q[i]);
		q[i]--;
		del[i] = 1;
	}	
	reverse(q, q + n);

	for (ll i = 0; i < n; i++){
		ll v = q[i];	del[v] = 0;
		for (ll j = 0; j < n; j++)
			for (ll w = 0; w < n; w++)
				a[j][w] = min(a[j][w], a[j][v] + a[v][w]);
		ans.push_back(get());
	}

	while (ans.size()){
		printf("%I64d ", ans.back());
		ans.pop_back();
	}
	printf("\n");
	return 0;
}