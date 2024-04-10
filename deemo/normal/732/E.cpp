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

int n, m, a[MAXN], b[MAXN];
vector<pii> vec[MAXN];
int sec[MAXN], sz;

void add_to_vec(int x, int id) {
    int pos = lower_bound(sec, sec + sz, x) - sec;
    if (pos >= sz || sec[pos] != x) return;

    vec[pos].push_back({b[id], id});
}

int gec[MAXN];
bool used[MAXN];
int to_whom[MAXN];

int req(int a, int b) {
    int res = 0;
    while (a != b) {
        a = a+1>>1;
        res++;
    }
    return res;
}

int dadada[MAXN];
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i], sec[sz++] = a[i];
    sort(sec, sec + sz);
    sz = unique(sec, sec + sz) - sec;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        int x = b[i];
        while (x > 1) {
            add_to_vec(x, i);
            x = x+1>>1;
        }
        add_to_vec(x, i);
    }
    for (int i = 0; i < sz; i++) {
        sort(vec[i].begin(), vec[i].end());
        reverse(vec[i].begin(), vec[i].end());
    }
    
    iota(gec, gec + n, 0);
    sort(gec, gec + n, [](int u, int v) { return a[u] > a[v]; });

    int connected = 0, adapters = 0;
    for (int i = 0; i < n; i++) {
        int v = gec[i];
        int pos = lower_bound(sec, sec + sz, a[v]) - sec;
        while (vec[pos].size()) {
            int who = vec[pos].back().second;
            vec[pos].pop_back();
            if (!used[who]) {
                used[who] = true;
                connected++;
                int r = req(b[who], a[v]);
                dadada[who] = r;
                adapters += r;
                to_whom[v] = who+1;
                break;
            }
        }
    }

    cout << connected << " " << adapters << "\n";
    for (int i = 0; i < m; i++)
        cout << dadada[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << to_whom[i] << " ";
    cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}