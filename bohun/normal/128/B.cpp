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
// Robal
// Jaki wielki jest Tytus Grodzicki
// Nie boi si.
// ~ Marcin Tytus Martowicz Bohun Grodzicki znachor
// Och Kaaaaarol <3



#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define DOW(i, n) for(int i = n - 1; 0 <= i; --i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;


const int nax = 1e5 + 111;
const int LOG = 16;

struct tablicasuf {
	char s[nax]; // od 1 :)	
	int kmr[nax];
	int sa[nax];
	int lcp[nax];
	pair<pair<int,int>,int> h[nax];
	int t[nax][LOG + 1];
	int L[nax];
	int R[nax];
	
	void make() {
		int n = strlen(s + 1);
		for(int i = 1; i <= n; ++i) kmr[i] = s[i] - 'a';
		int pot = 1;
		while(true) {
			for(int i = 1; i <= n; ++i) 
				h[i] = (i + pot <= n ? mp(mp(kmr[i], kmr[i + pot]), i) : mp(mp(kmr[i], -1), i));
			sort(h + 1, h + n + 1);
			pair<int, int> last = mp(-2, 0);
			int id = 0;
			for(int i = 1; i <= n; ++i) {
				if(last != h[i].fi) id++;
				kmr[h[i].se] = id;
				last = h[i].fi;
			}
			if(id == n) break;
			pot *= 2;
		}
		for(int i = 1; i <= n; ++i)
			sa[kmr[i]] = i;
		int k = 0;
		for(int i = 1; i <= n; ++i) {
			if(kmr[i] == n) continue;
			int id = sa[kmr[i] + 1];
			while(i + k <= n && id + k <= n && s[i + k] == s[id + k]) ++k;
			lcp[kmr[i]] = k;
			k = max(0, k - 1);
		}
		for(int i = 1; i <= n; ++i)
			t[i][0] = lcp[i];
		for(int j = 1; j <= LOG; ++j)
			for(int i = 1; i + (1 << (j - 1)) <= n; ++i)
				t[i][j] = min(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
	}
	
	void poka() {
		int n = strlen(s + 1);
		for(int i = 1; i <= n; ++i) {
			cout << i << " " << lcp[i] << endl;
			for(int j = sa[i]; j <= n; ++j)
				cout << s[j];
			cout << endl;
		}
	}
	
	int query(int l, int r) {
		if(l > r) swap(l, r);		
		if(l == r) return strlen(s + 1) - sa[l] + 1;
		int k = 0;
		while((1 << (k + 1)) <= r - l) k++;
		return min(t[l][k], t[r - (1 << k)][k]);
	} 
	
	void borders() { // jesli lcp = 0, to [1..N]
		int n = strlen(s + 1);
		for(int i = 1; i <= n; ++i) {
			int l = i;
			int r = n;
			while(l < r) {
				int m = (l + r + 1) / 2;
				if(lcp[i] <= query(i, m)) l = m;
				else r = m - 1;
			}
			R[i] = l;
			l = 1;
			r = i;
			while(l < r) {
				int m = (l + r) / 2;
				if(lcp[i] <= query(m, i)) r = m;
				else l = m + 1;
			}
			L[i] = l;
		}
	}	
} p;

int main() {
	//boost;
	scanf("%s", p.s + 1);
	p.make();
	p.borders();
	//p.poka();
	int KAROL = 0;
	int k;
	cin >> k;
	int n = strlen(p.s + 1);
	if(k > 1ll * n * (n + 1) / 2) {
		printf("No such line.\n");
		return 0;
	}
	for(int i = 1; i <= n; ++i) {
		int LCP = p.lcp[i];
		int L = KAROL + 1;
		for(int j = L; j <= LCP; ++j) {
			int le = i;
			int ri = n;
			while(le < ri) {
				int mi = (le + ri + 1) / 2;
				if(p.query(i, mi) >= j)
					le = mi;
				else
					ri = mi - 1;
			}
			k -= (ri - i + 1);
			//cout << i << " " << j << " " << ri << " " << p.query(i, i + 1) << endl;
			if(k <= 0) {
				for(int c = p.sa[i]; c < p.sa[i] + j; ++c)
					cout << p.s[c];
				return 0;
			}
		}
		
		int TYTUS = n - p.sa[i] + 1 - max(KAROL, LCP);
		if(k <= TYTUS) {
			for(int j = p.sa[i]; j < p.sa[i] + max(KAROL, LCP) + k; ++j) {
				cout << p.s[j];
			}
			return 0;
		}
		else {
			k -= TYTUS;
		}
		KAROL = LCP;
		//cout << i << " " << k << " " << KAROL << endl;
	}
	return 0;
}