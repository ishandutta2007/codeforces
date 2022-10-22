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
const int pier = 450;
const int D = nax / pier + 11;

int n;
int a[nax];
int q, type, b, c;
vector <int> block[D];
int siz[D];
int ile[D][nax];
int val = -1;

void del(int pos) {
	int ind = 0;
	while(true) {
		if(siz[ind] < pos)
			pos -= siz[ind];
		else {
			pos -= 1;
			val = block[ind][pos];
			block[ind].erase(block[ind].begin() + pos);
			ile[ind][val] -= 1;
			siz[ind] -= 1;
			return;
		}
		ind += 1;
	}
}

void add(int pos) {
	int ind = 0;
	while(true) {
		if(siz[ind] < pos)
			pos -= siz[ind];
		else {
			block[ind].insert(block[ind].begin() + pos, val);
			ile[ind][val] += 1;
			siz[ind] += 1;
			return;
		}
		ind += 1;
	}
}
			
int daj(int pos, int x) {
	int res = 0;
	int ind = 0;
	while(true) {
		if(siz[ind] < pos) {
			res += ile[ind][x];
			pos -= siz[ind];
		}
		else {
			FOR(i, 0, pos - 1)
				res += (block[ind][i] == x);
			return res;
		}
		ind += 1;
	}
	return res;
}

vector <int> ele;

void rebuild() {
	ele.clear();
	FOR(i, 0, n / pier)	{
		for(auto it : block[i])
			ele.pb(it);
		siz[i] = 0;
		FOR(j, 1, n)
			ile[i][j] = 0;
		block[i].clear();
	}
	assert(ss(ele) == n);
	FOR(i, 0, n - 1) {
		siz[i / pier] += 1;
		block[i / pier].pb(ele[i]);
		ile[i / pier][ele[i]] += 1;
	}
}
	

int main() {
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d", &a[i]);
		siz[i / pier] += 1;
		block[i / pier].pb(a[i]);
		ile[i / pier][a[i]] += 1;
	}
	scanf("%d", &q);
	int last = 0;
	while(q--) {
		scanf("%d %d %d", &type, &b, &c);
		b = (b + last - 1) % n + 1;
		c = (c + last - 1) % n + 1;
		if(b > c)
			swap(b, c);
		if(type == 1) {
			del(c);
			add(b - 1);
		}
		else {
			int k;
			scanf("%d", &k);
			k = (k + last - 1) % n + 1;
			last = daj(c, k) - daj(b - 1, k);
			printf("%d\n", last);
		}
		if(q % pier == 0) 
			rebuild();
	}
	
	return 0;
}