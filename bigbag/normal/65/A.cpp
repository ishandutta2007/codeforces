#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define azazax x1
#define azazay y1
#define azazaz prev

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

long long x, y, a[6];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 6; ++i) {
        cin >> a[i];
    }
    x = a[0] * a[2] * a[4];
    y = a[1] * a[3] * a[5];
    if (a[3] == 0) {
        cout << "Hermione" << endl;
        return 0;
    }
    if (a[2] == 0) {
        cout << "Ron" << endl;
        return 0;
    }

    if (a[1] == 0) {
        cout << "Hermione" << endl;
        return 0;
    }
    if (a[0] == 0) {
        cout << "Ron" << endl;
        return 0;
    }

    if (a[5] == 0) {
        cout << "Hermione" << endl;
        return 0;
    }
    if (a[4] == 0) {
        cout << "Ron" << endl;
        return 0;
    }

    if (x < y) {
        cout << "Ron" << endl;
    } else {
        cout << "Hermione" << endl;
    }
    return 0;
}