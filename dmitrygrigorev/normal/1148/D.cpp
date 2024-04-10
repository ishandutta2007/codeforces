#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int, int> > v;
bool cmp(int a, int b){
    if (v[a].first > v[b].first) return true;
    return false;
}
bool cmp2(int a, int b){
    if (v[a].first < v[b].first) return true;
    return false;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    vector<int> mr, ls;
    for (int i=0; i < n; i++){
        if (v[i].first < v[i].second) mr.push_back(i);
        else ls.push_back(i);
    }
    if (mr.size() > ls.size()){
        sort(mr.begin(), mr.end(), cmp);
        cout << mr.size() << "\n";
        for (int i=0;i<mr.size();i++) cout << mr[i]+1 << " ";
    }
    else{
        sort(ls.begin(), ls.end(), cmp2);
        cout << ls.size() << "\n";
        for (int i=0;i<ls.size();i++) cout << ls[i]+1 << " ";
    }
}