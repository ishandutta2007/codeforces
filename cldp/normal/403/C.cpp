#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 2100;
const int INF = 1000000000;

int N, count;
int x[MAXN][MAXN];
bool z[MAXN];

int dfs(int a) {
    z[a] = true;
    ++count;
    for (int i = 0; i < N; ++i) {
        if (z[i] || x[a][i] == 0) continue;
        dfs(i);
    }
    return 0;
}

int dfsN(int a) {
    z[a] = true;
    ++count;
    for (int i = 0; i < N; ++i) {
        if (z[i] || x[i][a] == 0) continue;
        dfsN(i);
    }
    return 0;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
     for (int j = 0; j < N; ++j) scanf("%d", &x[i][j]);
    
    bool flag = true;
    memset(z, 0, sizeof(z));
    count = 0;
    dfs(0);
    if (count != N) flag = false;
    
    memset(z, 0, sizeof(z));
    count = 0;
    dfsN(0);
    if (count != N) flag = false;
    
    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    

    return 0;
}