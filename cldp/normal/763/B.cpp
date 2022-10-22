#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct node {
    int x1, y1, x2, y2;
    node() {}
    bool operator < (const node &B) const {
        if (x1 != B.x1) return x1 < B.x1;
        return y1 < B.y1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    cout << "YES" << endl;
    for (int i = 0; i < N; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a = min(a, c);
        b = min(b, d);
        if (a % 2 == 0) {
            if (b % 2 == 0) cout << 1 << endl; else cout << 2 << endl;
        } else {
            if (b % 2 == 0) cout << 3 << endl; else cout << 4 << endl;
        }
    }

    return 0;
}