#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;

bool z[MAXN];
set<int> X[MAXN];
int y[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    int N, A, a;
    cin >> N >> A;
    for (int i = 1; i <= 1000000; ++i) X[0].insert(i);
    for (int i = 0; i < N; ++i) {
        cin >> a;
        if (a == A) {
            for (auto &iter : X[y[a]]) z[iter] = true;
            ++y[a];
        } else {
            if (z[a]) continue;
            X[y[a]].erase(a);
            X[++y[a]].insert(a);
        }
    }
    if (X[y[A]].find(A) != X[y[A]].end()) X[y[A]].erase(A);
    for (int i = y[A]; i <= N; ++i) {
        if (X[i].size() > 0) {
            cout << *X[i].begin() << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}