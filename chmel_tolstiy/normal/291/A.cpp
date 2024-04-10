#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x) v.push_back(x);
    }
    sort(v.begin(), v.end());
    
    int res = 0;
    int cur = 0;
    
    while (cur + 1 < v.size()) {
        if (v[cur] == v[cur + 1]) ++res;
        if (cur + 2 < v.size() && v[cur] == v[cur + 2]) {
            cout << -1 << endl;
            return 0;
        }
        ++cur;
    }
    
    cout << res << endl;
    return 0;
}