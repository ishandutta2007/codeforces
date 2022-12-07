#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

vector<int> solve(int start, int end, vector<int> &v) {
    int n = (int)v.size();
    int left = -1;
    int right = -1;
    int neg = 0;
    int two = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] < 0) {
            if(left == -1) left = i;
            right = i;
            neg++;
        }
        if(abs(v[i]) == 2) {
            two++;
        }
    }
    if(neg % 2 == 0) return {start, end, two};
    int first = 0;
    int second = 0;
    for(int i = left + 1; i < n; i++) {
        if(abs(v[i]) == 2) first++;
    }
    for(int i = 0; i < right; i++) {
        if(abs(v[i]) == 2) second++;
    }
    // cout << left << " " << right << endl;
    // cout << first << " " << second << endl;
    if(first > second) {
        return {start + left + 1, end, first};
    } else {
        return {start, end + (n - right), second};
    }
}

void solve() {
    int n;
    cin >> n;
    deque <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> ans;
    ans.push_back({n, 0, 0});
    int rem = 0;
    while(true) {
        vector<int> temp;
        while((int)v.size() > 0 && v[0] != 0) {
            temp.push_back(v[0]);
            v.pop_front();
            rem++;
        }
        if((int)temp.size() != 0) ans.push_back(solve(rem - (int)temp.size(), (int)v.size(), temp));
        // if((int)temp.size() != 0) ans.push_back({rem - (int)temp.size(), (int)v.size(), solve(temp)});
        if((int)v.size() > 0) {
            v.pop_front();
            rem++;
        } else {
            break;
        }
    }
    // for(auto i : ans) {
    //     cout << i[0] << " " << i[1] << " " << i[2] << endl;
    // }
    // cout << endl;
    sort(ans.begin(), ans.end(), [&](vector<int> a, vector<int> b) {
        return a[2] > b[2];
    });
    cout << ans[0][0] << " " << ans[0][1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}