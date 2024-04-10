#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 1;

    int prev = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1]) {
            ++prev;
        } else {
            prev = 1;
        }
        ans = max(ans, prev);
    }
    cout << ans << endl;


    return 0;
}