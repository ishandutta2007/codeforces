#include<iostream>
#include<algorithm>
#define F first
#define S second
using namespace std;
const int MAX_N = 1000;
string s[MAX_N];
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    pair<int, int> mi_add{n,m},ma_add{0,0},mi_sub{n,0},ma_sub{0,m};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j]=='B'){
                if(i+j<mi_add.F+mi_add.S){
                    mi_add={i,j};
                }
                if(i+j>ma_add.F+ma_add.S){
                    ma_add={i,j};
                }
                if(i-j<mi_sub.F-mi_sub.S){
                    mi_sub={i,j};
                }
                if(i-j>ma_sub.F-ma_sub.S){
                    ma_sub={i,j};
                }
            }
        }
    }
    pair<int, int> an;
    int mi=n+m;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) {
            int base=-1;
            for(auto x: {mi_add, ma_add, mi_sub, ma_sub}) {
                if(abs(x.F - i) + abs(x.S - j) > base) {
                    base = abs(x.F - i) + abs(x.S - j);
                }
            }
            if(base < mi) {
                mi = base;
                an = {i, j};
            }
        }
    cout << an.F + 1 << ' ' << an.S + 1 << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}