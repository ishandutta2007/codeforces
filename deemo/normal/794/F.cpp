#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int LOG = 10;

int n, q, a[MAXN];
ll weed[MAXN*4][LOG];
int nut[MAXN*4][LOG], gg[1<<LOG];
bool changed[MAXN*4];

void plant(int v, int b, int e){
	for (int w = 0; w < LOG; w++)
		nut[v][w] = 1<<w;
	if (e - b == 1){
		int cur = 1;
		while (a[b]){
			int x = a[b]%10;
			weed[v][x] += cur;
			a[b] /= 10;
			cur *= 10;
		}
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	for (int w = 0; w < LOG; w++)
		weed[v][w] = weed[v<<1][w] + weed[v<<1^1][w];
}

ll temp[2][LOG];
int t2[2][LOG];
void absorb(int v){
	if (!changed[v]) return;
	memset(temp, 0, sizeof(temp));
	memset(t2, 0, sizeof(t2));
	
	for (int w = 0; w < LOG; w++)
		while (nut[v][w]){
			int x = gg[nut[v][w]];
			nut[v][w] ^= 1<<x;
		
			temp[0][w] += weed[v<<1][x];
			temp[1][w] += weed[v<<1^1][x];

			t2[0][w] |= nut[v<<1][x];
			t2[1][w] |= nut[v<<1^1][x];
		}
	changed[v<<1] = changed[v<<1^1] = 1;

	for (int w = 0; w < LOG; w++){
		nut[v<<1][w] = t2[0][w];
		nut[v<<1^1][w] = t2[1][w];
		weed[v<<1][w] = temp[0][w];
		weed[v<<1^1][w] = temp[1][w];
	}
	for (int w = 0; w < LOG; w++)
		nut[v][w] = 1<<w;
	changed[v] = 0;
}

void water(int v, int b, int e, int l, int r, int x, int y){
	if (l <= b && e <= r){
		weed[v][y] += weed[v][x];
		weed[v][x] = 0;
		nut[v][y] |= nut[v][x];
		nut[v][x] = 0;
		changed[v] = 1;
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	absorb(v);
	water(v<<1, b, mid, l, r, x, y);
	water(v<<1^1, mid, e, l, r, x, y);
	for (int w = 0; w < LOG; w++)
		weed[v][w] = weed[v<<1][w] + weed[v<<1^1][w];
}

ll smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r){
		ll ret = 0;
		for (int w = 1; w < LOG; w++)
			ret += 1ll*w*weed[v][w];
		return ret;
	}
	if (r <= b || e <= l) return 0ll;

	int mid = b + e >> 1;
	absorb(v);
	return smoke(v<<1, b, mid, l, r) + smoke(v<<1^1, mid, e, l, r);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++)	cin >> a[i];
	plant(1, 0, n);

	for (int i = 0; i < 1<<LOG; i++)
		gg[i] = __builtin_ctz(i);

	while (q--){
		int t, l, r;
		cin >> t >> l >> r, l--;
		if (t == 1){
			int x, y;	cin >> x >> y;
			if (x ^ y)
				water(1, 0, n, l, r, x, y);
		}
		else
			cout << smoke(1, 0, n, l, r) << "\n";
	}
	return 0;
}