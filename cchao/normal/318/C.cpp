#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long x, y, m;
    cin >> x >> y >> m;
    if(max(x, y) >= m) {
        cout << 0 << endl;
        return 0;
    }
    else if(max(x, y) <= 0) {
        cout << -1 << endl;
        return 0;
    }
    long long arr[3];
    int pos = 1;
    long long ans = 0;
    arr[1] = min(x, y), arr[2] = max(x, y);
    if(arr[1] < 0) {
        ans = (-arr[1])/arr[2];
        arr[1] += ans * arr[2];
    }
    while(arr[2] < m) {
//      cout << arr[1] << ' ' << arr[2] << endl;
        arr[0] = arr[1] + arr[2];
        ans++;
        if(arr[0] > arr[1]) swap(arr[0], arr[1]);
        if(arr[1] > arr[2]) swap(arr[1], arr[2]);
    }
    cout << ans << endl;
    return 0;
}