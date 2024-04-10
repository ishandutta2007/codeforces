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
set<int> st[2];
vector<vector<int>> ans;

void fail() {
    cout << "-1\n";
    exit(0);
}

void solve() {
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            st[0].insert(i);
        else
            st[1].insert(i);
    
    while (st[0].size() || st[1].size()) {
        vector<int> temp;
        if (!st[0].size())
            fail();
 
        int lst = *st[0].begin();
        st[0].erase(st[0].begin());
        temp.push_back(lst);
        while (st[1].lower_bound(lst) != st[1].end()) {
            int nxt1 = *st[1].lower_bound(lst);
            if (st[0].upper_bound(nxt1) == st[0].end()) break;

            st[1].erase(nxt1);
            int nxt0 = *st[0].upper_bound(nxt1);
            st[0].erase(nxt0);
            temp.push_back(nxt1);
            temp.push_back(nxt0);
            lst = nxt0;
        }
        ans.push_back(temp);
    }
    
    cout << ans.size() << "\n";
    for (auto v: ans) {
        cout << v.size() << " ";
        for (auto x: v)
            cout << x+1 << " ";
        cout << "\n";
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