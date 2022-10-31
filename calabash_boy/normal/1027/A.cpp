//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cerr<<"[debug] "<<#x<<":"<<x<<endl;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int maxn = 1e6+100;
const int MOD = 1e9+7;
int a[maxn],n;
map<int,int> cnt;
vector<int> ans;
inline bool ok(char a, char b) {
    if (a == b) return true;
    return a + 2 == b || b + 2 == a;
}
void solve(){
    int n;
    string s;
    cin >> n >> s;
    bool flag = true;
    for (int i = 0; i + i < n; i++)
        if (!ok(s[i], s[n - 1 - i]))
            flag = false;
    cout << (flag? "YES": "NO") << endl;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}