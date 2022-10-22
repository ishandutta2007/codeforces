#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 110;
const int MAXM = 1100;
const int INF = 2000000000;

long long f[MAXN], g[MAXN];
long long ans = 0;


int main() {
    int b, d;
    string a, c;
    cin >> b >> d >> a >> c;
    int na = 0, pa = 0, pc = 0, la = a.size(), lc = c.size();
    bool flag = true;
    while (na < b) {
        if (na > lc && ans == 0) break;
        if (a[pa] == c[pc]) ++pc;
        ++pa;
        if (pa == la) {
            pa -= la;
            ++na;
        }
        if (pc == lc) {
            pc -= lc;
            if (f[pa] > 0 && flag) {
                ++ans;
                //cout << "F1: " << na << " " << pa << " " << ans << endl;
                ans += (b - 1 - na) / (na - g[pa]) * (ans - f[pa]);
                na += (b - 1 - na) / (na - g[pa]) * (na - g[pa]);
                //cout << "F2: " << na << " " << pa << " " << ans << endl;
                flag = false;
            } else {
                //cout << na << " " << pa << " "<< endl;
                f[pa] = ++ans;
                g[pa] = na;
            }
        }
    }
    
    cout << ans / d << endl;
    
    return 0;
}