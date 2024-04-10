#include <iostream>
using namespace std;

const int MAXN = 200010;

long long A[MAXN], B[MAXN], C[MAXN];
long long D[31];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> B[i];
    for (int i = 0; i < N; ++i) cin >> C[i];
    long long sum = 0;
    for (int i = 0; i < N; ++i) sum += B[i] + C[i];
    if (sum % (N + N) != 0) {
        cout << -1 << endl;
        return 0;
    }
    sum /= N + N;
    for (int i = 0; i < N; ++i) {
        A[i] = B[i] + C[i] - sum;
        if (A[i] % N != 0) {
            cout << -1 << endl;
            return 0;
        }
        A[i] /= N;
        for (int j = 0; j < 31; ++j) D[j] += ((A[i] & (1 << j)) > 0);
    }
    
    for (int i = 0; i < N; ++i) {
        long long BB = 0, CC = 0;
        for (int j = 0; j < 31; ++j) {
            if (A[i] & (1 << j)) {
                BB += D[j] * (1LL << j);
                CC += N * (1LL << j);
            } else {
                CC += D[j] * (1LL << j);
            }
        }
        if (BB != B[i] || CC != C[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < N; ++i) cout << A[i] << " ";
    cout << endl;

    return 0;
}