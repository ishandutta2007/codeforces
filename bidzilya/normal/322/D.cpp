#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int max_n = 1e2 + 10;

vector<int> atk, def, cl;
int n, m;

int build_without_def() {
    bool us[max_n];
    for (int i = 0; i < (int) cl.size(); ++i)
        us[i] = false;
    for (int i = 0; i < (int) atk.size(); ++i) {
        bool fnd = false;
        for (int j = 0; j < (int) cl.size(); ++j)
            if (!us[j] && cl[j] >= atk[i]) {
                fnd = true;
                us[j] = true;
                break;
            }
        if (!fnd) 
            return 0;
    }
    int result = 0;
    for (int i = 0; i < (int) cl.size(); ++i)
        result += cl[i];
    for (int i = 0; i < (int) atk.size(); ++i)
        result -= atk[i];
    return result;
}

int build_dp() {
    int dp[max_n][max_n];
    for (int i = 0; i <= (int) atk.size(); ++i)
        for (int j = 0; j <= (int) cl.size(); ++j)
            dp[i][j] = 0;
    for (int i = 0; i <= (int) cl.size(); ++i) {
        for (int j = 0; j <= (int) atk.size(); ++j) {
            if (i < (int) cl.size() && j < (int) atk.size() && cl[i] >= atk[j])
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + cl[i] - atk[j]);
            if (i < (int) cl.size())
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j < (int) atk.size())
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
        }
    }
    int result = 0;
    for (int i = 0; i <= (int) cl.size(); ++i)
        for (int j = 0; j <= (int) atk.size(); ++j)
                result = max(result, dp[i][j]);
    return result;
}

bool destroy_def() {
    bool us[max_n];
    for (int i = 0; i < (int) cl.size(); ++i)
        us[i] = 0;
    for (int i = 0; i < (int) def.size(); ++i) {
        bool fnd = false;
        for (int j = 0; j < (int) cl.size(); ++j)
            if (!us[j] && cl[j] > def[i]) {
                fnd = true;
                us[j] = true;
                break;
            }
        if (!fnd) {
            return false;
        }
    }
    int j = 0;
    for (int i = 0; i < (int) cl.size(); ++i)
        if (!us[i]) {
            cl[j] = cl[i];
            ++j;
        }
    m = j;
    cl.resize(m);
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string tp;
        int str;
        cin >> tp >> str;
        if (tp == "ATK") {
            atk.push_back(str);
        } else {
            def.push_back(str);
        }
    }
    cl.resize(m);
    for (int i = 0; i < m; ++i)
        cin >> cl[i];
    sort(atk.begin(), atk.end());
    sort(def.begin(), def.end());
    sort(cl.begin(), cl.end());
    int ans = 0;
    ans = max(ans, build_dp());
    if (destroy_def()) { 
        ans = max(ans, build_without_def());
    }
    cout << ans << endl;
    return 0;
}