#include <bits/stdc++.h>

const int MAX_N = 200 + 10 ;

std::vector<int> pt ;

struct data {
	int x , y ;
}a[MAX_N] ;

int T , n , k ;
bool ap[MAX_N] ;

bool check(int x , int y) {
	if (a[x].x > a[y].x) std::swap(x , y) ;

	if (a[y].x <= a[x].y && a[x].y <= a[y].y) return 1 ;
	else return 0 ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		pt.clear() ;

		scanf("%d %d" , &n , &k) ;

		for (int i = 1 ; i <= (n << 1) ; ++i) ap[i] = 0 ;
		for (int i = 0 ; i < k ; ++i) {
			int x , y ;
			scanf("%d %d" , &x , &y) ;

			if (x > y) std::swap(x , y) ;
			a[i] = (data){x , y} ; ap[x] = ap[y] = 1 ;
		}

		///

		for (int i = 1 ; i <= (n << 1) ; ++i) if (!ap[i]) pt.push_back(i) ;

		int m = pt.size() , mm = m >> 1 ;
		for (int j = 0 ; j < mm ; ++j) {
			int nj = j + mm ;
			a[k++] = (data){pt[j] , pt[nj]} ;
		}

		int res = 0 ;
		for (int i = 0 ; i < k ; ++i)
			for (int j = i + 1 ; j < k ; ++j)
				if (check(i , j)) ++res ;

		printf("%d\n" , res) ;
	}

	return 0 ;
}