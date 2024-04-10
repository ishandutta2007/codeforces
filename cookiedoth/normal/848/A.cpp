#include <bits/stdc++.h>
#define ll long long
#define elif else if
#define MOD 1000000007

using namespace std;

const int mx = 500;

int e[mx], k;

int main()
{
    cin >> k;
    e[0] = 0;
    e[1] = 0;
    for (int i = 2; i < mx; ++i) {
        e[i] = 1e9;
        for (int j = 1; j <= i - 1; ++j) {
            e[i] = min(e[i], e[j] + e[i-j] + j * (i - j));
        }
    }
    string ans;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < mx; ++j) {
            if (e[j] > k) {
                for (int a = 0; a < j - 1; ++a) {
                    ans.push_back('a' + i);
                }
                k -= e[j-1];
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}