#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct dragon {
    int str, p;
} dr[1005];

int main() {
    int s, n; cin >> s >> n;
    for(int i=0; i<n; i++) cin >> dr[i].str >> dr[i].p;
    sort(dr, dr+n, [](const dragon& a, const dragon& b) {
        return a.str < b.str;
    });
    for(int i=0; i<n; i++) {
        if(s <= dr[i].str) {
            cout << "NO" << endl;
            return 0;
        }
        s += dr[i].p;
    }
    cout << "YES" << endl;
}