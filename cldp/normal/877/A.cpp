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
    string P[5];
    P[0] = "Danil";
    P[1] = "Olya";
    P[2] = "Slava";
    P[3] = "Ann";
    P[4] = "Nikita";
    string Q;
    cin >> Q;
    int ans = 0;
    for (int i = 0; i < Q.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            if (Q.substr(i, P[j].size()) == P[j]) ++ans;
        }
    }
    if (ans == 1) cout << "YES" << endl; else cout << "NO" << endl;
    return 0;
}