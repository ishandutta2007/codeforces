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
string s[2];

int d[MAXN][2];
void solve() {
    cin >> n >> s[0] >> s[1];
    int fs = 0;
    while (s[0][fs] == '.' && s[1][fs] == '.') fs++;
    int sc = n-1;
    while (s[0][sc] == '.' && s[1][sc] == '.') sc--;
    
    for (int i = fs; i <= sc; i++) d[i][0] = d[i][1] = 1e9;;
    d[fs][0] = s[1][fs] == '*';
    d[fs][1] = s[0][fs] == '*';
    for (int i = fs+1; i <= sc; i++) {
        d[i][0] = min(d[i-1][1] + 2, d[i-1][0] + 1 + int(s[1][i] == '*'));
        d[i][1] = min(d[i-1][0] + 2, d[i-1][1] + 1 + int(s[0][i] == '*'));
    }

    cout << min(d[sc][0], d[sc][1]) << "\n";
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