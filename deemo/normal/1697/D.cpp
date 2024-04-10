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
string s;
pair<int, int> sec[MAXN];
int lst[MAXN];

void solve() {
    cin >> n;
    cout << "? 1 1" << endl;
    cin >> s;
    memset(lst, -1, sizeof(lst));
    lst[s[0]-'a'] = 0;

    int sz = 1;
    for (int i = 1; i < n; i++) {
        cout << "? 2 " << 1 << " " << i+1 << endl;
        int cnt; cin >> cnt;
        if (cnt != sz) {
            cout << "? 1 " << i+1 << endl;
            char ch; cin >> ch;
            s += ch;
            sz++;
        } else {
            int tt = 0;
            for (int j = 0; j < 26; j++)
                if (lst[j] != -1)
                    sec[tt++] = {lst[j], j};
            sort(sec, sec + sz);

            int lo = 0, hi = sz;
            while (hi-lo>1) {
                int mid = hi + lo >> 1;
                cout << "? 2 " << sec[mid].F+1 << " " << i+1 << endl;
                cin >> cnt;
                if (cnt == sz-mid)
                    lo = mid;
                else
                    hi = mid;
            }
            s += char('a' + sec[lo].S);
        }
        lst[s[i]-'a'] = i;
    }
    cout << "! " << s << endl;
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