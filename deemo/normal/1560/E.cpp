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

const int MAXN = 5e5 + 10;

int n;
string s;

string get(string s, string ord) {
    string res;
    for (int i = 0; i < ord.size(); i++) {
        res += s;
        string temp;
        for (char c: s)
            if (c != ord[i])
                temp += c;
        s = temp;
    }
    return res;
}

void solve() {
    int cnt[200] = {0};
    cin >> s; n = s.size();
    string order;
    reverse(s.begin(), s.end());
    for (char c: s) {
        if (order.find(c) == string::npos)
            order += c;
        cnt[c]++;
    }
    reverse(s.begin(), s.end());
    reverse(order.begin(), order.end());
    for (int i = 0; i < order.size(); i++)
        if (cnt[order[i]] % (i+1)) {
            cout << "-1\n";
            return;
        } else cnt[order[i]] /= (i+1);
    int i = 0;
    int rem = order.size();
    while (i < s.size() && rem) {
        if (!cnt[s[i]]) {
            cout << "-1\n";
            return;
        }
        cnt[s[i]]--;
        if (!cnt[s[i]])
            rem--;
        i++;
    }
    if (get(s.substr(0, i), order) != s) {
        cout << "-1\n";
        return;
    }
    cout << s.substr(0, i) << " " << order << "\n";
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