#include <iostream>
#include <deque>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <map>
#include <cassert>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    vector<int> mx(n);
    mx[n - 1] = h[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        mx[i] = max(mx[i + 1], h[i]);
    }

    for (int i = 0; i + 1 < n; ++i) {
        int d = mx[i + 1] + 1 - h[i];

        d = max(d, 0);

        cout << d << " ";
    }

    cout << 0 << endl;

    return 0;
}