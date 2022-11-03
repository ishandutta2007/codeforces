#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    string S;
    cin >> S;
    pair<int, int> best_swap = {0, 0};
    vector<int> v(N, 0);
    for(int n = 0; n < N; ++n) {
        v[n] = 1 - 2 * int(S[n] == ')');
    }
    for(int n = 1; n < N; ++n) {
        v[n] += v[n - 1];
    }
    if(v.back() != 0) {
        cout << "0\n1 1\n";
        return 0;
    }
    int m = *min_element(v.begin(), v.end());
    int ans = count(v.begin(), v.end(), m);
    vector<int> u(N + 1, 0), u1(N + 1, 0), u2(N + 1, 0);
    for(int n = 0; n < N; ++n) {
        if(v[n] == m) {
            ++u[n + 1];
        } else if(v[n] == m + 1) {
            ++u1[n + 1];
        } else if(v[n] == m + 2) {
            ++u2[n + 1];
        }
    }
    for(int n = 1; n <= N; ++n) {
        u[n] += u[n - 1];
        u1[n] += u1[n - 1];
        u2[n] += u2[n - 1];
    }
    auto bs = [](const auto& w, int f, int lo, int hi) {
        while(lo + 1 < hi) {
            int m = (lo + hi) / 2;
            if(w[m] >= f) {
                hi = m;
            } else {
                lo = m;
            }
        }
        return hi;
    };
    int first_min = bs(u, 1, 0, N) - 1;
    int first_min1 = bs(u1, 1, -1, N) - 1;
    for(int n = 0; n < N; ++n) {
        if(S[n] == '(') {
            if(u[N] - u[n] > 0) { //more minimums ahead, skip
                continue;
            }
            int n1 = u1[N] - u1[n] + u1[first_min] - u1[0];
            int n2 = u2[N] - u2[n] + u2[first_min] - u2[0] + u[n] - u[first_min];
            if(n1 > 0) {
                if(ans < n1) {
                    best_swap = {n, first_min};
                    ans = n1;
                }
            } else {
                if(ans < n2) {
                    best_swap = {n, first_min};
                    ans = n2;
                }
            }
            if(first_min1 >= 0 and first_min1 < first_min and u1[N] - u1[n] == 0) {
                int n3 = u2[N] - u2[n] + u2[first_min1] - u2[0] + u[n] - u[first_min1];
                if(ans < n3) {
                    best_swap = {n, first_min1};
                    ans = n3;
                }
            }
        } else {
            int i = bs(u1, u1[n], -1, n);
            int j = bs(u, u[n], -1, n);
            i = max(i, j);
            int n1 = u1[n] - u1[j];
            if(n1 > ans) {
                best_swap = {n, j};
                ans = n1;
            }
            int n2 = u[N] - u[n] + u[i] - u[0] + u2[n] - u2[i];
            if(n2 > ans) {
                best_swap = {n, i};
                ans = n2;
            }
        }
    }
    
    cout << ans << "\n" << best_swap.first + 1 << " " << best_swap.second + 1 << "\n";
    //cout << ans << "\n";
    
    return 0;
}