#include <bits/stdc++.h>

using namespace std;

int N, K, M, A;
int V[200], T[200];
int V0[200], T0[200];
int id[200];

int main() {
    cin >> N >> K >> M >> A;
    for(int a = 0; a < A; ++a) {
        int g;
        cin >> g;
        --g;
        V[g]++;
        T[g] = a;
    }
    if(N == 1) {
        cout << 1 << '\n';
        return 0;
    }
    for(int n = 0; n < N; ++n) {
        bool can_win, can_lose;
        memcpy(T0, T, N * sizeof(int));
        memcpy(V0, V, N * sizeof(int));
        V0[n] += M - A;
        T0[n] = (M == A) ? (T[n]) : (M - 1);
        iota(id, id + N, 0);
        sort(id, id + N, [&](int i, int j) { return V0[i] > V0[j] || (V0[i] == V0[j] && T0[i] < T0[j]); });
        if(V0[n] > 0 && find(id, id + N, n) - id < K) {
            can_win = true;
        } else {
            can_win = false;
        }
        iota(id, id + N, 0);
        sort(id, id + N, [&](int i, int j) { return V[i] > V[j] || (V[i] == V[j] && T[i] < T[j]); });
        if(find(id, id + N, n) - id >= K || V[n] == 0) {
            can_lose = true;
        } else if(K == N) {
            can_lose = false;
        } else {
            int j = 0;
            for(int i = find(id, id + N, n) - id + 1; i <= K; ++i) {
                j += V[n] + 1 - V[id[i]];
            }
            can_lose = (j <= M - A);
        }
        if(can_win) {
            if(can_lose) {
                cout << 2;
            } else {
                cout << 1;
            }
        } else {
            cout << 3;
        }
        cout << ' ';
    }
    cout << '\n';
}