#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 2e5 + 10;

int n, A, B, p[MAXN];
pii seg[2][MAXN << 2];
int dist[MAXN];

void plant(int v, int b, int e) {
    if (e - b == 1) {
        if (b == A) {
            seg[0][v] = {(int)-1e9, b};
            seg[1][v] = {(int)-1e9, b};
        } else {
            seg[0][v] = {p[b] - b, b};
            seg[1][v] = {p[b] + b, b};
        }
    } else {
        int mid = b + e >> 1;
        plant(v<<1, b, mid);
        plant(v<<1^1, mid, e);
        seg[0][v] = max(seg[0][v<<1], seg[0][v<<1^1]);
        seg[1][v] = max(seg[1][v<<1], seg[1][v<<1^1]);
    }
}

pii get_max(int v, int b, int e, int l, int r, int w) {
    if (l <= b && e <= r) return seg[w][v];
    if (r <= b || e <= l) return {(int)-1e9, -1};

    int mid = b + e >> 1;
    return max(get_max(v<<1, b, mid, l, r, w), get_max(v<<1^1, mid, e, l, r, w));
}

void upd(int v, int b, int e, int pos) {
    if (e - b == 1) {
        seg[0][v] = {(int)-1e9, b};
        seg[1][v] = {(int)-1e9, b};
        return;
    }

    int mid = b + e >> 1;
    if (pos < mid)
        upd(v<<1, b, mid, pos);
    else
        upd(v<<1^1, mid, e, pos);
    seg[0][v] = max(seg[0][v<<1], seg[0][v<<1^1]);
    seg[1][v] = max(seg[1][v<<1], seg[1][v<<1^1]);
}

void solve() {
    cin >> n >> A >> B, A--, B--;
    for (int i = 0; i < n; i++) cin >> p[i], dist[i] = 1e9;

    plant(1, 0, n);
    deque<int> deq {A};
    dist[A] = 0;
    while (deq.size()) {
        int v = deq.front();
        deq.pop_front();
        if (v == B) {
            cout << dist[v] << "\n";
            return;
        }

        int l = max(0, v - p[v]);
        int r = min(n, v + p[v] + 1);
        while (true) {
            auto x = get_max(1, 0, n, l, v, 1);
            if (x.F < v)
                break;

            int u = x.S;
            dist[u] = dist[v] + 1;
            deq.push_back(u);
            upd(1, 0, n, u);
        }

        while (true) {
            auto x = get_max(1, 0, n, v+1, r, 0);
            if (x.F < -v)
                break;

            int u = x.S;
            dist[u] = dist[v] + 1;
            deq.push_back(u);
            upd(1, 0, n, u);
        }
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}