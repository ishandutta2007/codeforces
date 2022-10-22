#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i < n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

int n;
int a;

struct nod {
	vector <pair<int,int>> pr; // prime, ile
	int d;
};

nod v[5005];

bool sito[5005];
vector <int> p;

ll ans;

int main() {
	for (int i = 2; i < 5000; ++i)
		if (!sito[i]) {
			p.pb(i);
			for (int j = i; j <= 5000; j += i)
				sito[j] = 1;
		}
	
	
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a);
		if(a == 0) a = 1;
		v[a].d++;
	}
	for (int i = 1; i <= 5000; ++i) {
		for (auto it : p) {
			int g = it;
			int w = 0;
			if(i < it) break;
			while (g <= i) {
				w += i / g;
				g *= it;
			}
			ans += 1LL * v[i].d * w;
			if (w) v[i].pr.pb({it, w});
		}
	}
	int L = 2;
	int R = 5000;
	while (true) {
		int best = 0;
		int LL = 0;
		int RR = 0;
		for (int i = L; i <= R;) {
			if (ss(v[i].pr) == 0) {
				i++;
				continue;
			}
			int j = i;
			int ile = 0;
			while(j <= R && v[i].pr.back().fi == v[j].pr.back().fi) {
				assert(ss(v[j].pr) > 0);
				ile += v[j].d;
				j++;
			}
			if(best < ile) {
				best = ile;
				LL = i;
				RR = j - 1;
			}
			assert(i < j);
			i = j;
		}
		
		if (best == 0) break;
		if (2 * best <= n) break;
		
		for (int i = LL; i <= RR; ++i) {
			v[i].pr.back().se--;
			if(v[i].pr.back().se == 0)
				v[i].pr.pop_back();
		}
		
		L = LL;
		R = RR;
		ans += n - 2 * best;
	}
	printf ("%lld", ans);
		
		
		
		
	
	
	
	return 0;
}