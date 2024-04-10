#include <bits/stdc++.h>

#define ll long long

const int N = 2e5 , MAX_N = 4e5 + 10 , mod = 998244353 ;

struct Node {
	int num , siz , r ;
	Node *ch[2] ;

	int getrank() {return ch[0] ? ch[0]->siz + 1 : 1 ;}
	void init(int a) {num = a ; siz = 1 ; r = 0 ; ch[0] = ch[1] = NULL ;}
	void update() {
		siz = 1 ;
		for (int i = 0 ; i < 2 ; ++i) siz += ch[i] ? ch[i]->siz : 0 ;
	}
}list[MAX_N] ;

int cur ;
Node *root ;

void rotate(Node *&rt , int d) {
	Node *son = rt->ch[d^1] ;

	rt->ch[d^1] = son->ch[d] ; son->ch[d] = rt ;
	rt->update() ; son->update() ; rt = son ;
}

void ins(Node *&rt , int a) {
	if (!rt) {
		rt = &list[cur++] ;
		rt->init(a) ; rt->r = rand() ;

		return ;
	}

	int d = rt->num > a ? 0 : 1 ;
	ins(rt->ch[d] , a) ; rt->update() ;

	if (rt->ch[d]->r > rt->r) rotate(rt , d^1) ;
}

void del(Node *&rt , int a) {
	if (rt->num == a) {
		if (!rt->ch[0]) rt = rt->ch[1] ;
		else if (!rt->ch[1]) rt = rt->ch[0] ;
		else {
			int d = rt->ch[0]->r > rt->ch[1]->r ? 0 : 1 ;
			rotate(rt , d^1) ; del(rt->ch[d^1] , a) ;
		}

		if (rt) rt->update() ;

		return ;
	}

	int d = rt->num > a ? 0 : 1 ;
	del(rt->ch[d] , a) ; rt->update() ;
}

int findrank(Node *rt , int a) {
	if (!rt) return 0 ;

	int r = rt->getrank() ;
	if (rt->num > a) return findrank(rt->ch[0] , a) ;
	else return findrank(rt->ch[1] , a) + r ;
}

int findnum(Node *rt , int k) {
	int r = rt->getrank() ;

	if (r == k) return rt->num ;
	else if (r < k) return findnum(rt->ch[1] , k - r) ;
	else return findnum(rt->ch[0] , k) ;
}

//------------------------------------------------------------------------//

std::vector<int> num ;

bool ap[MAX_N] ;
int T , n , m , y[MAX_N] , jc[MAX_N] , inv[MAX_N] ;

void init() {
	int siz = num.size() ;
	for (int i = 0 ; i < siz ; ++i) ins(root , num[i]) , ap[num[i]] = 0 ;

	num.clear() ;
}

int qpow(int a , int t) {
	int s = 1 ;
	for (; t ; t >>= 1 , a = (ll)a * a % mod)
		if (t & 1) s = (ll)s * a % mod ;

	return s ;
}

inline int rC(int n , int p) {
	return (ll)jc[n + p - 1] * inv[n - 1] % mod * inv[p] % mod ;
}

inline int cal(int p) {
	int p1 = (ll)rC(n , p + 1) * (p + 1) % mod , inv = qpow(n , mod - 2) ;

	return (ll)p1 * inv % mod ;
}

int main() {
	int dn = N << 1 ; jc[1] = 1 ;
	for (int i = 2 ; i <= dn ; ++i) jc[i] = (ll)jc[i - 1] * i % mod ;
	inv[dn] = qpow(jc[dn] , mod - 2) ;
	for (int i = dn - 1 ; i >= 0 ; --i) inv[i] = (ll)inv[i + 1] * (i + 1) % mod ;

	for (int i = 1 ; i <= N ; ++i) ins(root , i) ;

	///

	int T ;
	scanf("%d" , &T) ;
	for (; T-- ;) {
		init() ;
		scanf("%d %d" , &n , &m) ;
		for (int i = 0 ; i < m ; ++i) {
			int t ; scanf("%d %d" , &t , &y[i]) ;
		}

		///

		int p = 1 ;
		for (int i = m - 1 ; i >= 0 ; --i) {
			int nw = findnum(root , y[i]) ;
			ap[nw] = 1 ; if (!ap[nw + 1]) ++p ;

			del(root , nw) ; num.push_back(nw) ;
		}

		printf("%d\n" , cal(n - p)) ;
	}

	return 0 ;
}