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

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    deque<int> d[3];
    for (int i = 0; i < n; i++)
        d[s[i] - 'a'].push_back(i);

    for (int i = 0; i < n; i++) {
        int mn = -1;
        for (int j = 0; j < 3; j++)
            if (d[j].size() && (mn == -1 || d[j].front() < d[mn].front()))
                mn = j;
        
        int req = t[i] - 'a';
        if (req == mn)
            d[mn].pop_front();
        else if (req < mn) {
            cout << "NO\n";
            return;
        }
        else if (abs(req-mn) != 1) {
            cout << "NO\n";
            return;
        }
        else {
            int mn2 = -1;
            for (int j = 0; j < 3; j++)
                if (d[j].size() && j != mn && (mn2 == -1 || d[j].front() < d[mn2].front()))
                    mn2 = j;
            if (mn2 != mn + 1) {
                cout << "NO\n";
                return;
            } else {
                d[mn2].pop_front();
            }
        }
    }
    cout << "YES\n";
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