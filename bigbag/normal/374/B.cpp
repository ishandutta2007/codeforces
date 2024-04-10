#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 111111111;


int n;
pair <int, long long> d[max_n];
char a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    gets(a);
    int l = strlen(a);
    d[0] = make_pair(0, 1);
    if (a[0] != '9') {
        d[1] = make_pair(0, 1);
    } else {
        d[1] = make_pair(1, 1);
    }
    for (int i = 1; i < l; ++i) {
        int q = i + 1;
        if (a[i] == '9') {
            d[q] = make_pair(d[q - 1].first + 1, d[q - 1].second);
        }
        else {
            if (a[i] + a[i - 1] - '0' - '0' == 9) {
                if (d[q - 2].first + 1 < d[q - 1].first) {
                    d[q] = d[q - 1];
                }
                if (d[q - 2].first + 1 == d[q - 1].first) {
                    d[q].first = d[q - 1].first;
                    d[q].second = d[q - 2].second + d[q - 1].second;
                }
                if (d[q - 2].first + 1 > d[q - 1].first) {
                    d[q].first = d[q - 2].first + 1;
                    d[q].second = d[q - 2].second;
                }
            } else {
                d[q] = d[q - 1];
            }
        }
        //cout << d[i + 1].first << ' ' << d[i + 1].second << endl;
    }
    cout << d[l].second;
    return 0;
}