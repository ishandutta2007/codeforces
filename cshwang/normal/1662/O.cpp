#include <bits/stdc++.h>

#define pir std::pair<int , int>

const int D = 720 , MAX_R = 20 + 5 , MAX_D = D + 5 , MAX_SIZ = 1e5 + 10 ;

struct Link {
	int r , d ;
	Link *next ;
}list[MAX_SIZ] ;

int T , n , cur ;
int ty[MAX_R][MAX_D] ;
bool ap[MAX_R][MAX_D] ;
Link *head[MAX_R][MAX_D] ;

void ins(int x1 , int y1 , int x2 , int y2) {
	list[cur].r = x2 ;
	list[cur].d = y2 ;
	list[cur].next = head[x1][y1] ;
	head[x1][y1] = &list[cur++] ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 0 ; i <= 21 ; ++i)
			for (int j = 0 ; j < D ; ++j) {
				head[i][j] = NULL ;
				ty[i][j] = 0 ; ap[i][j] = 0 ;
			}

		for (int i = 0 ; i < n ; ++i) {
			getchar() ; char op = getchar() ;
			if (op == 'C') {
				int r , t1 , t2 ; scanf("%d %d %d" , &r , &t1 , &t2) ;
				t1 <<= 1 ; t2 <<= 1 ;
				for (; ;) {
					ty[r][t1] |= 1 ;
					if (t1 == t2) break ;
					(++t1) %= D ;
				}
			}
			else {
				int r1 , r2 , t ;
				scanf("%d %d %d" , &r1 , &r2 , &t) ;
				t <<= 1 ;
				for (int i = r1 + 1 ; i <= r2 ; ++i) ty[i][t] |= 2 ;
			}
		}

		///

		cur = 0 ;
		for (int i = 0 ; i <= 20 ; ++i)
			for (int j = 0 ; j < D ; ++j) {
				if ((ty[i][j] & 1) == 0) {
					ins(i , j , i + 1 , j) ;
					ins(i + 1 , j , i , j) ;
				}
				if ((ty[i][j] & 2) == 0) {
					ins(i , j , i , (j + 1) % D) ;
					ins(i , (j + 1) % D , i , j) ;
				}
			}

		std::queue<pir> que ;
		for (int j = 0 ; j < D ; ++j) que.push(std::make_pair(0 , j)) , ap[0][j] = 1 ;
		for (; !que.empty() ;) {
			int x = que.front().first , y = que.front().second ;
			que.pop() ;
			for (Link *h = head[x][y] ; h ; h = h->next) {
				int nx = h->r , ny = h->d ;
				if (ap[nx][ny]) continue ;
				ap[nx][ny] = 1 ;
				que.push(std::make_pair(nx , ny)) ;
			}
		}

		bool ok = 0 ;
		for (int j = 0 ; j < D ; ++j) ok |= ap[21][j] ;
		if (ok) printf("YES\n") ;
		else printf("NO\n") ;
	}

	return 0 ;
}