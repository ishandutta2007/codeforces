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
int gt[MAXN];
int a[MAXN];

void solve() {
    cin >> n >> s[0] >> s[1];
    gt[n] = 1;
    for (int i = n-1; ~i; i--)
        if (s[0][i] == s[1][i])
            gt[i] = gt[i+1];
        else if (s[0][i] < s[1][i])
            gt[i] = 1;
        else
            gt[i] = 0;

    for (int i = 0; i < n; i++) {
        int dif = s[1][i] - s[0][i];
        a[i] = dif;
        if (dif < 0) {
            a[i] += 26;
            for (int j = i-1; ~j; j--) {
                a[j]--;
                if (a[j] >= 0) break;
                a[j] += 26;
            }
        }
    }
    int carry = 0;
    for (int i = 0; i < n; i++) {
        a[i] += carry;
        carry = 0;
        if (a[i] % 2 == 0)
            a[i] /= 2;
        else {
            a[i] /= 2;
            carry = 26;
        }
    }
    for (int i = n-1; ~i; i--) {
        if (a[i] >= 26) 
            a[i-1] += a[i]/26;
        a[i] %= 26;
    }
    for (int i = n-1; ~i; i--) {
        int cur = s[0][i] - 'a';
        cur += a[i];
        if (cur >= 26) {
            a[i-1] += cur / 26;
            cur %= 26;
        }
        s[0][i] = char(cur + 'a');
    }
    cout << s[0] << "\n";
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