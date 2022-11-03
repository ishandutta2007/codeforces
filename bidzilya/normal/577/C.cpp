#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

const bool kFileInput = false;
const bool kDebugOutput = false;

bool IsPrime(int x)
{
    if (x == 1) {
        return false;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    if (kFileInput) {
        freopen("input.txt", "r", stdin);
    }

    int n;
    cin >> n;

    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (IsPrime(i)) {
            int x = i;
            while (x <= n) {
                ans.push_back(x);
                x *= i;
            }
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}