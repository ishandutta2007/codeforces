#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100005;
const int B = 330;

int floor_div(int a, int b){return a/b-(a%b<0);}

struct line{
    int m, b, id;
    int insect(line& o){return floor_div(o.b-b, m-o.m);}
    int eval(int x){return m*x+b;}
};

int n, slope[N], order[N], offset[N], pre[N], suf[N];
vector<line> hull[N];
bool used[N];

void build(vector<line>& hull, int l, int r){
    hull.clear();
    for(int i = l; i<r; i++){
        if(used[order[i]]) continue;
        line l = {slope[order[i]], offset[order[i]], order[i]};
        if(!hull.empty() && hull.back().m == l.m){
            if(hull.back().b < l.b) hull.pop_back();
            else continue;
        }
        while((int)hull.size()>=2 && hull.back().insect(l) >= hull[(int)hull.size()-2].insect(hull.back()))
            hull.pop_back();
        hull.push_back(l);
    }
}

pair<int, int> query(vector<line>& hull, int x){
    if(hull.empty()) return {LLONG_MIN, -1};
    while((int)hull.size() >= 2 && hull.back().eval(x) < hull[(int)hull.size()-2].eval(x))
        hull.pop_back();
    return {hull.back().eval(x), hull.back().id};
}

signed main(){
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> slope[i];
    iota(order, order+n, 0);
    for(int i = 0; i<=(n-1)/B; i++){
        sort(order+i*B, order+min(n, (i+1)*B), [&](int a, int b){return slope[a]>slope[b];});
        build(hull[i], i*B, min(n, (i+1)*B));
    }
    int ans = 0, cur = 0;
    for(int i = 0; i<n; i++){
        pair<int, int> best = {LLONG_MIN, -1};
        for(int j = 0; j<=(n-1)/B; j++){
            pair<int, int> tmp = query(hull[j], pre[j]+1);
            if(tmp.first > LLONG_MIN)
                tmp.first += suf[j];
            best = max(best, tmp);
        }
        int u = best.second, v = u/B;
        cur += best.first;
        ans = max(ans, cur);
        used[u] = 1;
        for(int j = v*B; j<min(n, (v+1)*B); j++)
            if(j < u) offset[j] += slope[u];
            else if(j > u) offset[j] += slope[j];
        build(hull[v], v*B, min(n, (v+1)*B));
        for(int j = 0; j<=(n-1)/B; j++)
            if(j < v) suf[j] += slope[u];
            else if(j > v) pre[j]++;
    }
    cout << ans << endl;
}