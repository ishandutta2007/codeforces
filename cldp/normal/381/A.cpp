#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 1100;
const int INF = 1000000000;


int x[MAXN];

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) cin >> x[i];
    
    int l = 0, r = n - 1;
    int ans[2], turn = 0;
    ans[0] = ans[1] = 0;
    while (l <= r) {
        if (x[l] > x[r]) {
            ans[turn] += x[l];
            ++l;
        } else {
            ans[turn] += x[r];
            --r;
        }
        turn = (turn + 1) % 2;
    }
    
    cout << ans[0] << " " << ans[1] << endl;
    
    return 0;
}