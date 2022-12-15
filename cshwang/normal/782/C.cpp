#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std ;

const int MAX_N = 200000 + 10 ;

struct data
{
	int num , next ;
}list[2 * MAX_N] ;

bool allcol[MAX_N] ;
int n , cur , head[MAX_N] , color[MAX_N] ;

void dfs(int t , int fa)
{
	int c1 = color[t] , c2 = color[fa] ;

	int h = head[t] , col = 1 ;
	for (; h != -1 ; h = list[h].next)
	{
		int nt = list[h].num ;
		
		if (nt == fa) continue ;
		
		while (col == c1 || col == c2) ++col ;
		color[nt] = col ;

		dfs(nt , t) ;
		++col ;
	}
}

void ins(int x , int y)
{
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = cur++ ;
}

int main()
{
	memset(head , -1 , sizeof(head)) ;

	///

	scanf("%d" , &n) ;
	for (int i = 1 ; i < n ; ++i)
	{
		int x , y ;
		scanf("%d %d" , &x , &y) ;
		ins(x , y) ; ins(y , x) ;
	}

	///
	
	color[0] = 0 ;
	color[1] = 1 ;
	dfs(1 , 0) ;

	///

	int sum = 0 ;
	for (int i = 1 ; i <= n ; ++i)
		sum += !allcol[color[i]] ? 1 : 0 , allcol[color[i]] = 1 ;

	printf("%d\n" , sum) ;
	for (int i = 1 ; i <= n ; ++i) printf("%d " , color[i]) ;
	printf("\n") ;

	return 0 ;
}