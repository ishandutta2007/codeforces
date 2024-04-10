#include <bits/stdc++.h>
using namespace std;

int n;
long long s;
vector<pair<long long, long long>> lines;
stack<pair<long long, long long>> st;
vector<pair<pair<long long, long long>, long long>> hull;

bool cmp(pair<pair<long long, long long>, long long> a, pair<pair<long long, long long>, long long> b){
    if(a.first.second != b.first.second) return a.first.second < b.first.second;
    if(a.first.first != b.first.first) return a.first.first < b.first.first;
    return a.second<b.second;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    lines.resize(n);
    for(int i = 0; i<n; i++) cin >> lines[i].first >> lines[i].second;
    sort(lines.begin(), lines.end());
    for(int i = 0; i<n; i++){
        if(!st.empty() && st.top().first == lines[i].first) continue;
        while(!st.empty() && st.top().second >= lines[i].second) st.pop();
        st.push(lines[i]);
    }
    lines.clear();
    while(!st.empty()){
        lines.push_back(st.top());
        st.pop();
    }
    reverse(lines.begin(), lines.end());
    // for(auto x : lines) cout << x.first << " " << x.second << endl;
    hull.push_back({{0, 0}, lines.front().first});
    for(int i = 1; i<lines.size(); i++){
        int posFirst = lower_bound(hull.begin(), hull.end(), make_pair(make_pair(-1ll, lines[i].second+1),-1ll), cmp)-hull.begin()-1;
        // cout << posFirst << endl;
        long long t = (lines[i].second-hull[posFirst].first.second+hull[posFirst].second-1)/hull[posFirst].second+hull[posFirst].first.first;
        long long px = t;
        long long py = (t-hull[posFirst].first.first)*hull[posFirst].second+hull[posFirst].first.second-lines[i].second;
        if(posFirst != hull.size()-1 && t >= hull[posFirst+1].first.first){
            py = hull[posFirst+1].first.second-lines[i].second;
            px = hull[posFirst+1].first.first;
        }
        while((hull.back().first.first-px)*lines[i].first+py >= hull.back().first.second) hull.pop_back();
        assert(!hull.empty());
        t = (hull.back().first.second-hull.back().first.first*hull.back().second-py+px*lines[i].first+lines[i].first-hull.back().second-1)/(lines[i].first-hull.back().second);
        // cout << t << endl;
        hull.push_back({{t, py+(t-px)*lines[i].first}, lines[i].first});
    }
    int cur = hull.size()-1;
    while(hull[cur].first.second > s) cur--;
    long long t = (s-hull[cur].first.second+hull[cur].second-1)/hull[cur].second+hull[cur].first.first;
    cout << t << endl;
}