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

int n, m, q, a, b;
char s[nax][12];
int t[nax][12];
int L[nax][12];
int R[nax][12];
int sum[nax][12][2];
int id[nax];
int Left[nax];
int Right[nax];
pair<int, int> go[nax][12];

map <char, int> mapa;

//////// 0 - lewo , 1 - prawo, 2 - gora

bool bad(int r, int w) {
	if(r <= 0)
		return 1;
	if(w == 0 || w == m + 1)
		return 1;
	return 0;
}

int daj(int row, int l, int r, int type) {
	int res = sum[row][r][type];
	if(l)
		res -= sum[row][l - 1][type];
	return res;
}

void rebuild(int block) {
	for(int i = Left[block]; i <= Right[block]; ++i) {
		
		int Last = 0;
		for(int j = 0; j <= m + 1; ++j) {
			L[i][j] = Last;
			if(j) {
				for(int g = 0; g < 2; ++g)
					sum[i][j][g] = sum[i][j - 1][g];
			}
			if(t[i][j] <= 1)
				sum[i][j][t[i][j]] += 1;
			else
				Last = j;
		}
		
		Last = m + 1;
		for(int j = m + 1; 0 <= j; --j) {
			R[i][j] = Last;
			if(t[i][j] == 2)
				Last = j;
		}
		
		go[i][0] = mp(i, 0);
		go[i][m + 1] = mp(i, m + 1);
		
		for(int j = 1; j <= m; ++j) {
			if(t[i][j] == 2) {
				if(i == Left[block])
					go[i][j] = mp(i - 1, j);
				else
					go[i][j] = go[i - 1][j];
			}
			if(t[i][j] == 0) {
				int e = L[i][j];
				if(daj(i, e, j, 1) > 0)
					go[i][j] = mp(-1, -1);
				else
					go[i][j] = go[i][e];
			}
			if(t[i][j] == 1) {
				int e = R[i][j];
				if(daj(i, j, e, 0) > 0)
					go[i][j] = mp(-1, -1);
				else {
					if(i == Left[block] && e <= m)
						go[i][j] = mp(i - 1, e);
					else if(e != m + 1)
						go[i][j] = go[i - 1][e];
					else
						go[i][j] = mp(i, m + 1);
				}
			}
		}
	}
}
					
void solve(int row, int col) {
	while(!bad(row, col)) {
		int rr = go[row][col].fi;
		int cc = go[row][col].se;
		row = rr;
		col = cc;
	}
	printf("%d %d\n", row, col);
}
		

int main() {
	mapa['<'] = 0;
	mapa['>'] = 1;
	mapa['^'] = 2;
	scanf("%d %d %d", &n, &m, &q);
	FOR(i, 0, n / P) {
		Left[i] = n + 1;
		Right[i] = -1;
	}
	FOR(i, 1, n) {
		t[i][0] = t[i][m + 1] = 2;
		scanf("%s", s[i] + 1);
		FOR(j, 1, m) 
			t[i][j] = mapa[s[i][j]];
		id[i] = i / P;
		Left[id[i]] = min(Left[id[i]], i);
		Right[id[i]] = max(Right[id[i]], i);
	}
	
	FOR(i, 0, n / P)
		rebuild(i);
	
	while(q--) {
		char c;
		scanf(" %c", &c);
		scanf("%d %d", &a, &b);
		if(c == 'A')	
			solve(a, b);
		else {
			scanf(" %c", &c);
			t[a][b] = mapa[c];
			rebuild(a / P);
		}
	}
		
	
	
	return 0;
}