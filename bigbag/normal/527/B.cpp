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

const int max_n = 222222, inf = 1111111111;

int n, ans, a[222][222];
string s1, s2;
vector<pair<char, char> > v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; ++i) {
        a[s1[i]][s2[i]] = i + 1;
        if (s1[i] != s2[i]) {
            ++ans;
        }
    }
    int x = 0, p1 = -1, p2 = -1;
    for (char c11 = 'a'; c11 <= 'z'; ++c11) {
        for (char c12 = 'a'; c12 <= 'z'; ++c12) {
            if (a[c11][c12] && c11 != c12) {
                for (char c21 = 'a'; c21 <= 'z'; ++c21) {
                    for (char c22 = 'a'; c22 <= 'z'; ++c22) {
                        if (a[c21][c22] && c21 != c22) {
                            int y = (c12 == c21) + (c22 == c11);
                            if (x < y) {
                                x = y;
                                p1 = a[c11][c12];
                                p2 = a[c21][c22];
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans - x << endl << p1 << " " << p2 << endl;
    return 0;
}