#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 200100;
const int MAXM = 1100;
const int INF = 2000000000;


int x[MAXN], y[MAXN];
map<int, int> yy;


int main() {
    int n, m;
    long long p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        yy[x[i]] = 0;
    }
    for (int j = 0; j < m; ++j) {
        cin >> y[j];
        ++yy[y[j]];
    }
    
    vector<int> ans;
    for (int k = 0; k < p; ++k) {
        if ((long long)k + (long long)(m-1) * p >= n) break;
        int start = k;
        map<int, int> z;
        for (int i = 0; i < m; ++i) {
            ++z[x[start]];
            start += p;
        }
        set<int> wrong;
        map<int, int>::iterator iter = yy.begin();
        while (iter != yy.end()) {
            int a = iter->first;
            ++iter;
            if (z.find(a) != z.end()) {
                if (z[a] != yy[a]) wrong.insert(a);
            } else
                if (yy[a] != 0) {
                    wrong.insert(a);
                }
        }
        
        if (wrong.size() == 0) {
            ans.push_back(start - m * p);
        }
        
        while (start < n) {
            int temp = start - m * p;
            --z[x[temp]];
            if (yy[x[temp]] == z[x[temp]]) {
                wrong.erase(x[temp]);
                //cout<< "Erase " << x[temp] << endl;
            } else {
                wrong.insert(x[temp]);
                //cout<< "Insert " << x[temp] << endl;
            }
            ++z[x[start]];
            if (yy[x[start]] != z[x[start]]) {
                wrong.insert(x[start]);
                //cout<< "Insert " << x[start] << endl;
            } else {
                wrong.erase(x[start]);
                //cout<< "Erase " << x[start] << endl;
            }
            start += p;
            if (wrong.size() == 0) {
                ans.push_back(start - m * p);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    if (ans.size() > 0) {
        cout << ans[0] + 1;
        for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i] + 1;
        cout << endl;
    }
    
    
    return 0;
}