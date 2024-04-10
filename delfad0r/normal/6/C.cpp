#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int sum = 0;
    for(int n = 0; n < N; ++n) {
        cin >> A[n];
        sum += A[n];
    }
    for(int n = 0, s = 0; n <= N; ++n) {
        if(s * 2  + A[n] > sum) {
            cout << n << ' ' << (N - n) << '\n';
            break;
        }
        s += A[n];
    }
}