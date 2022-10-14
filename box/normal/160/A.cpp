#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int tot = 0, n; cin >> n;
    vector<int> aray;
    for(int i=0; i<n; i++) {
        int v; cin >> v;
        tot += v; aray.push_back(v);
    }
    sort(aray.begin(), aray.end());
    int a = 0, b = tot;
    while(a <= b) {
        a += aray.back(); b -= aray.back();
        aray.pop_back();
    }
    cout << n - aray.size() << endl;
}