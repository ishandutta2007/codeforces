#include <bits/stdc++.h>

const int MAX_N = 2021 + 10 ;

struct data {
	int x , pl ;

	friend bool operator <(data a , data b) {return a.x < b.x ;}
	friend bool operator >(data a , data b) {return a.x > b.x ;}
} ;

std::vector<int> ans ;

bool ok ;
int T , n , a[MAX_N] ;

bool deal(int x) {
	if (!(x & 1)) return 0 ;

	std::reverse(a + 1 , a + 1 + x) ; ans.push_back(x) ;
	return 1 ;
}

data find_max(int x , int y) {
	data p = (data){a[x] , x} ;
	for (int i = x + 1 ; i <= y ; ++i) {
		data nw = (data){a[i] , i} ;
		p = std::max(p , nw) ;
	}

	return p ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

		///

		ans.clear() ;
		bool ok = 1 ;

		for (int len = n ; len > 1 ; len -= 2) {
			data p1 = find_max(1 , len) , p2 ;
			if (!deal(p1.pl)) {ok = 0 ; break ;}

			///

			p2 = find_max(2 , len) ;
			if (!deal(p2.pl - 1)) {ok = 0 ; break ;}
			deal(p2.pl + 1) ; deal(3) ; deal(len) ;
		}

		///

		if (ok) {
			int siz = ans.size() ;
			printf("%d\n" , siz) ;
			for (int i = 0 ; i < siz ; ++i) printf("%d " , ans[i]) ;
			printf("\n") ;
		}
		else printf("-1\n") ;
	}

	return 0 ;
}