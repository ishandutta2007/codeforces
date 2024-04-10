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
    string P, Q;
    cin >> P >> Q;
    vector<string> ans;
    for (int i = 0; i < P.size(); ++i) {
        for (int j = 0; j < Q.size(); ++j) {
            string R = P.substr(0, i + 1) + Q.substr(0, j + 1);
            ans.push_back(R);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;
    return 0;
}