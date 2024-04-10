#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


const int N = 1005;
int a[N][N],n,m;
int g[N][N],sz[N];
unordered_set<int> S;
int e[N*N],s[N*N],ss;

bool test(int v) {
	S.clear();
	for(int i = 0; i < n; ++i) {
		sz[i] = 0;
		for(int j = 0; j < m; ++j) {
			if(a[i][j] >= v) {
				g[i][sz[i]++] = j;
			}
		}
	}
	bool found = false;
	ss=0;
	for(int r = 0; r < n; ++r) {
		for(int a = 1; a < sz[r]; ++a) {
			for(int b = 0; b < a; ++b) {
				int h = g[r][b]*max(n,m)+g[r][a];
				if(e[h]) {
					found = true;
					goto skp;
				}
				s[ss++] = h;
				e[h] = true;
			}
		}
	}
	skp:;
	for(int i = 0; i < ss; ++i)
		e[s[i]] = false;
	return found;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d",a[i]+j);
		}
	}
	int lo = 0, hi = 1e9+1;
	while(hi-lo > 1) {
		int md = (1LL*lo+hi)/2;
		if(test(md)) lo = md;
		else hi = md;
	}
	printf("%d\n",lo);
	return 0;
}