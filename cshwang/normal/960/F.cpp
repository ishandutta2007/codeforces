#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

struct Node {
	int num , f , maxf , r ;
	Node *ch[2] ;

	int getans() {return std::max(f , ch[0] ? ch[0]->maxf : 0) ;}
	void update() {
		maxf = f ;
		for (int i = 0 ; i < 2 ; ++i)
			if (ch[i]) maxf = std::max(maxf , ch[i]->maxf) ;
	}
}list[MAX_N] ;

Node *root[MAX_N] ;
int n , m , cur , ans ;

void rotate(Node *&rt , int d) {
	Node *son = rt->ch[d^1] ;
	rt->ch[d^1] = son->ch[d] ; son->ch[d] = rt ;
	rt->update() ; son->update() ; rt = son ;
}

int find(Node *rt , int x) {
	if (!rt) return 0 ;

	if (rt->num > x) return find(rt->ch[0] , x) ;
	else return std::max(rt->getans() , find(rt->ch[1] , x)) ;
}

void insert(Node *&rt , int x , int f) {
	if (!rt) {
		rt = &list[cur++] ;
		rt->num = x ; rt->f = f ; rt->maxf = f ; rt->r = rand() ;
		rt->ch[0] = rt->ch[1] = NULL ;

		return ;
	}

	int d = rt->num > x ? 0 : 1 ;
	insert(rt->ch[d] , x , f) ;
	rt->update() ;

	if (rt->r > rt->ch[d]->r) rotate(rt , d^1) ;
}

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 0 ; i < m ; ++i) {
		int x , y , v , f ;
		scanf("%d %d %d" , &x , &y , &v) ;
		f = find(root[x] , v - 1) + 1 ;
		insert(root[y] , v , f) ;

		ans = std::max(ans , f) ;
	}

	printf("%d\n" , ans) ;

	return 0 ;
}