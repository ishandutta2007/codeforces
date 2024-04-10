#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 1e6 + 10;

ll n, vec[MAXN];
ll mini[MAXN], maxi[MAXN];
ll d[MAXN];

int main(){
	scanf("%I64d", &n);
	for (ll i = 0; i < n; i++)	scanf("%I64d", &vec[i]);
	mini[0] = maxi[0] = 1;
	for (ll i = 1; i < n; i++)	
		if (vec[i] > vec[i - 1])
			mini[i] = 1, maxi[i] = maxi[i - 1] + 1;
		else if (vec[i] == vec[i - 1])
			mini[i] = maxi[i] = 1;
		else
			mini[i] = 1 + mini[i - 1], maxi[i] = 1;
	
	d[0] = 0;
	for (ll i = 0; i < n; i++){
		ll a = mini[i], b = maxi[i];
		d[i + 1] = max(vec[i] - vec[i - b + 1] + d[i - b + 1], vec[i - a + 1] - vec[i] + d[i - a + 1]);
		if (b > 1)
			d[i + 1] = max(d[i + 1], d[i - b + 2] + vec[i] - vec[i - b + 2]);
		if (a > 1)
			d[i + 1] = max(d[i + 1], d[i - a + 2] + vec[i - a + 2] - vec[i]);
		d[i + 1] = max(d[i], d[i + 1]);
	}
	printf("%I64d\n", d[n]);
	return	0;
}