#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n;
ll a[2][MAXN];

ll get(bool t){
	sort(a[t], a[t] + n);
	ll ret = 0, sm = 0, tot = 0;
	for (int i = 0; i < n; i++){
		ll dis = (i?a[t][i] - a[t][i - 1]:0);
		tot += dis * dis * i;
		tot += 2ll * sm * dis;
		ret += tot;
		sm += dis * i;
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld %lld", &a[0][i], &a[1][i]);
	printf("%lld\n", get(0) + get(1));
	return 0;
}