#include <bits/stdc++.h>

const int MAX_N = 2e5 + 10 ;

std::queue<int> que ;
std::vector<int> vt[MAX_N] ;

int T , n , d[MAX_N] , deg[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) vt[i].clear() , deg[i] = 0 ;
		for (int i = 1 ; i <= n ; ++i) {
			int k ; scanf("%d" , &k) ;

			for (int j = 0 ; j < k ; ++j) {
				int x ; scanf("%d" , &x) ;
				vt[x].push_back(i) , ++deg[i] ;
			}
		}

		///

		for (int i = 1 ; i <= n ; ++i) {
			d[i] = 0 ;
			if (!deg[i]) que.push(i) , d[i] = 1 ;
		}

		for (; !que.empty() ;) {
			int x = que.front() ; que.pop() ;

			for (auto i : vt[x]) {
				--deg[i] ;
				if (!deg[i]) que.push(i) ;

				if (x > i) d[i] = std::max(d[i] , d[x] + 1) ;
				else d[i] = std::max(d[i] , d[x]) ;
			}
		}

		int ans = d[1] ;
		for (int i = 1 ; i <= n ; ++i) {
			if (deg[i]) {ans = -1 ; break ;}
			ans = std::max(ans , d[i]) ;
		}

		printf("%d\n" , ans) ;
	}

	return 0 ;
}