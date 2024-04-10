#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;
    int q[n];
    for(int i = 0; i < n; ++i)
        cin >> q[i];
    int bus = 0;
    int ans = 1;
    for(int i = 0; i < n; ++i) {
        if(bus + q[i] > m) {
            ++ans;
            bus = 0;
        }
        bus += q[i];
    }
    cout << ans << "\n";
}