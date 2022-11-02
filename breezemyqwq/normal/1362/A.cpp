#include <iostream>
#include <cstdio>

#define ll long long

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		if(a % b == 0) {
			ll k = a / b;
			int cnt = 0;
			while(k % 8 == 0) k /= 8, cnt++;
			if(k == 1) {
				printf("%d\n", cnt);
				continue;
			}
			while(k % 4 == 0) k /= 4, cnt++;
			if(k == 1) {
				printf("%d\n", cnt);
				continue;
			}
			while(k % 2 == 0) k /= 2, cnt++;
			if(k != 1) puts("-1");
			else printf("%d\n", cnt);
		}
		else if(b % a == 0) {
			ll k = b / a;
			int cnt = 0;
			while(k % 8 == 0) k /= 8, cnt++;
			if(k == 1) {
				printf("%d\n", cnt);
				continue;
			}
			while(k % 4 == 0) k /= 4, cnt++;
			if(k == 1) {
				printf("%d\n", cnt);
				continue;
			}
			while(k % 2 == 0) k /= 2, cnt++;
			if(k != 1) puts("-1");
			else printf("%d\n", cnt);
		}
		else puts("-1");
	}
	return 0;
}