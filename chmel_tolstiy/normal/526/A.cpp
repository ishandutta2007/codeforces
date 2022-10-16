#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

bool solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) for (int l = 1; l * 4 + i < n; ++l) {
        bool ok = true;
        for (int j = 0; j < 5; ++j) ok &= s[i + j * l] == '*';
        if (ok) {
            cout << "yes" << endl;
            return false;
        }
    }

    cout << "no" << endl;

    return false;
}

int main() {

    while (solve());
    
    return 0;
}