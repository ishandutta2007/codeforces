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

const int MAXN = 1e6 + 10;

int n;
string s;
char ch[4] = {'A', 'N', 'O', 'T'};
int mp[200];
int pt[MAXN][4];

int c[4];
int p[4];
int sec[4];
ll get() {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < 4; i++) p[sec[i]] = i;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            if (p[j] > p[mp[s[i]]])
                res += c[j];
        c[mp[s[i]]]++;
    }
    return res;
}

void solve() {
    mp['A'] = 0;
    mp['N'] = 1;
    mp['O'] = 2;
    mp['T'] = 3;

    cin >> s; n = s.size();
    for (int i = 0; i < n; i++) {
        for (int w = 0; w < 4; w++)
            pt[i+1][w] = pt[i][w] + int(mp[s[i]] == w);
    }

    iota(sec, sec + 4, 0);
    string best=s;
    ll cnt = 0;
    do{
        string cur = "";
        for (int i = 0; i < 4; i++) {
            int who = sec[i];
            for (int j = 0; j < pt[n][who]; j++)
                cur += ch[who];
        }
        ll temp = get();
        if (temp > cnt)
            cnt = temp, best = cur;
    }while(next_permutation(sec, sec + 4));
    cout << best << "\n";
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