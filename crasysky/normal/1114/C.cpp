#include <algorithm>
#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
using namespace std;
long long calc(long long n, long long base){
	long long b = base, ans = 0;
    for (; ; b *= base){
		ans += n / b;
		if (b > n / base)
			break;
    }
    return ans;
}
int main(){
    long long n, b, ans = -1;
    cin >> n >> b;
    for (long long i = 2; i * i <= b; ++ i)
		if (b % i == 0){
			long long cnt = 0;
			while (b % i == 0){
				++ cnt;
				b /= i;
			}
			if (ans == -1)
				ans = calc(n, i) / cnt;
			else
				ans = min(ans, calc(n, i) / cnt);
		}
	if (b != 1){
		if (ans == -1)
			ans = calc(n, b);
		else
			ans = min(ans, calc(n, b));
	}
	/*
	for (long long i = b, c = 1; ; i *= b, ++ c){
		if (ans % i){
			cout << c - 1 << endl;
			return 0;
		}
		if (i > ans / b){
			cout << c << endl;
			return 0;
		}
	}
	*/
	cout << ans << endl;
}