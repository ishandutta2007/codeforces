#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

bool x[26][26];
bool z[26];
vector<pair<int, int> > ans;

void dfs(int a) {
    z[a] = false;
    for (int i = 0; i < 26; ++i) {
        if (x[a][i] && z[i]) {
            ans.push_back(make_pair(a, i));
            dfs(i); 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    string P, Q;
    cin >> P >> Q;
    for (int i = 0; i < N; ++i) {
        if (P[i] != Q[i]) {
            x[P[i] - 'a'][Q[i] - 'a'] = x[Q[i] - 'a'][P[i] - 'a'] = true;
            z[P[i] - 'a'] = z[Q[i] - 'a'] = true;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (!z[i]) continue;
        dfs(i);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) cout << (char)(ans[i].first + 'a') << " " << (char)(ans[i].second + 'a') << endl;

    return 0;
}