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

const int max_n = 5005, max_m = 1011, inf = 1011111111;

int n, m, tp[max_n], a[max_n], b[max_n], res[max_n];
string value[max_n];
map<string, int> num;
char S[max_m], ans1[max_m], ans2[max_m];

string read() {
    scanf("%s", S);
    return S;
}

void get(int pos) {
    pair<int, int> mn = make_pair(inf, inf);
    pair<int, int> mx = make_pair(-inf, -inf);
    for (int x = 0; x < 2; ++x) {
        res[n] = x;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (tp[i] == 0) {
                res[i] = value[i][pos];
            } else if (tp[i] == 1) {
                res[i] = res[a[i]] & res[b[i]];
            } else if (tp[i] == 2) {
                res[i] = res[a[i]] | res[b[i]];
            } else {
                res[i] = res[a[i]] ^ res[b[i]];
            }
            sum += res[i];
        }
        mn = min(mn, make_pair(sum, x));
        mx = max(mx, make_pair(sum, -x));
    }
    mx.second *= -1;
    ans1[pos] = mn.second + '0';
    ans2[pos] = mx.second + '0';
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    num["?"] = n;
    for (int i = 0; i < n; ++i) {
        string s = read(), q, w;
        num[s] = i;
        read();
        q = read();
        if (q[0] == '0' || q[0] == '1') {
            tp[i] = 0;
            value[i] = q;
            for (int j = 0; j < m; ++j) {
                value[i][j] -= '0';
            }
        } else {
            string op = read();
            if (op == "AND") {
                tp[i] = 1;
            } else if (op == "OR") {
                tp[i] = 2;
            } else {
                tp[i] = 3;
            }
            w = read();
            a[i] = num[q];
            b[i] = num[w];
        }
        //cout << i << ": " << tp[i] << " " << a[i] << " " << b[i] << "   " << value[i] << endl;
    }
    for (int i = 0; i < m; ++i) {
        get(i);
    }
    printf("%s\n%s\n", ans1, ans2);
    return 0;
}