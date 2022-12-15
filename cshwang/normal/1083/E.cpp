#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define db double
#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const db eps = 1e-6 ;
const int MAX_N = 1e6 + 10 ;

struct data {ll x , y , a ;}dt[MAX_N] , que[MAX_N] ;

ll f[MAX_N] ;
int n , L , R ;

db getk(data a , data b) {
	return (a.y - b.y) * 1.0 / (a.x - b.x) ;
}

void push(data a) {
	for (; L < R && getk(que[R] , que[R - 1]) - getk(que[R] , a) < eps ; --R) ;
	que[++R] = a ;
}

void pop(ll k) {
	for (; L < R && k - getk(que[L] , que[L + 1]) < eps ; ++L) ;
}

bool cmp(data a , data b) {return a.y < b.y ;}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i)
		scanf("%lld %lld %lld" , &dt[i].x , &dt[i].y , &dt[i].a) ;
	std::sort(dt + 1 , dt + 1 + n ,cmp) ;

	///

	ll ans = 0 ;
	L = 1 ; R = 0 ; push((data){0 , 0 , 0}) ;
	for (int i = 1 ; i <= n ; ++i) {
		pop(dt[i].x) ;
		f[i] = dt[i].x * dt[i].y - dt[i].a + que[L].y - dt[i].x * que[L].x ;
		ans = std::max(ans , f[i]) ;

		push((data){dt[i].y , f[i] , 0}) ;
	}

	printf("%lld\n" , ans) ;

	return 0 ;
}