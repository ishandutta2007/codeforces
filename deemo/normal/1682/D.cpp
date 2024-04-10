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

int n;
string s;
int nxt[MAXN];
bool tor[MAXN];

void solve() {
    cin >> n >> s;
    int c1 = 0;
    for (char c: s)
        if (c == '1')
            c1++;
    if (c1 < 2) {
        cout << "NO\n";
        return;
    }

    int rt = -1;
    for (int i = 0; i < n; i++)
        if (s[i] == '1' && s[(i+1)%n] == '0') {
            rt = (i+1)%n;
            break;
        }
    if (rt == -1) {
        if (c1 & 1) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        for (int i = 2; i <= n; i++)
            cout << "1 " << i << "\n";
        return;
    }

    fill(nxt, nxt + n, -1);
    fill(tor, tor + n, true);
    int cr = n-1;
    for (int c = 1; c < n;) {
        int to = (rt + c) % n;
        c++;
        if (s[to] == '1')
            continue;

        while (true) {
            c++;
            int newto = (to+1)%n;
            nxt[to] = newto;
            tor[newto] = false;
            cr--;
            if (s[newto] == '1') break;
            to = newto;
        }
    }
    if (cr&1 != s[rt]-'0') {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        if (nxt[i] != -1)
            cout << i+1 << " " << nxt[i]+1 << "\n";
        if (i != rt && tor[i])
            cout << i+1 << " " << rt+1 << "\n";
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