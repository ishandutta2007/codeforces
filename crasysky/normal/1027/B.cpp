#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	int n = read(), q = read();
	while (q --){
		int x = read(), y = read();
		if (((x + y) & 1) == 0){
			long long cnt;
			if (x & 1)
				cnt = 1LL * (x - 1) / 2 * n;
			else
				cnt = 1LL * (x - 2) / 2 * n + (n + 1) / 2;
			if (x & 1)
				cnt += (y + 1) / 2;
			else
				cnt += y / 2;
			printf("%lld\n", cnt);
		}
		else{
			long long cnt = (1LL * n * n + 1) / 2;
			if (x & 1)
				cnt += 1LL * (x - 1) / 2 * n;
			else
				cnt += 1LL * (x - 2) / 2 * n + n / 2;
			if (x & 1)
				cnt += y / 2;
			else
				cnt += (y + 1) / 2;
			printf("%lld\n", cnt);
		}
	}
}