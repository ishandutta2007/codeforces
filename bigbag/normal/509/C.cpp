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

const int max_n = 333, inf = 1111111111;

int n, a[max_n], len[max_n];
string ans[max_n];

string get_min(int len, int q, int wer) {
    string res;
    for (int i = 0; i < len; ++i) {
        int st = 0;
        if (i == 0) {
            st = wer;
        }
        for (int j = st; j <= 9; ++j) {
            if (q - j <= 9 * (len - 1 - i)) {
                res += '0' + j;
                q -= j;
                break;
            }
        }
    }
    return res;
}

string get_max(int len, int q) {
    string res;
    for (int i = 0; i < len; ++i) {
        int st = 0;
        if (i == 0) {
            st = 1;
        }
        for (int j = 9; j >= st; --j) {
            if (q - j >= 0 && q - j <= 9 * (len - 1 - i)) {
                res += '0' + j;
                q -= j;
                break;
            }
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) {
            while (true) {
                ++len[i];
                if (9 * len[i] >= a[i]) {
                    ans[i] = get_min(len[i], a[i], 1);
                    break;
                }
            }
        } else {
            while (true) {
                ++len[i];
                if (9 * len[i] >= a[i]) {
                    if (len[i] > len[i - 1]) {
                        ans[i] = get_min(len[i], a[i], 1);
                        break;
                    } else if (len[i] == len[i - 1]) {
                        ans[i] = get_max(len[i], a[i]);
                        if (ans[i - 1] >= ans[i]) {
                            ++len[i];
                            ans[i] = get_min(len[i], a[i], 1);
                        } else {
                            int sum = a[i - 1], f = 0;
                            for (int j = len[i] - 1; j >= 0; --j) {
                                sum -= (ans[i - 1][j] - '0');
                                int o = a[i] - sum;
                                int qw = ans[i - 1][j] - '0' + 1;
                                //cout << "!" << i << "   " << qw << "   " << o << endl;
                                if (qw <= 9 && o >= qw && o <= 9 * (len[i] - j)) {
                                    ans[i] = "";
                                    for (int w = 0; w < j; ++w) {
                                        ans[i] += ans[i - 1][w];
                                    }
                                    ans[i] += get_min(len[i] - j, o, qw);
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
        cout << ans[i] << endl;
    }
    return 0;
}