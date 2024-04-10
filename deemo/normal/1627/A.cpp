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

const int MAXN = 100 + 10;

int n, m, r, c;
string s[MAXN];

void solve() {
    cin >> n >> m >> r >> c, r--, c--;
    for (int i = 0; i < n; i++) cin >> s[i];
    if (s[r][c] == 'B')
        cout << "0\n";
    else {
        bool fl = false;
        for (int i = 0; i < n; i++)
            fl |= s[i][c] == 'B';
        for (int j = 0; j < m; j++)
            fl |= s[r][j] == 'B';
        if (fl)
            cout << "1\n";
        else {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    fl |= s[i][j] == 'B';
            if (fl)
                cout << "2\n";
            else
                cout << "-1\n";
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