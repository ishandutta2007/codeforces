#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int n, k;
string s, ans;

void proc() {
    for (int i = k; i < n; ++i) {
        ans[i] = ans[i - k];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    s = read();
    ans = s;
    proc();
    printf("%d\n", n);
    if (ans >= s) {
        puts(ans.c_str());
        return 0;
    }
    for (int i = k - 1; i >= 0; --i) {
        if (ans[i] != '9') {
            ++ans[i];
            for (int j = i + 1; j < k; ++j) {
                ans[j] = '0';
            }
            proc();
            puts(ans.c_str());
            return 0;
        }
    }
    return 0;
}