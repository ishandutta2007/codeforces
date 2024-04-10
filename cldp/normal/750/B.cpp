#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;



int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int T = 0;
    for (int i = 0; i < N; ++i) {
        int M;
        string Q;
        cin >> M >> Q;
        if ((Q == "East" || Q == "West") && (T == 0 || T == 20000)) {
            cout << "NO" << endl;
            return 0;
        }
        if (Q == "East" || Q == "West") continue;
        if (Q == "North") T -= M; else T += M;
        if (T < 0 || T > 20000) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (T == 0) 
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}