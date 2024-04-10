#include <bits/stdc++.h>
using namespace std;

int x[1003][1003];
#define MOD 1000000007

long long mpow(int e) {
    if(e == 0) return 1;
    if(e == 1) return 2;
    long long a = mpow(e/2);
    a = a * a;
    if(e % 2) a *= 2;
    a = a % MOD;
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int h, w; cin >> h >> w;
    for(int i=0; i<h; i++) {
        int v; cin >> v;
        for(int j=0; j<v; j++) {
            if(x[i][j] == 2) {
                cout << 0 << endl;
                return 0;
            }
            x[i][j] = 1;
        }
        if(x[i][v] == 1) {
            cout << 0 << endl;
            return 0;
        }
        x[i][v] = 2;
    }
    for(int i=0; i<w; i++) {
        int v; cin >> v;
        for(int j=0; j<v; j++) {
            if(x[j][i] == 2) {
                cout << 0 << endl;
                return 0;
            }
            x[j][i] = 1;
        }
        if(x[v][i] == 1) {
            cout << 0 << endl;
            return 0;
        }
        x[v][i] = 2;
    }
    int t = 0;
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            if(x[i][j] == 0) t++;
    cout << mpow(t) << endl;
}