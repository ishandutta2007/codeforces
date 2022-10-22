#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1510;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int D = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> x[i];
        for (int j = 1; j < i; ++j) {
            if (x[j] > x[i]) ++D;
        }
    }
    D %= 2;
    int M, a, b;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        int L = (b - a + 1);
        int K = L * (L - 1) / 2;
        if (K & 1) D = 1 - D;
        if (D) cout << "odd" << endl; else cout << "even" << endl;
    }
    
    return 0;
}