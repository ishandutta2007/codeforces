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

const int max_n = 211111, inf = 1000000007;

string s, a, b;
int p[max_n];
long long dp[max_n], f[max_n];

void get_prefix_function() {
    p[0] = 0;
    for (int i = 1; i < s.length(); ++i) {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[i] != s[p[i]]) {
            p[i] = p[p[i] - 1];
        }
        if (s[i] == s[p[i]]) {
            ++p[i];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    s = b + "#" + a;
    get_prefix_function();
    /*for (int i = 0; i < s.length(); ++i) {
        cout << p[i] << " ";
    }
    cout << endl;*/
    int last = -1, len = b.length() + 1;
    long long ans = 0;
    for (int i = 0; i < a.length(); ++i) {
        if (p[i + len] == len - 1) {
            last = i;
        }
        if (last == -1) {
        } else {
            int poz = last - len + 1;
            //cout << i << " ! " << poz << endl;
            if (poz == -1) {
                dp[i] = 1 + dp[i - 1] + poz + 1;
                dp[i] %= inf;
            } else {
                dp[i] = 1 + f[poz] + dp[i - 1] + poz + 1;
                dp[i] %= inf;
            }
        }
        f[i] = dp[i];
        if (i > 0) {
            f[i] = f[i - 1] + dp[i];
            f[i] %= inf;
        }
        //cout << i << " - " << dp[i] << endl;
        //cout << i << " - " << f[i] << endl;
    }
    cout << dp[a.length() - 1] << endl;
    return 0;
}