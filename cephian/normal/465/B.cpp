#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<bool> v;
    while(n--) {
        bool b;
        cin >> b;
        v.push_back(b);
    }
    v.push_back(0);
    bool l0 = true;
    int streak = 0;
    int ans = -1;
    for(int i = 0; i < v.size(); ++i) {
        if(v[i]) {
            l0 = 0;
            ++streak;
        } else if(!l0) {
            ans += 1 + streak;
            l0 = 1;
            streak = 0;
        }
    }
    ans = max(ans, 0);
    cout << ans << "\n";
    
}