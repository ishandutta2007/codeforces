#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 5e5 + 10;

int n, ans[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		ll a, b, c, d;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		if (a & 1 && b & 1) ans[i] = 1;
		else if (!(a & 1) && b & 1) ans[i] = 2;
		else if (a & 1 && !(b & 1)) ans[i] = 3;
		else if (!(a & 1) && !(b & 1)) ans[i] = 4;
	}

	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);
	return 0;
}