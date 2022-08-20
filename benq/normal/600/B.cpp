#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool temp(int a, int b) {
    if (a <= b) return true;
    return false;
}

int main() {
    int a[200001];
    int n, m, b;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> v(a,a+n);
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < m; ++i) {
        cin >> b;
        cout << (lower_bound(v.begin(),v.end(),b, temp)-v.begin());
        if (i < m-1) {
            cout << " ";
        }
    }
}