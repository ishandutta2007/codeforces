// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int ans[100005];
int tot[6];

map<string, int> toInt;
vector<int> want[6];
string toStr[6];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    toInt["S"] = 0; toStr[0] = "S";
    toInt["M"] = 1; toStr[1] = "M";
    toInt["L"] = 2; toStr[2] = "L";
    toInt["XL"] = 3; toStr[3] = "XL";
    toInt["XXL"] = 4; toStr[4] = "XXL";
    toInt["XXXL"] = 5; toStr[5] = "XXXL";
    rep(i, 6) cin >> tot[i];
    int n; cin >> n;
    rep(i, n) {
        string s; cin >> s;
        string a, b="!";
        for(char c:s) {
            if(b != "!") b += c;
            else if(c == ',') b = "";
            else a += c;
        }
        if(b == "!") {
            ans[i] = toInt[a];
            tot[ans[i]]--;
        } else want[toInt[a]].pb(i);
    }
    rep(i, 6) {
        if(tot[i] < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    rep(i, 6) {
        for(int& v:want[i]) {
            if(tot[i]) {
                tot[i]--;
                ans[v] = i;
            } else {
                if(!tot[i+1]) {
                    cout << "NO" << endl;
                    return 0;
                }
                tot[i+1]--;
                ans[v] = i+1;
            }
        }
    }
    cout << "YES" << endl;
    rep(i, n) {
        cout << toStr[ans[i]] << endl;
    }
}