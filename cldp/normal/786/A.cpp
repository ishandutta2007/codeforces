#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 7010;

int f[MAXN][2], g[MAXN][2];
int X[MAXN], Y[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int K1, K2;
    cin >> K1;
    for (int i = 0; i < K1; ++i) cin >> X[i];
    cin >> K2; 
    for (int i = 0; i < K2; ++i) cin >> Y[i];
    
    memset(f, -1, sizeof(f));
    memset(g, 0, sizeof(g));
    queue<pair<int, int> > Q;
    f[0][0] = f[0][1] = 0;
    Q.push(make_pair(0, 0));
    Q.push(make_pair(0, 1));
    
    while (!Q.empty()) {
        int a = Q.front().first;
        int b = Q.front().second;
        Q.pop();
        if (f[a][b] == 0) {
            if (b == 1) {
                for (int i = 0; i < K1; ++i) {
                    int c = (a + N - X[i]) % N;
                    if (f[c][0] != -1) continue;
                    f[c][0] = 1;
                    Q.push(make_pair(c, 0));
                }
            } else {
                for (int i = 0; i < K2; ++i) {
                    int c = (a + N - Y[i]) % N;
                    if (f[c][1] != -1) continue;
                    f[c][1] = 1;
                    Q.push(make_pair(c, 1));
                }
            }
        } else {
            if (b == 1) {
                for (int i = 0; i < K1; ++i) {
                    int c = (a + N - X[i]) % N;
                    if (f[c][0] != -1) continue;
                    ++g[c][0];
                    if (g[c][0] == K1) {
                        f[c][0] = 0;
                        Q.push(make_pair(c, 0));
                    }
                }
            } else {
                for (int i = 0; i < K2; ++i) {
                    int c = (a + N - Y[i]) % N;
                    if (f[c][1] != -1) continue;
                    ++g[c][1];
                    if (g[c][1] == K2) {
                        f[c][1] = 0;
                        Q.push(make_pair(c, 1));
                    }
                }
            }
        }
    }
    
    for (int i = 1; i < N; ++i) {
        if (f[i][0] == -1) cout << "Loop ";
        if (f[i][0] == 0) cout << "Lose ";
        if (f[i][0] == 1) cout << "Win ";
    }
    cout << endl;
    
    for (int i = 1; i < N; ++i) {
        if (f[i][1] == -1) cout << "Loop ";
        if (f[i][1] == 0) cout << "Lose ";
        if (f[i][1] == 1) cout << "Win ";
    }
    cout << endl;
    
    return 0;
}