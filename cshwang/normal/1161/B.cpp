#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

std::vector<int> st[MAX_N] ;

int n , m , tmp[MAX_N] , nxt[MAX_N] ;

inline int gcd(int x , int y) {return y ? gcd(y , x % y) : x ;}

inline int lcm(int x , int y) {
	int d = gcd(x , y) ;
	ll tmp = x / d * y ;

	if (tmp > n) return n ;
	else return tmp ;
}

int count(int o) {
	int siz = st[o].size() , ns = siz - 1 ;
	if (!siz) return 1 ;

	std::sort(st[o].begin() , st[o].end()) ;
	for (int i = 1 ; i < siz ; ++i) tmp[i] = st[o][i] - st[o][i - 1] ;

	nxt[0] = nxt[1] = 0 ;
	for (int i = 2 ; i <= ns ; ++i) {
		int j = nxt[i - 1] ;
		for (; j && tmp[j + 1] != tmp[i] ; j = nxt[j]) ;

		if (tmp[j + 1] == tmp[i]) ++j ;
		nxt[i] = j ;
	}

	///

	int res = n ;
	if (!(n % 2) && o == n / 2) res = o ;

	for (int i = 1 ; i <= siz / 2 ; ++i) {
		if (siz % i) continue ;

		int tmp = -1 ;
		for (int j = i - 1 ; j < siz ; j += i)
			if (j != i - 1 && nxt[j] < i - 1) {tmp = n ; break ;}
			else {
				int cs = (st[o][(j + i) % siz] - st[o][j] + n) % n ;

				if (tmp == -1) tmp = cs ;
				else if (tmp != cs) {tmp = n ; break ;}
			}

		res = std::min(res , tmp) ;
	}

	return res ;
}

int main() {
	scanf("%d %d" , &n , &m) ;

	for (int i = 0 ; i < m ; ++i) {
		int x , y ; scanf("%d %d" , &x , &y) ;

		int l1 = (y - x + n) % n , l2 = (x - y + n) % n ;
		if (l2 < l1) std::swap(x , y) , std::swap(l1 , l2) ;

		st[l1].push_back(x) ;
	}

	///

	int s = 1 ;
	for (int i = 1 ; i < n ; ++i) {
		int a = count(i) ;
		s = lcm(s , a) ;

		if (s >= n) break ;
	}

	if (s < n) printf("Yes\n") ;
	else printf("No\n") ;

	return 0 ;
}