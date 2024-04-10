#include <bits/stdc++.h>
using namespace std ;

const int MAX_N = 1e6 + 10 ;

string s[MAX_N] ;
int n , m , pl[MAX_N] ;

bool cmp(int a , int b) {
	int p ;
	for (p = 0 ; p < m ; ++p) if (s[a][p] != s[b][p]) break ;

	if (p & 1) return s[a][p] > s[b][p] ;
	else return s[a][p] < s[b][p] ;
}

int main() {
	cin >> n >> m ;
	for (int i = 0 ; i < n ; ++i) cin >> s[i] ;
	for (int i = 0 ; i < n ; ++i) pl[i] = i ;

	///

	sort(pl + 0 , pl + n , cmp) ;
	for (int i = 0 ; i < n ; ++i) cout << pl[i] + 1 << " " ;
	cout << "\n" ;

	return 0 ;
}