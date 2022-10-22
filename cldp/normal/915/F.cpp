#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int N;
int f[MAXN], d[MAXN];
bool z[MAXN];
vector<int> X[MAXN];
vector<pair<int, int> > S;


int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return ;
    f[x] = f[y] = (d[x] > d[y] ? f[x] : f[y]);
    d[x] = d[y] = d[x] + d[y];
}

long long cal() {
    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        d[i] = 1;
        f[i] = i;
        z[i] = false;
    }
    for (int i = 0; i < N; ++i) {
        int a = S[i].first, b = S[i].second;
        int cnt = 0;
        long long temp = 1;
        for (int j = 0; j < X[b].size(); ++j) {
            int c = find(X[b][j]);
            if (!z[c]) continue;
            temp += 1LL * cnt * d[c] + d[c];
            cnt += d[c];
        }
        ans += temp * S[i].first;
        for (int j = 0; j < X[b].size(); ++j) {
            int c = find(X[b][j]);
            if (!z[c]) continue;
            Union(b, c);
        }
        z[b] = true;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        S.push_back(make_pair(a, i));
    }
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        X[a].push_back(b);
        X[b].push_back(a);
    }

    sort(S.begin(), S.end());
    long long ans = cal();
    sort(S.rbegin(), S.rend());
    ans -= cal();
    cout << ans << endl;

    return 0;
}