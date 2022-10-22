#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

ll n, k, a[MAXN];

int main(){
	scanf("%I64d %I64d", &n, &k);
	ll s = 1;
	for (int i = 0; i < n; i++){
		scanf("%I64d", &a[i]);
		s = s/__gcd(s, a[i]) * a[i];
		s = __gcd(s, k);
	}

	if (s == k)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}