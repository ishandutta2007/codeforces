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

bool mat[5200][5200];

bool issame[5200];
int n;

bool test(int v) {
    rep(i, n-1) {
        if(!((i+1)%v)) continue;
        if(!issame[i]) return 0;
    }
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    rep(i, n) {
        string s; cin >> s;
        rep(j, n/4) {
            char c = s[j];
            int v = 0;
            if(c <= '9') v = c - '0';
            else v = 10 + c - 'A';
            mat[i][4*j] = (bool)(v&8);
            mat[i][4*j+1] = (bool)(v&4);
            mat[i][4*j+2] = (bool)(v&2);
            mat[i][4*j+3] = (bool)(v&1);
        }
    }
    rep(i, n-1) {
        issame[i] = true;
        for(int j=0; issame[i] && j<n; j++) issame[i] = (mat[i][j] == mat[i+1][j]);
        for(int j=0; issame[i] && j<n; j++) issame[i] = (mat[j][i] == mat[j][i+1]);
    }
    for(int i=n; i>0; i--) {
        if(n%i) continue;
        if(test(i)) {
            cout << i << endl;
            return 0;
        }
    }
}