/**********
*         *
*  HELLO  *
*         *
**********/

#include <bits/stdc++.h>

using namespace std;

long long gcd (long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

long long lcm (long long a, long long b) {
    return (a * b) / gcd(a, b);
}

const long long mx = 500;
bool cycle, m1 = 0, exita;
long long n, g[mx], used[mx], len;
vector<long long> k;

void dfs(long long v) {
    used[v]++;
    if (cycle) len++;
    if (used[g[v]] == 0) {
        dfs(g[v]);
        if (exita) return;
    }
    if (used[g[v]] == 1) {
        cycle = 1;
        dfs(g[v]);
        if (exita) return;
    }
    if (used[g[v]] == 2) {
        if (cycle == 0) {
            m1 = 1;
            exita = 1;
            return;
        }
        else {
            exita = 1;
            k.push_back(len);
            return;
        }
    }
}

int main()
{
    k.clear();
    cin >> n;
    for (long long i = 0; i < n; ++i) {
        cin >> g[i];
        g[i]--;
        used[i] = 0;
    }
    for (long long i = 0; i < n; ++i) {
        cycle = 0;
        len = 0;
        exita = 0;
        if (used[i] == 0) dfs(i);
        if (m1 == 1) {
            cout << -1;
            return 0;
        }
    }
    for (long long i = 0; i < n; ++i) {
        if (used[i] == 1) {
            cout << -1;
            return 0;
        }
    }
    for (long long i = 0; i < k.size(); ++i) {
        if (k[i] % 2 == 0) k[i] = k[i] / 2;
    }
    int ans = 1;
    for (long long i = 0; i < k.size(); ++i) {
        ans = lcm(ans, k[i]);
    }
    cout << ans;
    return 0;
}