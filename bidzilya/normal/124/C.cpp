#include <cstdio>

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int max_n = 1e3 + 100;

string s;
char ans[max_n];
int c[26];
int is_prime[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 2; i < max_n; ++i)
        is_prime[i] = true;
    for (int i = 2; i * i < max_n; ++i)
        if (is_prime[i])
            for (int j = i * i; j < max_n; j += i)
                is_prime[j] = false;
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
        ++c[s[i] - 'a'];
    char cc;
    for (int i = 2; i <= s.length(); ++i) {
        if (!is_prime[i]) continue;
        cc = 0;
        int k = 0;
        for (int j = i; j <= s.length(); j += i)
            if (ans[j]) {
                if (!cc) {
                    cc = ans[j];
                } else if (cc != ans[j]) {
                    cout << "NO" << endl;
                    return 0;
                }
            } else {
                ++k;
            }
        if (cc) {
            if (c[cc - 'a'] < k) {
                cout << "NO" << endl;
                return 0;
            }
            c[cc - 'a'] -= k;
            for (int j = i; j <= s.length(); j += i)
                ans[j] = cc;
        } else {
            for (int j = 0; j < 26; ++j)
                if (c[j] >= k && (!cc || c[j] > c[cc - 'a'])) {
                    cc = j + 'a';
                }
            if (!cc) {
                cout << "NO" << endl;
                return 0;
            }
            c[cc - 'a'] -= k;
            for (int j = i; j <= s.length(); j += i)
                ans[j] = cc;
        }
    }
    for (int i = 0; i < 26; ++i)
        if (c[i]) {
            cc = i + 'a';
            break;
        }
    ans[1] = cc;
    cout << "YES" << endl;
    for (int i = 1; i <= s.length(); ++i)
        cout << ans[i];
    cout << endl;
    return 0;
}