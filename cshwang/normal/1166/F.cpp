#include <map>
#include <set>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

std::set<int> pt[MAX_N] ;
std::map<int , int> lk[MAX_N] ;

int n , m , c , q , fa[MAX_N] , siz[MAX_N] ;

inline int findset(int x) {return fa[x] == -1 ? x : (fa[x] = findset(fa[x])) ;}

void addpoint(int x , int y) {
	x = findset(x) ;
	if (pt[x].find(y) == pt[x].end()) pt[x].insert(y) , ++siz[x] ;
}

void merge(int x , int y) {
	x = findset(x) ; y = findset(y) ;
	if (x == y) return ;

	if (siz[x] > siz[y]) std::swap(x , y) ;
	fa[x] = y ;

	for (std::set<int> :: iterator p = pt[x].begin() ; p != pt[x].end() ; ++p)
		addpoint(y , *p) ;
}

void add(int x , int y , int c) {
	addpoint(x , y) ;
	if (!lk[x].count(c)) {lk[x][c] = y ; return ;}

	merge(lk[x][c] , y) ;
}

int main() {
	scanf("%d %d %d %d" , &n , &m , &c , &q) ;

	for (int i = 1 ; i <= n ; ++i) fa[i] = -1 ;
	for (int i = 0 ; i < m ; ++i) {
		int x , y , c ;
		scanf("%d %d %d" , &x , &y , &c) ;
		add(x , y , c) ; add(y , x , c) ;
	}

	///

	for (; q-- ;) {
		getchar() ;

		char op ; int x , y ;
		scanf("%c %d %d" , &op , &x , &y) ;

		if (op == '?') {
			int fx = findset(x) , fy = findset(y) ;

			if (fx == fy) printf("Yes\n") ;
			else if (pt[fx].find(y) != pt[fx].end()) printf("Yes\n") ;
			else printf("No\n") ;
		}
		else {
			scanf("%d" , &c) ;
			add(x , y , c) ; add(y , x , c) ;
		}
	}

	return 0 ;
}