#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 4e5 + 5, pod = (1 << 19), inf = 1e9 + 5, ile = 10000000;

struct Sufiks{
	int kmr[nax];
	pair<pair<int, int>, int> help[nax];
	char s[nax];
	int sa[nax]; // k-ty sufiks od 0
	int lcp[nax];
	int n;
	void init(int N)
	{
		n = N;
	}
	void Build()
	{
		for(int i = 1; n >= i; ++i)
		kmr[i] = s[i] - 'a' + 1;
		int pot = 1;
		while(true)
		{
			for(int i = 1; n >= i; ++i)
			{
				if(i + pot < n)
					help[i] = mp(mp(kmr[i], kmr[i + pot]), i);
				else
					help[i] = mp(mp(kmr[i], -1000), i);
			}
			sort(help + 1, help + n + 1);
			pair<int, int> last = mp(-2, -2);
			int id = 0;
			for(int i = 1; n >= i; ++i)
			{
				if(help[i].fi != last)
					++id;
				kmr[help[i].se] = id;
				last = help[i].fi;
			}
			if(id == n)
				break;
			pot *= 2;
		}
		for(int i = 1; n >= i; ++i)
			sa[kmr[i]] = i;
	}
	void Lcp()
	{
		int k = 0;
		for(int i = 1; n >= i; ++i)
		{
			if(kmr[i] == n)
				continue;
			int id = sa[kmr[i] + 1];
			while(i + k <= n && id + k <= n && s[i + k] == s[id + k])
				++k;
			lcp[kmr	[i]] = k;
			k = max(0, k - 1);
		}
	}
};

int fre = 1;
int root[ile], l[ile], r[ile], s[ile];

void Build(int x = 0, int le = 0, int pr = pod - 1) {
	if(le == pr)
		return;
	l[x] = fre++;
	r[x] = fre++;
	int mid = (le + pr) / 2;
	Build(l[x], le, mid);
	Build(r[x], mid + 1, pr);
}

int Add(int x, int id, int le = 0, int pr = pod - 1) {
	int ja = fre++;
	if(le == x && pr == x) {
		s[ja] = s[id] + 1;
		return ja;
	}
	int mid = (le + pr) / 2;
	l[ja] = l[id];
	r[ja] = r[id];
	if(x <= mid)
		l[ja] = Add(x, l[ja], le, mid);
	else
		r[ja] = Add(x, r[ja], mid + 1, pr);
	s[ja] = s[l[ja]] + s[r[ja]];
	return ja;
}

int Daj(int x, int y, int u, int u2, int le = 0, int pr = pod - 1) {
	if(y >= pr && le >= x) {
		return s[u] - s[u2];
	}
	int mid = (le + pr) / 2;
	int res = 0;
	if(x <= mid)
		res += Daj(x, y, l[u], l[u2], le, mid);
	if(y > mid)
		res += Daj(x, y, r[u], r[u2], mid + 1, pr);
	return res;
}

Sufiks slo;
int g = 0;
char c[nax];
int rodzaj[nax];

priority_queue <pair<int, int>> stak;
int lewo[nax], prawo[nax], rep[nax];
int dlu[nax];


int main() {
	
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	int n, q;
	scanf ("%d %d", &n, &q);
	g = 1;
	for(int i = 1; i <= n; ++i) {
		scanf ("%s", c);
		int len = strlen(c);
		for(int j = 0; j < len; ++j) {
			slo.s[g + j] = c[j];
			rodzaj[g + j] = i;
			dlu[g + j] = len;
		}
		rep[i] = g;
		g += len;
		slo.s[g] = '#';
		++g;
	}
	slo.init(strlen(slo.s + 1));
	slo.Build();
	slo.Lcp();
	Build();
	
	int L = strlen(slo.s + 1);
	for(int i = 1; i <= L; ++i) {
		//cout << "S :" << i << endl;
		//for(int j = slo.sa[i]; j <= L; ++j)
		//	cout << slo.s[j];
		//cout << endl;
		lewo[i] = prawo[i] = i;
	}
	//cout << endl << endl;
	for(int i = 1; i <= L; ++i) {
		stak.push(mp(dlu[slo.sa[i]], i));
		while(!stak.empty() && stak.top().fi > slo.lcp[i]) {
			prawo[stak.top().se] = i;
			stak.pop();
		}
	}
	while(!stak.empty()) {
		prawo[stak.top().se] = L;
		stak.pop();
	}
	for(int i = L; 1 <= i; --i) {
		while(!stak.empty() && stak.top().fi > slo.lcp[i]) {
			lewo[stak.top().se] = i + 1;
			stak.pop();
		}
		stak.push(mp(dlu[slo.sa[i]], i));
	}
	while(!stak.empty()) {
		lewo[stak.top().se] = 1;
		stak.pop();
	}
	
	for(int i = 1; i <= L; ++i) {
		//cout << i << " " << lewo[i] << " " << prawo[i] << endl;
		root[i] = Add(rodzaj[slo.sa[i]], root[i - 1]);
	}
	
	while(q--) {
		int a, b, c;
		scanf ("%d %d %d", &a, &b, &c);
		int LL = lewo[slo.kmr[rep[c]]];
		int RR = prawo[slo.kmr[rep[c]]];
		printf ("%d\n", Daj(a, b, root[RR], root[LL - 1]));
		//assert(fre < ile);
		
	}
	
		
	
	
	
		
	
		
	
    return 0;
}