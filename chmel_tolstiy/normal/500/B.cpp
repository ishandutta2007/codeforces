#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<string> f(n);
    for (int i = 0; i < n; ++i) cin >> f[i];
    
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (f[i][k] == '1' && f[k][j] == '1')
                    f[i][j] = '1';
     vector<int> b(n);
     for (int i = 0; i < n; ++i) if (b[i] == 0) {
        vector<int> id;
        for (int j = 0; j < n; ++j) if (j == i || f[j][i] == '1')
            id.push_back(j);
        vector<int> val;
        for (int j = 0; j < id.size(); ++j)
            val.push_back(a[id[j]]);
        sort(val.begin(), val.end());
        for (int j = 0; j < id.size(); ++j)
            b[id[j]] = val[j];
     }
     for (int i = 0; i < b.size(); ++i) {
         if (i) cout << ' ';
         cout << b[i];
     }
     cout << endl;
     return 0;
}