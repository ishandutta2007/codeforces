#include <bits/stdc++.h>

using namespace std;

#define long int64_t
#define DV(a) (" [" #a "=" + to_string(a) + "]")

// *****

auto solve() {
    int N, L;
    cin >> N >> L;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int balance = 0;
    int max_since = L;
    int events = 0;
    for (int i = 0; i < N; i++) {
        balance += A[i];
        if (A[i] == 0 && balance < 0) {
            int increment = -balance;
            if (max_since + increment <= L) {
                max_since += increment;
            } else {
                events++;
                max_since = 0;
            }
            balance = 0;
        }
        max_since = max(max_since, balance);
        if (balance > L) {
            return -1;
        }
    }
    return events;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}