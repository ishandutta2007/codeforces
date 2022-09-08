#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 333, inf = 111111111;

int n, a[max_n], b[max_n];
map<int, vector<int> > m;
vector < pair <int, int> > ans;

int good() {
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    while (true) {
        int poz = good();
        if (poz == -1) {
            break;
        }
        //cout << poz << endl;
        for (int i = poz; i < n; ++i) {
            if (a[poz] == b[i]) {
                while (i != poz) {
                    swap(b[i], b[i - 1]);
                    ans.push_back(make_pair(i - 1, i));
                    --i;
                }
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    }
    return 0;
}