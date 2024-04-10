// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

const int nax = 2e5 + 11;
const int mod = 1e9 + 7;

int n, p, q;

char s[nax];
vector <string> res;
string elo;

int main() {
	scanf("%d %d %d", &n, &p, &q);
	scanf("%s", s + 1);
	
	int a = -1;
	int b = -1;
	for(int i = 0; i <= 100; ++i) {
		int suma = i * p;
		if(n - suma >= 0 && (n - suma) % q == 0) {
			a = i;
			b = (n - suma) / q;
			break;
		}
	}
	if(a == -1) {
		printf("-1");
		return 0;
	}
	printf("%d\n", a + b);
	int pos = n;
	while(a > 0) {
		elo.pb(s[pos--]);
		if(ss(elo) == p) {
			reverse(elo.begin(), elo.end());
			res.pb(elo);
			elo = "";
			a -= 1;
		}
	}
	while(b > 0) {
		elo.pb(s[pos--]);
		if(ss(elo) == q) {
			reverse(elo.begin(), elo.end());
			res.pb(elo);
			elo = "";
			b -= 1;
		}
	}
	reverse(res.begin(), res.end());
	for(auto it : res) {
		for(int i = 0; i < ss(it); ++i)
			printf("%c", it[i]);
		printf("\n");
	}
	
			
	
	
	
	
	return 0;
}