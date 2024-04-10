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

const int MAXN = 1e3 + 10;

int n, m;
string s[MAXN];

int mx[4];
void ins(int i, int j) {
    mx[0] = max(mx[0], i+j);
    mx[1] = max(mx[1], (n-i)+j);
    mx[2] = max(mx[2], i+(m-j));
    mx[3] = max(mx[3], (n-i)+(m-j));
}

int get(int i, int j, int t) {
    switch (t) {
        case 0:
            return i+j;
        case 1:
            return (n-i)+j;
        case 2:
            return i+(m-j);
        case 3:
            return (n-i)+(m-j);
    }
}

void solve() {
    fill(mx, mx + 4, -1e8);
    cin >> n >> m; for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'B')
                ins(i, j);

    pii ans;
    int best = 1e9;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int tmp = -1e9;
            for (int t = 0; t < 4; t++)
                tmp = max(tmp, mx[t] - get(i, j, t));
            if (best > tmp)
                best = tmp, ans = {i, j};
        }
    cout << ans.F+1 << " " << ans.S + 1 << "\n";
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