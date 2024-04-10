#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

struct k {
    int n, t;
    string name;
    void read(int poz) {
        n = poz;
        string q;
        cin >> name >> q;
        t = 2;
        if (q == "captain") {
            t = 4;
        }
        if (q == "man") {
            t = 3;
        }
        if (q == "rat") {
            t = 1;
        }
    }
    bool operator < (const k &a) const {
        return t < a.t || t == a.t && n < a.n;
    }
};

int n;
k a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        a[i].read(i);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        cout << a[i].name << endl;
    }
    return 0;
}