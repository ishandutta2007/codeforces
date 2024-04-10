#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
cin >> n;
vector<int> a(n);
for (int i = 0; i < n; i++)
    cin >> a[i];
map<int, vector<pair<int,int>>> segs;
for (int r = 0; r < n; r++) {
    int sum = 0;                              
    for (int l = r; l >= 0; l--) {
        sum += a[l];
        segs[sum].push_back({l, r});
    }
}
int result = 0;
vector<pair<int,int>> best;
for (const auto& p: segs) {
    const vector<pair<int,int>>& pp = p.second;
    int cur = 0;
    int r = -1;
    vector<pair<int,int>> now;
    for (auto seg: pp)
        if (seg.first > r) {
            cur++;
            now.push_back(seg);
            r = seg.second;
        }
    if (cur > result) {
        result = cur;
        best = now;
    }
}
cout << result << endl;
for (auto seg: best)
    cout << seg.first + 1 << " " << seg.second + 1 << endl;
}