#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;	
 
const int V = 100000;
 
int n;
int A[V];	
int B[V];
 
map <int, int> maps;
 
int cnt = 0;
 
pair<int, int> ask(int l, int r) {
	//cnt++;
	//if (cnt == 5) exit(0);
	/*printf ("? %d %d\n", l, r);
	rep(i, 1, V - 1) B[i] = 0;
	rep(i, l, r) B[A[i]]++;
	pair<int, int> ans = {-1, -1};
	rep(i, 1, V - 1)
		if (B[i] > ans.fi)
			ans = {B[i], i};
	return {ans.se, ans.fi};*/
	printf ("? %d %d\n", l, r);
	fflush(stdout);
	int x, y;
	scanf ("%d%d", &x, &y);
	return {x, y};
}
 
bool czynalewo(int l, int val) {
	if (l == 1) return false;
	return ask(l - 1, l - 1).fi == val;
}
 
bool czynaprawo(int l, int val) {
	if (l == n) return false;
	return ask(l + 1, l + 1).fi == val;
}
 
int prawo(int r, int kto, int ile, int koniec = -1) {
	//printf ("%d %d %d %d\n", r, kto, ile, koniec);
	if (r <= 0) return 0;
	if (koniec == -1) {
		auto it = ask(r, r);
		if (it.fi == kto) return 0;
		koniec = it.fi;
	}
	
	auto it = ask(r - ile + 1, r);
	if (it.fi == koniec) {
		//cat("A");
		maps[it.fi] = it.se;
		return it.se + prawo(r - it.se, kto, ile);
	}
	
	if (it.fi == kto) {
		//cat("C");
		return prawo(r, kto, ile - it.se, koniec);
	}
	
	if (czynalewo(r - ile + 1, it.fi)) {
		//cat("E");
		int sum = prawo(r, it.fi, it.se, koniec);
		return sum + prawo(r - sum, kto, ile, it.fi);
	}
	//cat("X");
	maps[it.fi] = it.se;
	int sum = it.se + prawo(r, it.fi, it.se, koniec);
	return sum + prawo(r - sum, kto, ile);	
}
 
int lewo(int l, int kto, int ile, int poczatek = -1) {
	if (l > n) return 0;
	if (poczatek == -1) {
		auto it = ask(l, l);
		if (it.fi == kto) return 0;
		poczatek = it.fi;
	}
	
	auto it = ask(l, l + ile - 1);
	if (it.fi == poczatek) {
		maps[it.fi] = it.se;
		return it.se + lewo(l + it.se, kto, ile);
	}
	
	if (it.fi == kto) 
		return lewo(l, kto, ile - it.se, poczatek);
	
	if (czynaprawo(l + ile - 1, it.fi)) {
		int sum = lewo(l, it.fi, it.se, poczatek);
		return sum + lewo(l + sum, kto, ile, it.fi);
	}
		
	maps[it.fi] = it.se;
	int sum = it.se + lewo(l, it.fi, it.se, poczatek);
	return sum + lewo(l + sum, kto, ile);
}
 
int main() {
	scanf ("%d", &n);
	
	auto it = ask(1, n);
	maps[it.fi] = it.se;
	
	prawo(n, it.fi, it.se);
	
	lewo(1, it.fi, it.se);
	
	printf ("! ");
	for (auto it : maps) 
		rep(i, 1, it.se)
			printf ("%d ", it.fi);
	
	return 0;
}