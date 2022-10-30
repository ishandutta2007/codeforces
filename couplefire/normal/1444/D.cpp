#include <bits/stdc++.h>
using namespace std;

pair<vector<int>, vector<int>> split(vector<int> v){
    int n = v.size();
    n--;
    bitset<1010006> f[n+1];
    f[0][0] = 1;
    int sum = 0;
    for(int i = 1; i<=n; i++){
        sum += v[i];
        f[i].reset();
        f[i] = f[i-1];
        f[i] |= f[i-1]<<v[i];
    }
    if((sum&1) || !f[n][sum/2]) return {{},{}};
    vector<int> a1;
    vector<int> a2;
    int cur = sum/2;
    for(int i = n; i>=1; i--){
        if(!f[i-1][cur]) a1.push_back(v[i]), cur -= v[i];
        else a2.push_back(v[i]);
    }
    return {a1, a2};
}

bool cmp(pair<double, double> p1, pair<double, double> p2){
    return (p1.second/p1.first)<(p2.second/p2.first);
}

void solve(){
    int h, v;
    vector<int> vh, vv;
    cin >> h;
    vh.resize(h+1);
    for(int i = 0; i<h; i++) cin >> vh[i+1];
    cin >> v;
    vv.resize(v+1);
    for(int i = 0; i<v; i++) cin >> vv[i+1];
    // cout << v << " " << h << endl;
    if(v != h){
        cout << "No" << endl;
        return;
    }
    auto p1 = split(vh);
    auto p2 = split(vv);
    if(p1.first.size() == 0){
        cout << "No" << endl;
        return;
    }
    if(p2.first.size() == 0){
        cout << "No" << endl;
        return;
    }
    assert(p1.first.size()+p1.second.size() == h);
    assert(p2.first.size()+p2.second.size() == v);
    int s1 = min(p1.first.size(), p2.first.size());
    int s2 = min(p1.second.size(), p2.second.size());
    vector<pair<int, int>> v1;
    vector<pair<int, int>> v2;
    pair<int, int> x = {0, 0};
    pair<int, int> y = {0, 0};
    for(int i = 0; i<s1; i++){
        v1.push_back({p1.first[i], p2.first[i]});
        x.first += p1.first[i];
        x.second += p2.first[i];
    }
    for(int i = 0; i<s2; i++){
        v2.push_back({-p1.second[i], -p2.second[i]});
        y.first += p1.second[i];
        y.second += p2.second[i];
    }
    if(cmp(y, x)){
        v1.clear();
        v2.clear();
        swap(p1.first, p1.second);
        swap(p2.first, p2.second);
        swap(s1, s2);
        for(int i = 0; i<s1; i++){
        v1.push_back({p1.first[i], p2.first[i]});
        x.first += p1.first[i];
        x.second += p2.first[i];
    }
    for(int i = 0; i<s2; i++){
        v2.push_back({-p1.second[i], -p2.second[i]});
        y.first += p1.second[i];
        y.second += p2.second[i];
    }
    }
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    vector<int> t1;
    vector<int> t2;
    if(s1 < p1.first.size()){
        for(int i = s1; i<p1.first.size(); i++) t1.push_back(p1.first[i]);
    }
    else for(int i = s1; i<p2.first.size(); i++) t2.push_back(p2.first[i]);
    if(s2 < p1.second.size()) for(int i = s2; i<p1.second.size(); i++) t1.push_back(-p1.second[i]);
    else for(int i = s2; i<p2.second.size(); i++) t2.push_back(-p2.second[i]);
    assert(t1.size() == t2.size());
    vector<pair<int, int>> v3;
    for(int i = 0; i<t1.size(); i++) v3.push_back({t1[i], t2[i]}); 
    sort(v3.begin(), v3.end());
    assert(v1.size() + v2.size()+v3.size() == v);
    cout << "Yes" << endl;
    int curx = 0, cury = 0;
    for(auto p : v1){
        curx+=p.first;
        cout << (curx) << " " << (cury) << endl;
        cury+=p.second;
        cout << (curx) << " " << (cury) << endl;
    }
    for(auto p : v3){
        curx+=p.first;
        cout << (curx) << " " << (cury) << endl;
        cury+=p.second;
        cout << (curx) << " " << (cury) << endl;
    }
    for(auto p : v2){
        curx+=p.first;
        cout << (curx) << " " << (cury) << endl;
        cury+=p.second;
        cout << (curx) << " " << (cury) << endl;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}