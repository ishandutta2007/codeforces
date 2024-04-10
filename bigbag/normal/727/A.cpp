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

const int max_n = 1, inf = 1111111111;

int a, b;
vector<int> ans;

bool dfs(long long x) {
    if (x > b) {
        return false;
    }
    if (x == b) {
        ans.push_back(b);
        return true;
    }
    if (dfs(2 * x)) {
        ans.push_back(x);
        return true;
    }
    if (dfs(10 * x + 1)) {
        ans.push_back(x);
        return true;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    if (dfs(a)) {
        cout << "YES" << endl << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[ans.size() - i - 1] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}