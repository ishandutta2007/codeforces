#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 200100;
const int INF = 1000000000;

int x[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    
    long long temp = 0;
    long long ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; ++i) temp += x[i] == 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] == 1) ans1 += temp; else --temp;
    }
    for (int i = 0; i < n; ++i) temp += x[i] == 1;
    for (int i = n-1; i >= 0; --i) {
        if (x[i] == 0) ans2 += temp; else --temp;
    }
    
    if (ans1 < ans2) cout << ans1 << endl; else cout << ans2 << endl;

    return 0;
}