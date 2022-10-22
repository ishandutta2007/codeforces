#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 1100;
const int INF = 1000000007;

int f[2100][2100];
vector<int> X[2100];


int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
     for (int j = 1; j <= i; ++j)
      if (i % j == 0) X[i].push_back(j);
    
    
    for (int i = 1; i <= N; ++i) f[1][i] = 1;
    for (int i = 2; i <= K; ++i) {
        for (int j = 1; j <= N; ++j) {
            f[i][j] = 0;
            for (int k = 0; k < X[j].size(); ++k) f[i][j] = (f[i][j] + f[i - 1][X[j][k]]) % INF;
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= N; ++i) ans = (ans + f[K][i]) % INF;
    cout << ans << endl;

    return 0;
}