#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    map<int, int> S;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        ++S[x[i]];
    }
    for (auto iter = S.rbegin(); iter != S.rend(); ++iter) {
        if (iter->second % 2 == 0) continue;
        cout << "Conan" << endl;
        return 0;
    }
    cout << "Agasa" << endl;
    
    return 0;
}