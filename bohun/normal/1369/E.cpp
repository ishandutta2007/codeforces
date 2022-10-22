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

const int N = 1e6 + 10;
const int T = 1 << 17;

int n, m, w[N], x[N], y[N], cnt[N];
vector <int> v[N], S;
bool odw[N], byl[N];

void add(int x) {
	if (byl[x]) return;
	S.pb(x);
	byl[x] = 1;
}

int main() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, n) scanf ("%d", w + i);
	rep(i, 1, m) {
		scanf ("%d%d", x + i, y + i);
		v[x[i]].pb(i);
		v[y[i]].pb(i);
		cnt[x[i]]++; cnt[y[i]]++;
	}
	rep(i, 1, n)
		if (w[i] >= cnt[i])
			add(i);
	vector <int> ans;
	while (ss(ans) < m) {
		if (S.empty()) {
			printf ("DEAD\n");
			return 0;
		}
		int C = S.back();
		S.pop_back();
		for (auto it : v[C]) {
			if (!odw[it]) {
				ans.pb(it);
				cnt[x[it]]--;
				cnt[y[it]]--;
				if (w[x[it]] >= cnt[x[it]])
					add(x[it]);
				if (w[y[it]] >= cnt[y[it]])
					add(y[it]);
				odw[it] = 1;
			}	
		}
	}
	reverse(all(ans));
	printf ("ALIVE\n");
	for (auto it : ans) printf ("%d ", it);
		
				
		
		
	
	
	return 0;
}