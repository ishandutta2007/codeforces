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

int n, k;
long long sum0[max_n];
double ans, a[2][max_n], sum1[max_n], dp[2][max_n];
vector<pair<long long, double> > v;

double get(pair<long long, double> a, pair<long long, double> b) {
    return (b.second - a.second) / (a.first - b.first);
}

void add(long long k, double x) {
    while (v.size()) {
        pair<long long, double> p = v[v.size() - 1];
        if (p.first == k) {
            if (x > p.second) {
                v.pop_back();
            } else {
                break;
            }
        }
        pair<long long, double> p2 = v[v.size() - 2];
        double x1 = get(p, p2);
        double x2 = get(p, make_pair(k, x));
        if (x1 >= x2) {
            v.pop_back();
        } else {
            break;
        }
    }
    v.push_back(make_pair(k, x));
    //cout << v.size() << endl;
    /*printf("add %I64d %.5f\n", k, x);
    cout << "v : ";
    for (int i = 0; i < v.size(); ++i) {
        printf("(%I64d %.2f) ", v[i].first, v[i].second);
    }
    cout << endl;*/
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[0][i] = sum0[i] = x;
        a[1][i] = sum1[i] = 1.0 / x;
        if (i) {
            sum0[i] += sum0[i - 1];
            sum1[i] += sum1[i - 1];
        }
        ans += 1.0 * sum0[i] / x;
    }
    int q1 = 0, q2 = 1;
    for (int i = 0; i < n; ++i) {
        dp[q1][i] = 0;
    }
    for (int i = 1; i < k; ++i) {
        v.clear();
        for (int j = 0; j < i; ++j) {
            add(sum0[j], dp[q1][j] - sum1[j] * sum0[j]);
        }
        int poz = 0;
        for (int j = i; j < n; ++j) {
            poz = min(poz, (int) v.size() - 1);
            while (poz + 1 < v.size()) {
                double x = get(v[poz], v[poz + 1]);
                if (sum1[j] > x) {
                    ++poz;
                } else {
                    break;
                }
            }
            dp[q2][j] = v[poz].first * sum1[j] + v[poz].second;
            add(sum0[j], dp[q1][j] - sum1[j] * sum0[j]);
        }
        swap(q1, q2);
    }
    printf("%.10f\n", ans - dp[q1][n - 1]);
    return 0;
}