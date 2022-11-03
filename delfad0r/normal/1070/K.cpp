#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
ifstream input_from_file("input.txt");
#define cin input_from_file
#endif

typedef long long LL;
typedef pair<int, int> II;

const int MAX_N = 100010;
int N, K;
int S, cnt;
int A[MAX_N], s[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S += A[i];
    }
    
    if (S % K != 0) {
        cout << "No\n";
        return 0;
    }
    
    S /= K;
    int last = -1, d = 0;
    for (int i = 0; i < N; i++) {
        d += A[i];
        if (d > S) {
            cout << "No\n";
            return 0;
        }
        if (d == S) {
            s[cnt++] = i - last;
            d = 0;
            last = i;
        }
    }
    
    if (last != N - 1) {
        cout << "No\n";
        return 0;
    }
    
    cout << "Yes\n";
    for (int i = 0; i < K; i++)
        cout << s[i] << " ";
    cout << "\n";
    
    return 0;
    
}