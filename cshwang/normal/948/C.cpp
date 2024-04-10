#include <queue>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define pq std::priority_queue
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

ll offset ;
int n , v[MAX_N] , t[MAX_N] ;
pq<ll , std::vector<ll> , std::greater<ll> > que ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &v[i]) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &t[i]) ;

	///

	for (int i = 0 ; i < n ; ++i) {
		ll ans = 0 ;

		que.push(v[i] + offset) ;
		offset += t[i] ; ans = (ll)que.size() * t[i] ;

		for (; !que.empty() ;) {
			ll x = que.top() ;
			if (x < offset) {ans -= (offset - x) ; que.pop() ;}
			else break ;
		}

		printf("%lld\n" , ans) ;
	}

	return 0 ;
}