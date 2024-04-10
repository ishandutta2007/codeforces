#include <bits/stdc++.h>

using namespace std; 

typedef pair<int, int> pii; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline void tense(T &x, const T &y) {
	if (x > y) x = y; 
}

template <class T>
inline void relax(T &x, const T &y) {
	if (x < y) x = y; 
}

const int MaxN = 400000 + 5; 
const int dx[4] = {-1, 1, 0, 0}; 
const int dy[4] = {0, 0, -1, 1}; 

int n, m, a[MaxN]; 
int nV; 

pii idx[MaxN]; 
vector<bool> c[MaxN]; 
vector<int> p[MaxN], pos[MaxN]; 

bool isKey[MaxN]; 
vector<int> adjG[MaxN], adjD[MaxN]; 

int dfsClock, dfn[MaxN], low[MaxN]; 
int stkTop, stk[MaxN]; 

int nS, scc[MaxN]; 
int sccTag[MaxN], ind[MaxN]; 

void dfsTarjan(int u) {
	stk[++stkTop] = u; 
	dfn[u] = low[u] = ++dfsClock; 

	for (int v : adjG[u])
		if (!dfn[v]) {
			dfsTarjan(v); 
			tense(low[u], low[v]); 
		} else if (!scc[v]) {
			tense(low[u], dfn[v]); 
		}
	
	if (dfn[u] == low[u]) {
		++nS; 
		do {
			int v = stk[stkTop--]; 
			scc[v] = nS; 

			// cerr << nS << ':' << v << ':' << idx[v].first << ' ' << idx[v].second << '\n'; //

			if (isKey[v]) sccTag[nS] = v; 

			for (int w : adjG[v])
				if (scc[w] && scc[w] != nS) {
					++ind[scc[w]]; 
					adjD[nS].push_back(scc[w]); 
				}
		} while (stk[stkTop + 1] != u); 
	}
}

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	scanf("%d%d", &m, &n); 

	for (int i = 1; i <= n; ++i) {
		c[i] = vector<bool>(m + 2); 
		pos[i] = vector<int>(m + 2); 
	}

	for (int i = m; i >= 1; --i) {
		static char s[MaxN]; 
		scanf("%s", s + 1); 

		for (int j = 1; j <= n; ++j) {
			c[j][i] = s[j] == '#'; 
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (c[i][j]) {
				p[i].push_back(j); 
				idx[pos[i][j] = ++nV] = make_pair(i, j); 
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		read(a[i]); 

		for (int j = 0, pL = 0, pR = 0; j < (int)p[i].size(); ++j) {
			int u = pos[i][p[i][j]]; 

			if (j) adjG[u].push_back(pos[i][p[i][j - 1]]); 

			while (pL < (int)p[i - 1].size() && p[i - 1][pL] <= p[i][j]) {
				adjG[u].push_back(pos[i - 1][p[i - 1][pL]]); 
				++pL; 
			}
			while (pR < (int)p[i + 1].size() && p[i + 1][pR] <= p[i][j]) {
				adjG[u].push_back(pos[i + 1][p[i + 1][pR]]); 
				++pR; 
			}

			if (j < (int)p[i].size() - 1 && c[i][p[i][j] + 1]) {
				adjG[u].push_back(pos[i][p[i][j + 1]]); 
			}

			if (j == a[i] - 1) {
				isKey[u] = true; 
			}
		}
	}

	for (int u = 1; u <= nV; ++u)
		if (!dfn[u]) dfsTarjan(u); 

	static int hasTag[MaxN]; 
	static bool used[MaxN]; 

	for (int u = nS; u >= 1; --u) {
		if (hasTag[u]) {
			sccTag[u] = 0; 
		} else {
			used[sccTag[u]] = true; 
		}

		for (int v : adjD[u])
			hasTag[v] |= hasTag[u] || sccTag[u]; 
	}

	static int tagmin[MaxN], tagmax[MaxN]; 	
	static vector<int> endpos[MaxN]; 

	for (int u = 1; u <= nS; ++u) {
		tagmin[u] = sccTag[u] ? sccTag[u] : nV + 1; 
		tagmax[u] = sccTag[u] ? sccTag[u] : 0; 

		for (int v : adjD[u]) {
			tense(tagmin[u], tagmin[v]); 
			relax(tagmax[u], tagmax[v]); 
		}

		if (!ind[u])
			endpos[tagmin[u]].push_back(tagmax[u]); 
	}

	static priority_queue<int> heap; 
	int ans = 0; 

	for (int i = 1, cur = 0; i <= nV; ++i) {
		for (int r : endpos[i])
			heap.push(r); 
		
		if (used[i] && cur < i) {
			++ans; 
			cur = heap.top(); 
			heap.pop(); 
		}
	}

	cout << ans << '\n'; 

	return 0; 
}