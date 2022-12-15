#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define db double
#define pi acos(-1)
#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

struct data {
	db S ;
	int x , y , r ;
}a[MAX_N] ;
struct Link {
	int num ;
	Link *next ;
}list[MAX_N] ;

Link *head[MAX_N] ;
db f[MAX_N][2][2] ;
int n , cur , fa[MAX_N] ;

int type(int x) {return x ? 1 : -1 ;}

ll squ(int x) {return (ll)x * x ;}

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void dp(int x) {
	db sum[2][2] ;
	sum[0][0] = sum[0][1] = sum[1][0] = sum[1][1] = 0 ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int num = h->num ;
		dp(num) ;

		for (int i = 0 ; i < 2 ; ++i)
			for (int j = 0 ; j < 2 ; ++j) sum[i][j] += f[num][i][j] ;
	}

	for (int i = 0 ; i < 2 ; ++i)
		for (int j = 0 ; j < 2 ; ++j) {
			db s1 = sum[i][j ^ 1] + type(j ^ 1) * a[x].S ,
			   s2 = sum[i ^ 1][j] + type(i ^ 1) * a[x].S ;

			f[x][i][j] = std::max(s1 , s2) ;
		}
}

bool check(int x , int y) {
	data *p = &a[x] , *q = &a[y] ;
	if (p->r < q->r) return 0 ;

	ll t1 = squ(p->x - q->x) + squ(p->y - q->y) , t2 = squ(p->r) ;

	return t1 < t2 ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) {
		data *p = &a[i] ;
		scanf("%d %d %d" , &p->x , &p->y , &p->r) ;
		p->S = pi * squ(p->r) ;
	}

	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= n ; ++j) {
			if (i == j) continue ;

			if (check(i , j) && (!fa[j] || check(fa[j] , i))) fa[j] = i ;
		}
	for (int i = 1 ; i <= n ; ++i)
		if (fa[i]) ins(fa[i] , i) ;

	///

	
	db ans = 0 ;
	for (int i = 1 ; i <= n ; ++i) 
		if (!fa[i]) {
			dp(i) ;
			ans += f[i][0][0] ;
		}

	printf("%0.10lf\n" , ans) ;

	return 0 ;
}