/**
 *  created: 18/02/2021, 16:48:15
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

int n;

int ask(int l, int r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int res;
    cin >> res;
    --res;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int pos = ask(0, n - 1);
    if (pos > 0 && ask(0, pos) == pos) {
        int l = 0, r = pos;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (ask(mid, pos) == pos) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << "! " << l + 1 << endl;
    } else {
        int l = pos, r = n - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (ask(pos, mid) == pos) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << "! " << r + 1 << endl;
    }

    return 0;
}