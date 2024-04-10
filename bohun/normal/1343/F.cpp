#include <bits/stdc++.h>
#define ll long long
#define ld long double
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

const int nax = 210;

int n, k, a;

vector <vector <int>> v;
vector <int> f;

int p[nax];
int used[nax];
int uu[nax];
int gdzie[nax];

bool ok(int a, int b) {
	rep(i, 1, n) used[i] = p[i] = gdzie[i] = 0;
	p[1] = a;
	p[2] = b;
	used[a] = 1;
	used[b] = 1;
	gdzie[a] = 1;
	gdzie[b] = 2;
	
	rep(i, 0, n) uu[i] = 0;
	
	rep(i, 3, n) {
		rep(j, 0, n - 2) {
			if (uu[j]) continue;
			int qw = -1;
			for (auto it : v[j]) {
				if (used[it] == true) {
					if (gdzie[it] + ss(v[j]) - 1 >= i) continue;
					qw = -1;
					break;
				}
				else {
					if (qw != -1) {
						qw = -1;
						break;
					}
					qw = it;
				}
			}
			if (qw == -1) {
				continue;
			}
			uu[j] = 1;
			p[i] = qw;
			gdzie[qw] = i;
			used[qw] = 1;
			break;
		}
		if (!p[i]) return false;
	}
	return true;
}
	

int main() {
	srand(1337);
	int t;
	scanf ("%d", &t);
	while (t--) {
		v.clear();
		scanf ("%d", &n);
		rep(i, 1, n - 1) {
			scanf ("%d", &k);
			f.clear();
			rep(j, 1, k) {
				scanf ("%d", &a);
				f.pb(a);
			}
			v.pb(f);
		}
		
		random_shuffle(all(v));
			
		for (auto it : v) {
			if (ss(it) == 2) {
				if (ok(it[0], it[1])) break;
				if (ok(it[1], it[0])) break;
			}
		}
		
		rep(i, 1, n) printf ("%d ", p[i]);
		printf ("\n");
		
	}
	
	return 0;
}