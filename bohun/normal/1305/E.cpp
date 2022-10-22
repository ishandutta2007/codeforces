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

int n, m;
vector <int> v;

int ile[1000005];

unordered_map <int, int> mapa;

void add(int x) {
	for (auto it : v)
		mapa[it + x] = 1;
	v.pb(x);
}

void jebaj() {
	int y = 0;
	for (auto it : v)
		y = max(y, it + 1);
	
	while (n--) {
		while (mapa.find(y) != mapa.end()) y++;
		add(y);
		y++;
	}
}

int main() {	
	scanf ("%d%d", &n, &m);
	
	if (n == 1) {
		if (m == 0) {
			printf ("1 \n");
			return 0;
		}
		printf ("-1\n");
		return 0;
	}
	
	if (n == 2) {
		if (m == 0) {
			printf ("1 2 \n");
			return 0;
		}
		printf ("-1\n");
		return 0;
	}
	
	add(1);
	add(2);
	
	n -= 2;
	
	int x = 3;
	
	while (true) {
		if (!n && m > 0) {
			printf ("-1\n");
			return 0;
		}
		
		if (m == 0) break;
		
		int z = (x % 2 == 0 ? x / 2 - 1 : x / 2);
		
		if (m >= z) {
			n--;
			add(x++);
			m -= z;
			continue;
		}
		
		break;
	}
	
	if (m == 0) {
		jebaj();
	}
	else {
		rep(i, 0, ss(v) - 1)
			rep(j, i + 1, ss(v) - 1)
				ile[v[i] + v[j]]++;
			
		bool ok = 0;
					
		rep(i, 1, 1000000) {
			if (x <= i && ile[i] == m) {
				add(i);
				n--;
				ok = 1;
				break;
			}
		}
		
		assert(ok);
		
		jebaj();
		
	}
	sort(v.begin(), v.end());
	for (auto it : v)
		printf ("%d ", it);
		
			
		
		
	
	return 0;
}