#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

bool z[400];

int main() {
    ios_base::sync_with_stdio(false);
    string P;
    int N;
    cin >> N;
    cin >> P;
    z['a'] = z['e'] = z['i'] = z['o'] = z['u'] = z['y'] = true;
    while (true) {
        bool flag = false;
        for (int i = 0; i + 1 < P.size(); ++i) {
            if (z[P[i]] && z[P[i + 1]]) {
                P = P.substr(0, i + 1) + P.substr(i + 2);
                flag = true;
                break;
            }
        }
        if (!flag) break;
    }
    cout << P << endl;

    return 0;
}