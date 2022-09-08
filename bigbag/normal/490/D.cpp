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

const int inf = 1111111111;

long long a[5], c2[5], c3[5], k, s1, s2, ss1, ss2, pw[5][111];
long long ans[5], cnt2[5], cnt3[5];

void get(long long poz) {
    long long x = a[poz];
    while (x % 3 == 0) {
        ++c3[poz];
        x /= 3;
        x *= 2;
    }
    while (x % 2 == 0) {
        x /= 2;
        ++c2[poz];
    }
}

bool ok(long long &s2, long long ss1) {
    c2[4] = 0;
    c3[4] = 0;
    while (s2 >= ss1) {
        if (s2 % ss1 == 0) return true;
        if (s2 % 3 != 0) {
            return false;
        }
        ++c3[4];
        s2 = s2 / 3 * 2;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    pw[2][0] = 1;
    pw[3][0] = 1;
    for (long long i = 1; i < 111; ++i) {
        pw[2][i] = pw[2][i - 1] * 2;
        pw[3][i] = pw[3][i - 1] * 3;
    }
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    get(0);
    get(1);
    get(2);
    get(3);
    s1 = a[0] * a[1];
    s2 = a[2] * a[3];
    k = s2;
    ans[4] = inf;
    for (long long i = 0; i <= c3[0] + c3[1]; ++i) {
        for (long long j = 0; j <= c2[0] + c2[1]; ++j) {
            ss1 = s1 / pw[3][i] * pw[2][i];
            if (ss1 % pw[2][j] != 0) continue;
            ss1 /= pw[2][j];
            //if (i == 0 && j == 2) cout << i <<" " << j << " " << ss1 << endl;
            s2 = k;
            if (ok(s2, ss1)) {
                //if (i == 0 && j == 2 && c3[4] != 0) cout << "!" << c3[4] << endl;
                a[4] = s2 / ss1;
                get(4);
                //if (i == 0 && j == 2 && c3[4] != 0) cout << "@"  << a[4] << endl;
                if (k / pw[3][c3[4]] * pw[2][c3[4]] / pw[2][c2[4]] == ss1 && c2[4] <= c2[2] + c2[3] && c3[4] <= c3[2] + c3[3] && c3[4] + c2[4] + i + j < ans[4]) {
                    //cout << i <<" " << j << " " << ss1 << endl;
                    //cout << "^" << endl;
                    //cout << k << " " << ss1 << " " << k / ss1 << endl;
                    ans[4] = c2[4] + c3[4] + i + j;
                    cnt3[0] = min(c3[0], i);
                    cnt3[1] = i - cnt3[0];
                    cnt2[0] = min(c2[0] - c3[0] + cnt3[0], j);
                    cnt2[1] = j - cnt2[0];
                    long long q, w;
                    q = c3[4];
                    w = c2[4];// - c3[4];
                    cnt3[2] = min(c3[2], q);
                    cnt3[3] = q - cnt3[2];
                    cnt2[2] = min(c2[2] - c3[2] + cnt3[2], w);
                    cnt2[3] = w - cnt2[2];
                    ans[0] = a[0] / pw[3][cnt3[0]] * pw[2][cnt3[0]] / pw[2][cnt2[0]];
                    ans[1] = a[1] / pw[3][cnt3[1]] * pw[2][cnt3[1]] / pw[2][cnt2[1]];
                    ans[2] = a[2] / pw[3][cnt3[2]] * pw[2][cnt3[2]] / pw[2][cnt2[2]];
                    ans[3] = a[3] / pw[3][cnt3[3]] * pw[2][cnt3[3]] / pw[2][cnt2[3]];
                    //ans[3] = cnt3[3];
                }
            }
        }
    }
    if (ans[4] != inf) {
        cout << ans[4] << endl;
        cout << ans[0] << " " << ans[1] << endl;
        cout << ans[2] << " " << ans[3] << endl;
        return 0;
    }
    cout << "-1" << endl;
    return 0;
}