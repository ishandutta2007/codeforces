#include <map>
#include <set>
#include <stack>
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

const int max_n = 333, inf = 1111111111;

int n, a[max_n][max_n], b[max_n];
vector<int> ans;
string s;

void add(int num) {
    ans.push_back(num + 1);
    for (int i = 0; i < n; ++i) {
        b[i] -= a[num][i];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            a[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (b[j] == 0) {
                add(j);
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}