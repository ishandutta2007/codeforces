#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int B = 16;
struct Bitset{
	unsigned ll x[B];
	bool operator [] (int i) { return x[i >> 6] >> (i & 63) & 1; }

	Bitset operator & (const Bitset &o) const{
		Bitset res;
		for(int i = 0; i < B; ++i) res.x[i] = x[i] & o.x[i];
		return res;
	}

	void set(int i){
		x[i >> 6] |= 1ULL << (i & 63);
	}

	int count(){
		int res = 0;
		for(int i = 0; i < B; ++i)
			res += __builtin_popcountll(x[i]);
		return res;
	}

	pair<int, int> gettwo(){
		int pre = -1;
		for(int i = 0; i < B; ++i)
			if(x[i]){
				for(int j = 0; j < 64; ++j)
					if(x[i] >> j & 1){
						if(pre == -1) pre = (i << 6) | j;
						else return mkp(pre, (i << 6) | j);
					}
			}
		return mkp(-1, -1);
	}
};
const int maxn = 1000;
int n;
Bitset b[maxn];
int du[maxn];
bool a[maxn][maxn], bb[maxn][maxn];
int cnt[maxn];

int main(){
	//reopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	bool star_flag = 1;
	for(int i = 0; i < n; ++i){
		scanf("%d", cnt + i);
		if(cnt[i] != n) star_flag = 0;
		for(int j = 0; j < cnt[i]; ++j){
			static int x;
			scanf("%d", &x); 
			x--;
			b[i].set(x);
			bb[i][x] = 1;
		}
	}
	if(star_flag){
		for(int i = 2; i <= n; ++i) printf("%d %d\n", 1, i);
		return 0;
	}

	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j){
			Bitset t = b[i] & b[j];
			if(t.count() == 2){
				auto p = t.gettwo();
				if(p.fi == -1) { printf("fuck\n"); return 0; }
				a[p.fi][p.se] = a[p.se][p.fi] = 1;
			}
		}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			du[i] += a[i][j];
		}
	}

	for(int i = 0; i < n; ++i){
		if(du[i]) continue;
		int t = -1;
		for(int j = 0; j < n; ++j)
			if(bb[j][i] && (t == -1 || cnt[j] < cnt[t])) t = j;

		vector<int> v;
		for(int j = 0; j < n; ++j)
			if(bb[t][j] && du[j]){
				v.pb(j);
			}
		if(v.size() > 2){
			int m = v.size();
			for(int j = 0; j < m; ++j){
				int k = 0;
				while(k < m && (k == j || a[v[j]][v[k]])) ++k;
				if(k == m){
					a[v[j]][i] = a[i][v[j]] = 1;
					break;
				}
			}
		}else{
			if(v.size() < 2) { printf("shit\n"); return 0; }
			if(du[v[0]] > 1 || du[v[1]] > 1){
				int x = du[v[0]] > 1 ? v[1] : v[0];
				a[x][i] = a[i][x] = 1;
			}else{
				int j;
				for(j = 0; j < n; ++j)
					if(a[v[0]][j] && j != v[1]){
						if(bb[t][j])
							a[v[0]][i] = a[i][v[0]] = 1;
						else
							a[v[1]][i] = a[i][v[1]] = 1;
						break;
					}
				if(j == n) a[v[0]][i] = a[i][v[0]] = 1;
			}
		}
	}
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < i; ++j)
			if(a[i][j]) printf("%d %d\n", i + 1, j + 1);
	
	return 0;
}