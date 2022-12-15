#include <bits/stdc++.h>

const int MAX_N = 4e6 + 10 ;

int n , mod , f[MAX_N] , s[MAX_N] ;

int main() {
	scanf("%d %d" , &n , &mod) ;

	///

	f[n] = s[n] = 1 ;
	for (int i = n - 1 ; i ; --i) {
		f[i] = s[i + 1] ;

		int pre = i , ad = 0 ;
		for (int j = 2 ; i * j <= n ; ++j) {
			int st = i * j , ed = std::min(n , st + j - 1) ,
				res = (s[st] - s[ed + 1] + mod) % mod ;

			(ad += res) %= mod ;
		}

		(f[i] += ad) %= mod ; s[i] = (s[i + 1] + f[i]) % mod ;
	}

	printf("%d\n" , f[1]) ;

	return 0 ;
}