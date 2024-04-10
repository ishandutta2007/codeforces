#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*
DP[i][j] = the minimum cost to make the product of the first i
numbers equal 1 (if j = 0) or -1 (if j = 1)
*/

inline int abs(int x) {
    if(x < 0) return -x;
    else return x;
}

long long DP[100005][2];

int main() {
    int n; cin >> n;
    memset(DP, 1, sizeof DP);
    for(int i=0; i<n; i++) {
        int v; cin >> v;
        int a = abs(v-1), b = abs(v+1);
        if(i == 0) {
            DP[i][0] = a;
            DP[i][1] = b;
        } else {
            DP[i][0] = min(DP[i-1][0] + a, DP[i-1][1] + b);
            DP[i][1] = min(DP[i-1][1] + a, DP[i-1][0] + b);
        }
    }
    cout << DP[n-1][0] << endl;
}