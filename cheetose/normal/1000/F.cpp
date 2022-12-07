#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define x first
#define y second

const int N = 500 * 1000 + 13;
const int P = 800;
const int INF = 1e9;

bool comp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b){
	int num = a.x.x / P;
	if (num != b.x.x / P)
		return a.x.x < b.x.x;
	if (num & 1)
		return a.x.y < b.x.y;
	return a.x.y > b.x.y;
}

int val[N];
int cnt[N];
int bl[P];
int tot;

inline void add(int x){
	++cnt[x];
	if (cnt[x] == 1){
		++val[x];
		++bl[x / P];
		++tot;
	}
	else if (cnt[x] == 2){
		--val[x];
		--bl[x / P];
		--tot;
	}
}

inline void sub(int x){
	--cnt[x];
	if (cnt[x] == 1){
		++val[x];
		++bl[x / P];
		++tot;
	}
	else if (cnt[x] == 0){
		--val[x];
		--bl[x / P];
		--tot;
	}
}

int get(){
	if (tot == 0) 
		return 0;
	
	forn(i, P){
		if (bl[i] > 0){
			for (int j = i * P;; ++j){
				if (val[j]){
					return j;
				}
			}
		}
	}
	
	assert(false);
}

int n, m;
int a[N], ans[N];
pair<pair<int, int>, int> q[N];

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]);
	scanf("%d", &m);
	forn(i, m){
		scanf("%d%d", &q[i].x.x, &q[i].x.y);
		--q[i].x.x, --q[i].x.y;
		q[i].y = i;
	}
	sort(q, q + m, comp);
	
	int l = 0, r = -1;
	
	forn(i, m){
		int L = q[i].x.x;
		int R = q[i].x.y;
		
		while (r < R){
			++r;
			add(a[r]);
		}
		
		while (r > R){
			sub(a[r]);
			--r;
		}
		
		while (l > L){
			--l;
			add(a[l]);
		}
		
		while (l < L){
			sub(a[l]);
			++l;
		}
		
		ans[q[i].y] = get();
	}
	
	forn(i, m)
		printf("%d\n", ans[i]);
	
	return 0;
}