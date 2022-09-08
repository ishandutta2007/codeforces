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

const int max_n = 422222, inf = 1111111111;

int n[2], p[max_n];
long long l[2][max_n], ans;
char c[2][max_n];
vector<pair<char, long long> > v;

void get_prefix_function() {
    p[0] = 0;
    for (int i = 1; i < v.size(); ++i) {
        p[i] = p[i - 1];
        while (p[i] > 0 && v[i] != v[p[i]]) {
            p[i] = p[p[i] - 1];
        }
        if (v[i] == v[p[i]]) {
            ++p[i];
        }
    }
}

void proc(int tp) {
    vector<pair<char, long long> > v;
    int cnt = 0;
    for (int i = 0; i < n[tp]; ) {
        long long len = 0;
        int poz = i;
        while (poz < n[tp] && c[tp][poz] == c[tp][i]) {
            len += l[tp][i];
            ++i;
        }
        l[tp][cnt] = len;
        c[tp][cnt] = c[tp][poz];
        ++cnt;
    }
    n[tp] = cnt;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n[0], &n[1]);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n[i]; ++j) {
            scanf("%I64d%c%c", &l[i][j], &c[i][j], &c[i][j]);
        }
    }
    proc(0);
    proc(1);
    /*for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n[i]; ++j) {
            cout << "(" << c[i][j] << " " << l[i][j] << ") ";
        }
        cout << endl;
    }*/
    if (n[1] == 1) {
        for (int i = 0; i < n[0]; ++i) {
            if (c[0][i] == c[1][0] && l[0][i] >= l[1][0]) {
                ans += l[0][i] - l[1][0] + 1;
            }
        }
    } else {
        for (int i = 1; i + 1 < n[1]; ++i) {
            v.push_back(make_pair(c[1][i], l[1][i]));
        }
        v.push_back(make_pair('A', 1));
        for (int i = 0; i < n[0]; ++i) {
            v.push_back(make_pair(c[0][i], l[0][i]));
        }
        get_prefix_function();
        for (int i = 0; i + n[1] - 1 < n[0]; ++i) {
            //if (p[i + n[1] - 2] == n[1] - 2) cout << "!" << i << endl;
            if (c[0][i] == c[1][0] && l[0][i] >= l[1][0] && p[n[1] + i + n[1] - 3] == n[1] - 2 && l[0][i + n[1] - 1] >= l[1][n[1] - 1] && c[0][i + n[1] - 1] == c[1][n[1] - 1]) {
                ++ans;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}