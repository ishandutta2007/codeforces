#include <bits/stdc++.h>
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using pii=pair<int, int>;
//#define int ll

int gr[105][105];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    int sr = b-1, sc, dir;
    if(b%2) { sc = 0; dir = 1; }
    else { sc = a-1; dir = -1; }
    vector<int> want; want.push_back(0);
    rep(i, n) {
        int v; cin >> v;
        want.push_back(v);
    }
    int cur = 1, area = 0;
    while(cur <= n) {
        //cout << area << ' ' << n << ' ' << cur << ' ' << want[cur] << endl;
        area++; gr[sr][sc] = cur;
        if(area == want[cur]) {
            cur++;
            area = 0;
        }
        if(dir == 1) {
            if(sc != a-1 && sc != a+c-1) sc++;
            else if(sc == a-1 && sr == 0) sc++;
            else {
                dir = -1;
                if(sc == a+c-1) sr++;
                else sr--;
            }
        } else {
            if(sc != 0 && sc != a) sc--;
            else {
                dir = 1;
                if(sc == a) sr++;
                else sr--;
            }
        }
    }
    cout << "YES" << endl;
    rep(i, max(b, d)) {
        rep(j, a+c) {
            if(gr[i][j] != 0) cout << (char)('a' + gr[i][j] - 1);
            else cout << '.';
        }
        cout << endl;
    }
}