#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int a[101][2];

int main() {
    int n,p,q;
    string s;
    cin >> n >> p >> q >> s;
    if (p != q) {
        a[p][0] = 1;
        a[q][1] = 1;
    } else {
        a[p][0] = 1;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (i-p >= 0 && (a[i-p][0] || a[i-p][1])) {
            a[i][0] = a[i-p][0]+1;
            a[i][1] = a[i-p][1];
        } else if (i-q >= 0 && (a[i-q][0] || a[i-q][1])) {
            a[i][1] = a[i-q][1]+1;
            a[i][0] = a[i-q][0];
        }
    }
    
    if (a[n][0] || a[n][1]) {
        cout << a[n][0]+a[n][1] << endl;
        for (int i = 0; i < a[n][0]; ++i) {
            for (int j = 0; j < p; ++j) {
                cout << s[p*i+j];
            }
            cout << endl;
        }
        for (int i = 0; i < a[n][1]; ++i) {
            for (int j = 0; j < q; ++j) {
                cout << s[q*i+j+a[n][0]*p];
            }
            cout << endl;
        }
    } else {
        cout << -1;
    }
}