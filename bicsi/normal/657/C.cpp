#include <bits/stdc++.h>

using namespace std;

int T[500000];
long long S[500000];
priority_queue<long long> Q;

long long nows, k, n;

void InsertQ(long long val) {
    Q.push(val);
    nows += val;

    if(Q.size() > k) {
        nows -= Q.top();
        Q.pop();
    }
}

int main() {
//    freopen("debug", "r", stdin);

    int b, c;
    cin >> n >> k >> b >> c;

    for(int i = 1; i <= n; ++i) {
        cin >> T[i];
    }
    sort(T + 1, T + n + 1);

    for(int i = 1; i <= n; ++i) {
        S[i] = S[i - 1] + T[i];
    }

    if(b >= 5 * c) {
        long long best = 1e18;
        for(int i = k; i <= n; ++i) {
            best = min(best, 1LL * T[i] * k - S[i] + S[i - k]);
        }
        cout << best * c << '\n';
        return 0;
    } else {
        long long best = 1e18;

        for(int i = 0; i < 5; ++i) {

            long long bring_to = 2e9;

            for(int i = 1; i <= n; ++i) {
                int val = T[i];
                long long cost_needed = 0;
                while(val % 5) {cost_needed += c; val += 1;}
                cost_needed -= 1LL * b * (val / 5);
                InsertQ(cost_needed);

                if(i >= k) {
                    best = min(best, nows + 1LL * k * b * (val / 5));
                }
            }


            for(int i = 1; i <= n; ++i) {
                T[i] += 1;
            }

            for(int i = 0; i < 5; ++i)
                while(!Q.empty()) Q.pop();
            nows = 0;
        }

        cout << best;
        return 0;
    }

    return 0;
}