#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

int ret[1001000], ans, n, p;

int main(){
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &p);
		ans ^= p;
		ret[i] = ret[i-1] ^ i;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n / i; j++)
			ans ^= ret[i - 1];
		int j = n / i * i;
		ans ^= ret[n - j];
	}
	printf("%d\n", ans);
	return 0;
}