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

int n;
int tr[MAXN*MAXN][26], sz;
string s;

void insert(string t) {
    int cur = 0;
    for (char c: t) {
        if (!tr[cur][c-'a'])
            tr[cur][c-'a'] = ++sz;
        cur = tr[cur][c-'a'];
    }
}

vector<string> vec;

void dfs(int v, string cur="") {
    for (int w = 0; w < 26; w++)
        if (!tr[v][w]) {
            vec.push_back(cur + char('a' + w));
            return;
        }
    for (int w = 0; w < 26; w++)
        dfs(tr[v][w], cur + char('a' + w));
}

bool check(string t) {
    int ln = t.size();
    for (int i = 0; i + ln <= n; i++)
        if (t == s.substr(i, ln)) {
            return false;
        }
            cout << t << "\n";
    return true;
}

void solve() {
    cin >> n >> s;
    for (int i = 0; i < 26; i++) {
        string temp = "";
        temp += char('a' + i);
        if (check(temp)) {
            return;
        }
    }
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++) {
            string temp = "";
            temp += char('a' + i);
            temp += char('a' + j);
            if (check(temp)) return;
        }
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            for (int k = 0; k < 26; k++) {
                string temp = "";
                temp += char('a' + i);
                temp += char('a' + j);
                temp += char('a' + k);
                if (check(temp)) return;
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