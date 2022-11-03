#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

const int magic = 505;

struct vert{
	int pred, r;
};

struct cnm{
	vert t[101];
	cnm() { for (int i = 0; i < 101; i++) t[i].pred = i, t[i].r = 0; }
	void clear() { for (int i = 0; i < 101; i++) t[i].pred = i, t[i].r = 0; }

	int get(int v){
		if (t[v].pred == v) return v;
		t[v].pred = get(t[v].pred);
		return t[v].pred;
	}

	void merge(int a, int b){
		a = get(a); b = get(b);
		if (a != b){
			if (t[a].r < t[b].r) swap(a, b);
			t[b].pred = a;
			if (t[a].r == t[b].r) t[a].r++;
		}
	}
} cc[505];

int uk[505][101];
int n;
int a[200007];

int to[101];
void update(int v){
	for (int i = 1; i <= 100; i++) to[i] = -1;
	for (int i = 1; i <= 100; i++) if (uk[v][i] != -1) uk[v][i] = cc[v].get(uk[v][i]), to[uk[v][i]] = i;
	int l = v * magic;
	int r = min(n - 1, (v + 1) * magic - 1);
	for (int i = l; i <= r; i++){
		a[i] = to[cc[v].get(a[i])];
	}
	for (int i = 1; i <= 100; i++) uk[v][i] = i;
	cc[v].clear();
}

void up(int l, int r, int x, int y){
	bool f = 0;
	for (int i = l; i <= r; ){
		int v = i / magic;
		if (i != l && v != ((i - 1) / magic)) f = 0;
		if (i % magic == 0 && i + magic - 1 <= r){
			if (uk[v][x] != -1){
				if (uk[v][y] == -1) uk[v][y] = uk[v][x];
				else {
					cc[v].merge(uk[v][x], uk[v][y]);
				}
				uk[v][x] = -1;
			}
			i += magic;
			f = 0;
		} else {
			if (!f) update(v), f = 1;
			if (a[i] == x) a[i] = y;
			i++;
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < 505; i++) for (int j = 1; j <= 100; j++) uk[i][j] = j;
	int m;
	cin >> m;
	while(m--){
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		l--, r--;
		if (x == y) continue;
		up(l, r, x, y);
	}
	for (int i = 0; i < 505; i++) update(i);
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
}