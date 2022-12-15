#include <stdio.h>
#include <stdlib.h>
using namespace std ;

const int MAX_N = 150000 + 10 ;

struct Link
{
	int num ;
	Link *next ;
}list[2 * MAX_N] ;

long long res ;
bool ap[MAX_N] ;
int n , m , cur ;
Link *head[MAX_N] ;

long long dfs(int x)
{
	long long sedge = 0 ;
	ap[x] = 1 ; ++res ;
	for (Link *h = head[x] ; h ; h = h->next , ++sedge)
	{
		int nx = h->num ;
		if (ap[nx]) continue ;
		
		sedge += dfs(nx) ;
	}

	return sedge ;
}

void ins(int x , int y)
{
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

int main()
{
	scanf("%d %d" , &n , &m) ;
	for (int i = 0 ; i < m ; ++i)
	{
		int x , y ;
		scanf("%d %d" , &x , &y) ;
		ins(x , y) ; ins(y , x) ;
	}

	///
	
	bool ans = 0 ;
	for (int i = 1 ; i <= n ; ++i)
		if (!ap[i])
		{
			res = 0 ;
			long long sum = dfs(i) ;

			if (sum != res * (res - 1)) {printf("NO\n") ; ans = 1 ; break ;}
		}

	if (!ans) printf("YES\n") ;

	return 0 ;
}