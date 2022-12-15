#include <set>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 , MAX_M = 'z' + 10 ;

std::set<int> mx ;
std::vector<int> pl[MAX_M] ;

int T , n ;
char s[MAX_N] ;
bool ud[MAX_N] , ap[MAX_M] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%s" , s) ; n = strlen(s) ;
		for (int i = 'a' ; i <= 'z' ; ++i) pl[i].clear() , ap[i] = 0 ;
		for (int i = 0 ; i < n ; ++i) pl[s[i]].push_back(i) ;

		///

		for (int i = 'a' ; i <= 'z' ; ++i) {
			if (!pl[i].size()) continue ;
			int x = pl[i][pl[i].size() - 1] ;
			mx.insert(x) ;
		}

		int pre = -1 ;
		for (; !mx.empty() ;) {
			int R = *mx.begin() , nw = -1 , c = 'z' ;
			for (c = 'z' ; c >= 'a' ; --c) {
				if (!pl[c].size() || ap[c]) continue ;

				int p = *std::lower_bound(pl[c].begin() , pl[c].end() , pre) ;
				if (p <= R) {nw = p ; break ;}
			}

			printf("%c" , s[nw]) ;
			ap[c] = 1 ; pre = nw + 1 ; mx.erase(pl[c][pl[c].size() - 1]) ;
		}
		printf("\n") ;
	}

	return 0 ;
}