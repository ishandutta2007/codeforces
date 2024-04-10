#include<bits/stdc++.h>
using namespace std;

#define maxn 101010
#define left __left
#define right __right
int n;
int x[maxn], left[maxn], right[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = n; i--; ) {
        int h;
        cin >> x[i] >> h;
        left[i] = x[i] - h;
        right[i] = x[i] + h;
    }
    vector<int> vals;
    vals.push_back(INT_MIN);
    vals.insert(vals.end(), x, x + n);
    vals.insert(vals.end(), left, left + n);
    vals.insert(vals.end(), right, right + n);
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    vector<int> pos(vals.size(), -1);
    vector<int> has_tree(vals.size());

    for (int i = n; i--; ) {
        x[i] = (int)(lower_bound(vals.begin(), vals.end(), x[i]) - vals.begin());
        left[i] = (int)(lower_bound(vals.begin(), vals.end(), left[i]) - vals.begin());
        right[i] = (int)(lower_bound(vals.begin(), vals.end(), right[i]) - vals.begin());
        pos[x[i]] = i;
        has_tree[x[i]] = 1;
    }
    
    for (int i = 0; i < vals.size() - 1; ++i) 
        has_tree[i + 1] += has_tree[i];
    
    vector<int> dp(vals.size());
    for (int i = 1; i < (int)vals.size(); ++i) {
        dp[i] = max(dp[i], dp[i - 1]);
        if (pos[i] == -1) continue;
        int u = pos[i];
        if (has_tree[i - 1] - has_tree[left[u] - 1] == 0)
            dp[i] = max(dp[i], dp[left[u] - 1] + 1);
        if (has_tree[right[u]] - has_tree[i] == 0)
            dp[right[u]] = max(dp[right[u]], dp[i - 1] + 1);
    }
    
    cout << dp.back();
    
    return 0;
}