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

const int nax = 1e5 + 5, pod = (1 << 17), inf = 1e9 + 5, ile = 6000000;

int n, k;
int t[nax];
int last, a, b;

int fre = 1;
int root[ile], l[ile], r[ile], s[ile];
vector <int> pos[nax];

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
		s[ja]++;
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

int Daj(int x, int y, int u, int le = 0, int pr = pod - 1) {
	if(y >= pr && le >= x) {
		return s[u];
	}
	int mid = (le + pr) / 2;
	int res = 0;
	if(x <= mid)
		res += Daj(x, y, l[u], le, mid);
	if(y > mid)
		res += Daj(x, y, r[u], mid + 1, pr);
	return res;
}


int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> k;
	Build();
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
		pos[t[i]].pb(i);
		int x = ss(pos[t[i]]);
		if(x > k)
			root[i] = Add(pos[t[i]][x - k - 1], root[i - 1]); 
		else
			root[i] = root[i - 1];
	}
	
	int q;
	cin >> q;
	while(q--) {
		cin >> a >> b;
		a = (a + last) % n + 1;
		b = (b + last) % n + 1;
		if(a > b)
			swap(a, b);
		last = b - a + 1 - Daj(a, b, root[b]);
		cout << last << endl;
	}
	
	
		
	
		
	
    return 0;
}