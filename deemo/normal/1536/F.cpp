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

const int MAXN = 2e6 + 10;

int g[MAXN][2][2];
int ss[MAXN], tt[MAXN];

int choose(int a, int b) {
    if (a < b)
        return 0;
    if (a < 0 || b < 0) return 0;
    return 1ll*ss[a]*tt[b]%MOD*tt[a-b]%MOD;
}

void solve() {
    /*
    g[1][0][0] = g[1][1][1] = 1;
    for (int i = 2; i < 10; i++)
        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 2; b++) {
                set<int> st;
                for (int j = 1; j <= i; j++)
                    for (int w = 0; w < 2; w++) {
                        if (j == 1 && w == a) continue;
                        if (j == i && w == b) continue;
                        st.insert(g[j-1][a][w] ^ g[i-j][w][b]);
                    }
                for (int j = 0; ; j++) {
                    if (!st.count(j)) {
                        g[i][a][b] = j;
                        break;
                    }
                }
                cout << i << "      " << a << " " << b << "     " << g[i][a][b] << endl;
            }*/
    ss[0] = 1;
    for (int i = 1; i < MAXN; i++)
        ss[i] = 1ll*ss[i-1]*i % MOD;
    tt[0] = 1;
    for (int i = 1; i < MAXN; i++)
        tt[i] = pw(ss[i], MOD-2) % MOD;

    int n; cin >> n;
    int ans = 0;
    if (n%2==0)
        ans = 2ll*ss[n]%MOD;
    for (int i = 1; i <= n/2; i++) {
        int rem = n-i;
        if (rem&1) continue;
        int groups = i+1;
        int temp = choose(rem+1, groups-1);
        add(temp, -choose(rem-1, groups-3));
        ans = (ans + 2ll*ss[rem]*temp) % MOD;
    }
    cout << ans << "\n";
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