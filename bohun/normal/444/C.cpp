#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
 
using namespace std;

const int nax = 1e5 + 111;
const int P = 400;

int n, m;
int col[nax];
int type, l, r, x;
int id[nax];
ll sum[nax], kub[nax], jo[nax]; 
int L[nax], R[nax], COL[nax];
bool ok[nax];

int Lastkub[nax];
int Lastjo[nax];
int timer = 1;

void brut(int l, int r, int k) {
	FOR(i, l, r) {
		if(Lastjo[i] < Lastkub[i / P])
			col[i] = COL[i / P];
		sum[i] += abs(k - col[i]);
		kub[id[l]] += abs(k - col[i]);
		col[i] = k;
		Lastjo[i] = timer;
	}
}

void op(int nr, int k) {
	Lastkub[nr] = timer;
	kub[nr] += (ll) abs(k - COL[nr]) * (R[nr] - L[nr] + 1);
	jo[nr] += abs(k - COL[nr]);
}
	

void mal(int l, int r, int k) {
	if(id[l] == id[r]) {
		brut(l, r, k);
		ok[l / P] = 0;
		return;
	}
	int x = l;
	int y = r;
	brut(L[id[y]], y, k);
	ok[id[y]] = 0;
	brut(x, R[id[x]], k);
	ok[id[x]] = 0;
	x = R[id[x]] + 1;
	y = L[id[y]] - 1;
	for(int i = x / P; i <= y / P; ++i) {
		if(ok[i]) {
			op(i, k);
			ok[i] = 1;
			COL[i] = k;
		}
		else {
			brut(L[i], R[i], k);
			ok[i] = 1;
			COL[i] = k;
		}
	}
}
			
void solve(int l, int r) {
	ll suma = 0;
	int x = l;
	int y = r;
	if(id[x] == id[y]) {
		FOR(i, x, y)
			suma += jo[id[i]] + sum[i];
		printf("%lld\n", suma);
		return;
	}
	while(id[x] == id[l]) {
		suma += jo[id[x]] + sum[x];
		x += 1;
	}
	while(id[y] == id[r]) {
		suma += jo[id[y]] + sum[y];
		y -= 1;
	}
	x = id[x];
	y = id[y];
	FOR(i, x, y) {
		suma += kub[i];
	}
	printf("%lld\n", suma);
}
	

int main() {	
	scanf("%d %d", &n, &m);
	FOR(i, 0, nax - 1) {
		L[i] = n + 1;
		R[i] = -1;
	}
	FOR(i, 1, n) {
		col[i] = i;
		id[i] = i / P;
		R[id[i]] = max(i, R[id[i]]);
		L[id[i]] = min(i, L[id[i]]);
	}
	FOR(i, 1, m) {
		scanf("%d %d %d", &type, &l, &r);
		if(type == 1) {
			scanf("%d", &x);
			mal(l, r, x);
		}
		else {
			solve(l, r);
		}
		timer += 1;
	}		
	
	return 0;
}