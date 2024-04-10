#include <bitset>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 200 + 10 , MAX_L = 10 + 5 , MAX_S = (1 << 11) + 10 , K = 10 ;

std::bitset<MAX_S> ap[MAX_N] ;

int n , m ;
char st[MAX_N] , pre[MAX_N][MAX_L] , suf[MAX_N][MAX_L] ;

void update(int len , int p) {
	int offset = 0 ;
	for (int L = 1 ; L <= K ; ++L) {
		for (int i = 0 ; i < len ; ++i) {
			int j = i + L ;
			if (j > len) break ;

			int num = 0 ;
			for (int k = i ; k < j ; ++k) num = (num << 1) + st[k] - '0' ;

			ap[p][num + offset] = 1 ;
		}

		offset += (1 << L) ;
	}
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) {
		scanf("%s" , st) ;

		///

		int len = strlen(st) ;
		update(len , i) ;

		for (int p = 0 , j = std::max(0 , len - K) ; j < len ; ++j) suf[i][p++] = st[j] ;
		for (int p = 0 , j = 0 ; j < std::min(len , K) ; ++j) pre[i][p++] = st[j] ;
	}

	///

	scanf("%d" , &m) ;
	for (int i = n + 1 ; i <= n + m ; ++i) {
		int a , b ; scanf("%d %d" , &a , &b) ;

		ap[i] = ap[a] | ap[b] ;
		int l1 = strlen(suf[a]) , l2 = strlen(pre[b]) ;
		for (int j = 0 ; j < l1 ; ++j) st[j] = suf[a][j] ;
		for (int j = 0 ; j < l2 ; ++j) st[j + l1] = pre[b][j] ;
		update(l1 + l2 , i) ;

		///

		int l3 = strlen(pre[a]) , l4 = strlen(suf[b]) , p = 0 ;
		for (int j = 0 ; j < std::min(K , l3) ; ++j) pre[i][p++] = pre[a][j] ;
		for (int j = 0 ; j < std::min(l2 , K - l3) ; ++j) pre[i][p++] = pre[b][j] ;

		p = 0 ;
		for (int j = std::max(0 , l1 - (K - l4)) ; j < l1 ; ++j) suf[i][p++] = suf[a][j] ;
		for (int j = std::max(0 , l4 - K) ; j < l4 ; ++j) suf[i][p++] = suf[b][j] ;

		///

		int ans = 0 , next = 1 , area = 1 ;
		for (int j = 0 ; j < MAX_S ; ++j) {
			if (!ap[i][j]) break ;

			if (j == next) ++area , ++ans , next += (1 << area) ;
		}

		printf("%d\n" , ans) ;
	}

	return 0 ;
}