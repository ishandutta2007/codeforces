#include "bits/stdc++.h"

using namespace std;

long long a[30];

int main() {
    string s;
    cin >> s;
    for (int i = 2; i < s.size(); ++i) {
        if (s[i] - 'A' != (s[i - 1] + s[i - 2] - 'A' - 'A') % 26) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}