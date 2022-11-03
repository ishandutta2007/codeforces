#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    int ans = 0;
    long long sm = 0;
    for (int i = 0; i < n; ++i) {
        if (t[i] >= sm) {
            sm += t[i];
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}