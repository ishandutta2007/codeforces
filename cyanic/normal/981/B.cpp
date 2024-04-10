#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

map<int,int> val;
int n, a, b;
LL res;

int main() {
	scanf("%d", &n);
	rep (i, 1, n) {
		scanf("%d%d", &a, &b);
		val[a] = b;
		res += b;
	}
	scanf("%d", &n);
	rep (i, 1, n) {
		scanf("%d%d", &a, &b);
		if (!val[a]) res += b;
		else res += max(0, b - val[a]);
	}
	printf("%I64d\n", res);
	
	return 0;
}