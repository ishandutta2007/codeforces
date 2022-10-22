#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);


int main() {
    ios_base::sync_with_stdio(false);
    string Q;
    cin >> Q;
    int ans = 0;
    for (int i = 0; i < Q.size(); ++i) {
        if (Q[i] == 'a' || Q[i] == 'e' || Q[i] == 'i' || Q[i] == 'o' || Q[i] == 'u') ++ans;
        if (Q[i] == '1' || Q[i] == '3' || Q[i] == '5' || Q[i] == '7' || Q[i] == '9') ++ans;

    }
    cout << ans << endl;
    return 0;
}