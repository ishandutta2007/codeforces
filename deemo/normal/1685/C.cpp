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

inline int get_val(char c) {
    return c == '('? 1: -1;
}

void solve() {
    cin >> n >> s; n *= 2;
    auto tt = s;
    vector<int> s1(n+2, 0);
    vector<int> s2(n+2, 0);
    vector<pii> ans;
    int l = 0, r = n;
    while (l < r) {
        int best_l = l;
        while (l < r) {
            s1[l+1] = s1[l] + get_val(s[l]);
            if (s1[l+1] < 0)
                break;
            l++;
            if (s1[l] >= s1[best_l])
                best_l = l;
        }
        int best_r = r;
        while (l < r) {
            s2[r-1] = s2[r] + get_val(s[r-1]);
            if (s2[r-1] > 0)
                break;
            r--;
            if (s2[r] <= s2[best_r])
                best_r = r;
        }
        if (l == r) break;
        ans.push_back({best_l, best_r});
        l = best_l;
        r = best_r;
        reverse(s.begin()+l, s.begin()+r);
    }

    if (ans.size() <= 1) {
        cout << ans.size() << "\n";
        for (auto [x, y]: ans)
            cout << x+1 << " " << y << "\n";
    } else {
        int sm = 0;
        int id = 0, best = 0;
        s = tt;
        for (int i = 0; i < n; i++) {
            sm += get_val(s[i]);
            if (sm >= best)
                id = i+1, best = sm;
        }
        cout << "2\n";
        cout << "1 " << id << "\n";
        cout << id+1 << " " << n << "\n";
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