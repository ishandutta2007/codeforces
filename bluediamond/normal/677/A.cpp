#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long int64;

const int inf = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    int n, h; cin >> n >> h;
    int result = n;
    for (int i = 0; i < n; i += 1) {
        int x; cin >> x;
        if (x > h) {
            result += 1;
        }
    }
    cout << result << '\n';
    return 0;
}