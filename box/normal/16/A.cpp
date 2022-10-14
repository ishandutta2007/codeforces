#include <iostream>
using namespace std;

bool m() {
    int n, m; cin >> n >> m;
    char pcolor = 'A';
    for(int i=0; i<n; i++) {
        char ccolor = 'B';
        char c;
        for(int j=0; j<m; j++) {
            cin >> c;
            if(ccolor != 'B' && ccolor != c) return false;
            ccolor = c;
        }
        if(pcolor != 'A' && pcolor == ccolor) return false;
        pcolor = ccolor;
    }
    return true;
}

int main() {
    if(m()) cout << "YES" << endl;
    else cout << "NO" << endl;
}