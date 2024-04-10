#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353;

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
const int C = 17;

int n, q;
string s, t;

int ss[C+2][MAXN];
int sm[1<<C][C+2];
void deal_with(int endless, int req, int rem) {
    for (int i = 1; i <= C; i++)
        add(sm[req][i], 1ll * ss[i][endless] * ss[i][rem] % MOD);
}

int ans[1<<C];
void solve() {
    for (int i = 0; i <= C; i++) {
        ss[i][0] = 1;
        for (int j = 1; j < MAXN; j++)
            ss[i][j] = 1ll*ss[i][j-1]*i%MOD;
    }
    cin >> n >> s >> q;
    for (int i = 0; i < n; i++)
        if (i == n-1)
            t += s[i];
        else {
            t += s[i];
            t += "r";
        }
    n = t.size();
    s = t;
    for (int i = 0; i < n; i++) {
        int l = i, r = i+1;
        int req = 0;
        int endless = 0;
        int rem = 0;
        for (char c: s)
            if (c == '?')
                rem++;
        do {
            if (s[l] == '?')
                rem--;
            if (l < r-1 && s[r-1] == '?')
                rem--;
            if (s[l] != '?' && s[r-1] != '?') {
                // nothing
            } else if (s[l] != '?' || s[r-1] != '?') {
                if (s[l] != '?')
                    req |= 1<<s[l]-'a';
                else
                    req |= 1<<s[r-1]-'a';
            } else
                endless++;

            if (s[l] != 'r') {
                deal_with(endless, req, rem);
            }

            l--, r++;
        } while (0 <= l && r <= n && (s[l] == s[r-1] || s[l] == '?' || s[r-1] == '?'));
    }

    for (int mask = 1; mask < 1<<C; mask++)
        for (int sub = mask; ; sub=sub-1&mask) {
            add(ans[mask], sm[sub][__builtin_popcount(mask)]);
            if (!sub)
                break;
        }

    while (q--) {
        cin >> t;
        int mask = 0;
        for (char c: t)
            mask |= 1<<c-'a';
        cout << ans[mask] << "\n";
    }
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