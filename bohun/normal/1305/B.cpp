#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

char s[1100];

int n;
bool x[1100];

vector <vector <int>> res;

int main() {	
	scanf ("%s", s + 1);
	n = strlen(s + 1);
	
	while (true) {
		int i = 1;
		int j = n;
		
		while (i <= n && (x[i] || s[i] == ')')) i++;
		while (1 <= j && (x[j] || s[j] == '(')) j--;
		
		if (i >= n + 1 || j <= 0 || i > j) break;
		
		vector <int> z = {};
		
		while (i < j) {
			z.pb(i);
			z.pb(j);
			
			x[i] = 1;
			x[j] = 1;
			
			while (i <= n && (x[i] || s[i] == ')')) i++;
			while (1 <= j && (x[j] || s[j] == '(')) j--;
			if (i >= n + 1 || j <= 0) break;
		}
		
		res.pb(z);
	}
	
	printf ("%d\n", ss(res));
	for (auto it : res) {
		printf ("%d\n", ss(it));
		sort(it.begin(), it.end());
		for (auto i : it)
			printf ("%d ", i);
		printf ("\n");
	}
			 
	
	return 0;
}