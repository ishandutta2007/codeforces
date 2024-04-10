#include <iostream>
using namespace std;

const int MAXN = 200010;

int x[MAXN], s[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, K, Q;
    cin >> N >> K >> Q;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        
        ++x[a];
        --x[b + 1];
    }
    int temp = 0;
    for (int i = 1; i <= 200000; ++i) {
        temp += x[i];
        s[i] = s[i - 1];
        if (temp >= K) ++s[i];
    }
    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << s[b] - s[a - 1] << endl;
    }  
    return 0;
}