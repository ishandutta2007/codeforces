#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

const bool kFileInput = false;
const bool kDebugOutput = false;

int main()
{
    if (kFileInput) {
        freopen("input.txt", "r", stdin);
    }

    int n, x;
    cin >> n >> x;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (x % i == 0 && x / i <= n) {
            ++ans;
        }
    }
    cout << ans << endl;


    return 0;
}