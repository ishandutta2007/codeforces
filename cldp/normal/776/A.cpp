#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 2010;



int main() {
    ios_base::sync_with_stdio(false);
    string P, Q;
    int N;
    cin >> P >> Q;
    cin >> N;
    cout << P << " " << Q << endl;
    for (int i = 0; i < N; ++i) {
        string R, S;
        cin >> R >> S;
        if (R == P) P = S; else Q = S;
        cout << P << " " << Q << endl;
    }
    return 0;
}