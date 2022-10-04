/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll INF = 1e9;

int n, m;
vector<int> a;

int main() {
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < m; ++i) {
		int c;
		cin >> c;
		c--;
		a[c]++;
	}
	int cnt = INF;
	for (int i = 0; i < n; ++i) {
		cnt = min(cnt, a[i]);
	}
	cout << cnt << endl;
}