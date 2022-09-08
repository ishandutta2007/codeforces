#include <bits/stdc++.h>

using namespace std;

double st = clock();

double get_time() {
    return (clock() - st) / CLOCKS_PER_SEC;
}

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    map<int, int> ans;
    cin >> n;
    ans[3] = 13; // Sample
    ans[0] = 15;
    ans[1] = 14;
    ans[2] = 12;
    ans[4] = 8;
    ans[5] = 9;
    ans[6] = 10;
    ans[7] = 11;

    ans[8] = 0;
    ans[9] = 1;
    ans[10] = 2;
    ans[11] = 3;

    ans[12] = 4;
    ans[13] = 5;
    ans[14] = 6;
    ans[15] = 7;
    if (ans.count(n)) {
        cout << ans[n] << endl;
        return 0;
    }
    while (get_time() < n / 16.0) {
    }
    cout << 0 << endl;
    return 0;
}