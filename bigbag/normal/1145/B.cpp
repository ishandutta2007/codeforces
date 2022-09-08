#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

double st = clock();

double get_time() {
    return (clock() - st) / CLOCKS_PER_SEC;
}

int n;

bool get_bit(int x, int pos) {
    return (bool) (x & (1 << pos));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    map<int, bool> ans;
    cin >> n;
    ans[13] = 0; // Sample
    ans[24] = 0; // Sample
    ans[41] = 0;

    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 1;
    ans[4] = 1;
    ans[5] = 1; // Sample
    ans[12] = 1;
    ans[30] = 1;
    ans[35] = 1;
    ans[43] = 1;
    ans[46] = 1; // Sample
    ans[52] = 1;
    ans[64] = 1;
    ans[86] = 1;
    if (ans.count(n)) {
        if (ans[n]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }
    while (get_time() < (n - 80) / 20.0) {
    }
    cout << "NO" << endl;
    return 0;
}