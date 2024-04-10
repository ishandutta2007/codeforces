#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const ll mod = int(1e9) + 7;
const int ma = 1024 * 1024;

int n, is_cntr[300000], szk[20][300000], cntp[1 << 20], cntp1[1 << 20], cv[1 << 20];
ll ans[300000]; 
vector<int> e[300000];
char s[300000];

void dfs(int nu, int pr, int i) {
	szk[i][nu] = 1;
	for (int v : e[nu]) {
		if (is_cntr[v] == 0 && v != pr) {
			dfs(v, nu, i);
			szk[i][nu] += szk[i][v];
		}
	}
}

void dfs1(int nu, int pr, int &cntr, int i, int n) {
	bool ok = true;
	for (int v : e[nu]) {
		if (is_cntr[v] == 0 && v != pr) {
			dfs1(v, nu, cntr, i, n);
			if (2 * szk[i][v] > n)
				ok = false;
		}
	}
	if (2 * (n - szk[i][nu]) > n) ok = false;
	if (ok) cntr = nu;
}

ll dfs2(int nu, int pr, int msk) {
	msk ^= (1 << (s[nu] - 'a'));
	//cout << nu << " " << pr << " " << msk << "\n";
	ll cpk = 0;
	if (cv[msk] <= 1) {
		cpk++;
	}
	for (int v : e[nu]) {
		if (v != pr && is_cntr[v] == 0) {
			cpk += dfs2(v, nu, msk);
		}
	}
	ans[nu] += cpk;
	if (nu != pr) {
		cntp[msk]++;
	}
	re cpk;
}


void dfs5(int nu, int pr, int msk) {
	msk ^= (1 << (s[nu] - 'a'));
	for (int v : e[nu]) {
		if (v != pr && is_cntr[v] == 0) {
			dfs5(v, nu, msk);
		}
	}
	if (nu != pr) {
		cntp[msk]--;
	}
	re;
}

void dfs3(int nu, int pr, int msk, int del) {
	msk ^= (1 << (s[nu] - 'a'));
	for (int v : e[nu]) {
		if (v != pr && is_cntr[v] == 0) {
			dfs3(v, nu, msk, del);
		}
	}
	cntp1[msk] += del;
	re;	
}

ll dfs4(int nu, int pr, int msk) {
	msk ^= (1 << (s[nu] - 'a'));
	ll ck = cntp[msk] - cntp1[msk];
	forn (i, 20) 
		ck += ll(cntp[msk ^ (1 << i)] - cntp1[msk ^ (1 << i)]);
	for (int v : e[nu]) {
		if (v != pr && is_cntr[v] == 0) {
			ck += dfs4(v, nu, msk);
		}
	}
	ans[nu] += ck;
	re ck;  
}

void centroid(int nu, int cp) {
	dfs(nu, nu, cp);
	int num = -1;
	dfs1(nu, nu, num, cp, szk[cp][nu]);
	//cout << nu << " " << num << " " << cp << "\n";
	nu = num;
	dfs2(num, num, 0);
	//forn (i, n) 
	//	cout << ans[i] << " ";
	//cout << "\n";
	is_cntr[num] = 1;
	ll sm = 0;
	for (int v : e[num]) {
		if (is_cntr[v] == 0) {
			dfs3(v, v, (1 << (s[num] - 'a')), 1);
			sm += dfs4(v, v, 0);
			dfs3(v, v, (1 << (s[num] - 'a')), -1);
		}
	}
	assert(sm % 2 == 0);
	ans[num] += sm / 2LL;
	is_cntr[num] = 0;
	dfs5(num, num, 0);
	is_cntr[num] = 1;
	for (int v : e[num]) {
		if (is_cntr[v] == 0)
			centroid(v, cp + 1);
	}
}

int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	scanf("%d", &n);
	//cin >> n;
	forn (i, (1 << 20)) {
		if (i % 2)
			cv[i] = 1 + cv[i / 2];
		else
			cv[i] = cv[i / 2];
	}
	forn (i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		e[a].push_back(b);
		e[b].push_back(a);
		//cin >> a 
	}
	scanf("%s", s);
	centroid(0, 0);
	forn (i, n) {
		printf("%I64d ", ans[i]);
	}
}