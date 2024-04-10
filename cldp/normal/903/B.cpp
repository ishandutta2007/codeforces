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
    int h1, a1, c1, h2, a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    vector<string> ans;
    while (true) {
        if (h2 <= a1) {
            ans.push_back("STRIKE");
            break;
        }
        if (h1 > a2) {
            ans.push_back("STRIKE");
            h1 -= a2;
            h2 -= a1;
        } else {
            ans.push_back("HEAL");
            h1 -= a2 - c1;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
    return 0;
}