#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1100;
const int INF = 1000000000;


int main() {
    int n;
    cin >> n;
    vector<int> x(n, 0);
    for (int i = 0; i < n; ++i) cin >> x[i];
    sort(x.begin(), x.end());
    vector<int> l, r;
    for (int i = 0; i < n; ++i) {
        if (l.empty() || x[i] > l[l.size() - 1]) {
            l.push_back(x[i]);
            continue;
        }
        if (r.empty() || x[i] > r[r.size() - 1]) {
            r.push_back(x[i]);
            continue;
        }
    }
    if (!r.empty() && l[l.size() - 1] == r[r.size() - 1]) r.erase(r.end() - 1);
    
    cout << l.size() + r.size() << endl;
    cout << l[0];
    for (int i = 1; i < l.size(); ++i) cout << " " << l[i];
    for (int i = r.size() - 1; i >= 0; --i) cout << " " << r[i];
    cout << endl;

    return 0;
}