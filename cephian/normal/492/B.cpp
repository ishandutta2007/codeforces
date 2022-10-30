#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int lanterns[1000];

int main() {
    ios::sync_with_stdio(0);
    
    int n, l;
    cin >> n >> l;
    cout << setprecision(10) << fixed;
    for(int i = 0; i < n; ++i)
        cin >> lanterns[i];
    
    sort(lanterns, lanterns + n);
    
    double ans = max(lanterns[0], l - lanterns[n-1]);
    for(int i = 1; i < n; ++i) {
        ans = max(ans, (lanterns[i]-lanterns[i-1])/2.0);
    }
    cout << ans << "\n";
    
    return 0;
}