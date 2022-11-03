#include <bits/stdc++.h>
using namespace std;

const int kMaxItr = 100;

int main()
{
    ios_base::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;
    vector<int> x(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> b[i];
    }
    x[0] = 0;
    b[0] = 0;
    ++n;
    vector<vector<double> > dx(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dx[i][j] = sqrt(abs((x[j] - x[i]) - l));
        }
    }
    int all_b = 0;
    for (int i = 0; i < n; ++i) {
        all_b += b[i];
    }
    double bl = 0.0;
    double br = 1.0 * (x[n - 1] - x[0]) / all_b;
    vector<int> ans_x;
    for (int i = 1; i < n; ++i) {
        ans_x.push_back(i);
    }
    vector<double> dist(n);
    vector<int> p(n);
    for (int itr = 0; itr < kMaxItr; ++itr) {
        double R = (bl + br) / 2.0;

        dist[0] = 0.0;
        for (int i = 1; i < n; ++i) {
            dist[i] = dist[i - 1] + dx[i - 1][i] - R * b[i];
            p[i] = i - 1;

            for (int j = 0; j < i; ++j) {
                double cur_val = dist[j] + dx[j][i] - R * b[i];
                if (cur_val < dist[i]) {
                    dist[i] = cur_val;
                    p[i] = j;
                }
            }
        }

        if (dist[n - 1] <= 0.0) {
            ans_x.clear();
            for (int v = n - 1; v != 0; v = p[v]) {
                ans_x.push_back(v);
            }
            reverse(ans_x.begin(), ans_x.end());
            br = R;
        } else {
            bl = R;
        }
    }
    for (int i = 0; i < (int) ans_x.size(); ++i) {
        cout << ans_x[i] << " ";
    }

    return 0;
}