#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <vector>

#define int long long

using namespace std;
signed main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    int ans = 0, s=0;
    for (int i=0; i < n; i++){
        if (v[i] == 0) ans += s;
        else s++;
    }
    cout << ans;
    
}