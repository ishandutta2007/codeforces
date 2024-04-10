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

int cnt[2][max_n];
long long ans;
string s1, s2;

int get(int x, int l, int r) {
    if (l == 0) {
        return cnt[x][r];
    }
    return cnt[x][r] - cnt[x][l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s1 >> s2;
    cnt[s2[0] - '0'][0] = 1;
    for (int i = 1; i < s2.length(); ++i) {
        cnt[0][i] = cnt[0][i - 1];
        cnt[1][i] = cnt[1][i - 1];
        ++cnt[s2[i] - '0'][i];
    }
    for (int i = 0; i < s1.length(); ++i) {
        int l = i, r = l + s2.length() - s1.length();
        ans += get((s1[i] - '0') ^ 1, l, r);
    }
    cout << ans << endl;
    return 0;
}