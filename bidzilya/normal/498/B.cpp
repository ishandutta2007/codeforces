#include <bits/stdc++.h>
using namespace std;

int n, T;
vector<int> t;
vector<double> p;

vector<double> a[2];
vector<double> sa[2];

vector<double> pw;

const double eps = 1e-12;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> T;
    p.resize(n);
    t.resize(n);
    for (int i = 0; i < n; ++i) {
        int tp;
        cin >> tp >> t[i];
        p[i] = tp / 100.0;
    }

    pw.assign(n, 1.0);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < t[i]; ++j) {
            pw[i] *= (1.0 - p[i]);
            if (pw[i] < eps) {
                pw[i] = 0.0;
            }
        }
    }

    a[0].assign(T + 1, 0.0);
    sa[0].assign(T + 1, 0.0);

    a[0][0] = 1.0;

    int cur_ptr = 0;

    double answer = 0.0;

    for (int s = 0; s <= n; ++s) {
        int new_ptr = (cur_ptr + 1) & 1;
        a[new_ptr].assign(T + 1, 0.0);
        sa[new_ptr].assign(T + 1, 0.0);
        for (int cur_t = 0; cur_t <= T; ++cur_t) {
            if (s != 0 && cur_t != 0) {
                sa[cur_ptr][cur_t] += sa[cur_ptr][cur_t - 1] * (1.0 - p[s - 1]);
                if (sa[cur_ptr][cur_t] < eps) {
                    sa[cur_ptr][cur_t] = 0.0;
                }
            }
            a[cur_ptr][cur_t] += sa[cur_ptr][cur_t];
            if (a[cur_ptr][cur_t] < eps) {
                a[cur_ptr][cur_t] = 0.0;
            }

            if (s == n || cur_t == T) {
                continue;
            }

            sa[new_ptr][cur_t + 1] += a[cur_ptr][cur_t] * p[s];
            if (cur_t + t[s] <= T) {
                sa[new_ptr][cur_t + t[s]] -= a[cur_ptr][cur_t] * p[s] * pw[s];
            }
            if (cur_t + t[s] <= T) {
                a[new_ptr][cur_t + t[s]] += a[cur_ptr][cur_t] * pw[s];
            }
        }
        if (s == n) {
            double cur_answer = 0.0;
            for (int cur_t = 0; cur_t <= T; ++cur_t) {
                cur_answer += a[cur_ptr][cur_t];
            }
            cur_answer *= n;
            answer += cur_answer;
        }
        if (s < n) {
            double cur_pw = s;
            int cur_t = T;
            while (T - cur_t < t[s] && cur_t >= 0) {
                answer += a[cur_ptr][cur_t] * cur_pw;
                cur_pw *= (1.0 - p[s]);
                --cur_t;
            }
        }
        swap(new_ptr, cur_ptr);
    }

    cout << fixed << setprecision(15);
    cout << answer << endl;

    return 0;
}