#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int L = 31 , MAX_L = 31 + 5 , mod = 1e9 + 7 ;

int T , x1 , x2 , y1 , y2 , k ;
int f[MAX_L][2][2][2] , g[MAX_L][2][2][2] ;

int cal(int n , int m) {
	if (n < 0 || m < 0) return 0 ;

	for (int i = L ; i >= 0 ; --i)
		for (int x = 0 ; x <= 1 ; ++x)
			for (int y = 0 ; y <= 1 ; ++y)
				for (int z = 0 ; z <= 1 ; ++z)
					f[i][x][y][z] = g[i][x][y][z] = 0 ;

	f[L][1][1][1] = 0 ; g[L][1][1][1] = 1 ;
	for (int i = L ; i > 0 ; --i)
		for (int x = 0 ; x <= 1 ; ++x)
			for (int y = 0 ; y <= 1 ; ++y)
				for (int z = 0 ; z <= 1 ; ++z)
					for (int a = 0 ; a <= 1 ; ++a)
						for (int b = 0 ; b <= 1 ; ++b) {
							int c = a ^ b , j = i - 1 ; bool ch1 , ch2 , ch3 ;

							ch1 = ((1 << j) & n) >= ((a & x) << j) ? 1 : 0 ;
							ch2 = ((1 << j) & m) >= ((b & y) << j) ? 1 : 0 ;
							ch3 = ((1 << j) & k) >= ((c & z) << j) ? 1 : 0 ;

							if (ch1 & ch2 & ch3) {
								int st1 , st2 , st3 ;
								st1 = ((1 << j) & n) == (a << j) ? 1 & x : 0 ;
								st2 = ((1 << j) & m) == (b << j) ? 1 & y : 0 ;
								st3 = ((1 << j) & k) == (c << j) ? 1 & z : 0 ;

								(g[j][st1][st2][st3] += g[i][x][y][z]) %= mod ;
								(f[j][st1][st2][st3] += f[i][x][y][z]) %= mod ;
								f[j][st1][st2][st3] = ((ll)f[j][st1][st2][st3] + ((ll)c << (j)) * g[i][x][y][z]) % mod ;
							}
						}

	int sum = 0 ;
	for (int x = 0 ; x <= 1 ; ++x)
		for (int y = 0 ; y <= 1 ; ++y)
			for (int z = 0 ; z <= 1 ; ++z) {
				(sum += f[0][x][y][z]) %= mod ;
				(sum += g[0][x][y][z]) %= mod ;
			}

	return sum ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d %d %d %d" , &x1 , &y1 , &x2 , &y2 , &k) ;
		--x1 ; --y1 ; --x2 ; --y2 ; --k ;

		int s1 = cal(x2 , y2) , s2 = cal(x1 - 1 , y2) , s3 = cal(x2 , y1 - 1) , s4 = cal(x1 - 1 , y1 - 1) , ans ;
		ans = ((ll)s1 - s2 - s3 + mod + mod + s4) % mod ;

		printf("%d\n" , ans) ;
	}

	return 0 ;
}