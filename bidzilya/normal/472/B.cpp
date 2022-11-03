#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

typedef long long ll;

int n, k;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int ans = 0;

    for (int i = 0; i < n; i += k) {
        ans += 2 * a[i];
    }
    
    cout << ans << endl;
    
    return 0;
}