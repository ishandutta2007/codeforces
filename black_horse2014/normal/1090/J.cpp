#include <bits/stdc++.h>
using namespace std;

void build_z(string s, int *d) {
    int n = s.length();
    int l = 0, r = 0;
    d[0] = n;
    for (int i = 1, k; i < n; i++) {
        k = (i < r ? min(d[i - l], r - i) : 0);
        while (i + k < n && s[i + k] == s[k]) k++;
        d[i] = k;
        if (i + k > r) r = i + k, l = i;
    }
}

const int N = 220000;

string s, t;
int z[N], pi[N], ma[N];
int main() {
    ios::sync_with_stdio(0);
    cin >> s >> t;
    int ls = s.length(), lt = t.length();
    s = t + "A" + s;
    build_z(s, z);
    pi[1] = 0;
    int n = s.length();
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        for (; cur && s[i] != s[cur]; cur = pi[cur]);
        if (s[i] == s[cur]) cur++;
        pi[i + 1] = cur;
    }
    for (int i = 0; i < lt; i++) {
        int x = i + 1 - pi[i + 1];
        ma[i] = x;
        if (i) ma[i] = max(ma[i], ma[i - 1]);
    }
    long long dap = 0;
    for (int i = 0; i < ls; i++) {
        int j = lt + 1 + i;
        int d = min(z[j + 1], ls - 1 - i);
        int pos = upper_bound(ma, ma + lt, d) - ma;
        dap += (lt - pos + 1);
    }
    int cc = min(lt, z[lt + 1]);
    for (int i = 0; i < ls; i++) {
        int j = i + lt + 1;
        int b = pi[j + 1];
        if (b == i + 1) b = pi[b];
        if (b == 0) dap--;
    }
    cout<<dap<<endl;
    return 0;
}