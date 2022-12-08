#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Frac{
    ll a, b;
    Frac(){}
    Frac(ll _a, ll _b){
        ll g = __gcd(_a, _b);
        a = _a / g, b = _b / g;
    }

    void dd(){
        ll g = __gcd(a, b);
        a/=g, b/=g;
    }

    Frac add1(){
        return Frac(a+b, b);
    }
    Frac sub1(){
        return Frac(a-b, b);
    }

    bool operator<(const Frac &r)const{
        return make_pair(a, b) < make_pair(r.a, r.b);
    }

    bool operator==(const Frac &r)const{
        return a==r.a && b==r.b;
    }

    Frac operator/(const Frac &r)const{
        return Frac(a * r.b, b * r.a);
    }
};

int n;
pair<Frac, Frac> arr[200002];
bool used[200002];
vector<pair<int, int> > ans;
vector<Frac> pointVec;

vector<pair<int, int> > link[400002];

int dfs(int x){
    vector<int> vec;
    while(!link[x].empty()){
        pair<int, int> p = link[x].back();
        if(used[p.second]){
            link[x].pop_back();
            continue;
        }
        used[p.second] = 1;
        link[x].pop_back();
        int ret = dfs(p.first);
        if(ret == 0) vec.push_back(p.second);
        else{
            ans.push_back(make_pair(p.second, ret));
        }
    }

    while(vec.size() >= 2){
        int x = vec.back(); vec.pop_back();
        int y = vec.back(); vec.pop_back();
        ans.push_back(make_pair(x, y));
    }

    if(vec.empty()) return 0;
    else return vec.back();
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%lld %lld %lld %lld", &arr[i].first.a, &arr[i].first.b, &arr[i].second.a, &arr[i].second.b);
    for(int i=1; i<=n; i++){
        arr[i].first.dd();
        arr[i].second.dd();
    }
    for(int i=1; i<=n; i++){
        pointVec.push_back(arr[i].first.add1() / arr[i].second);
        pointVec.push_back(arr[i].first / arr[i].second.add1());
    }
    sort(pointVec.begin(), pointVec.end());
    pointVec.erase(unique(pointVec.begin(), pointVec.end()), pointVec.end());

    for(int i=1; i<=n; i++){
        int u = lower_bound(pointVec.begin(), pointVec.end(), arr[i].first.add1() / arr[i].second) - pointVec.begin();
        int v = lower_bound(pointVec.begin(), pointVec.end(), arr[i].first / arr[i].second.add1()) - pointVec.begin();
        link[u].push_back(make_pair(v, i));
        link[v].push_back(make_pair(u, i));
    }

    for(int i=0; i<(int)pointVec.size(); i++){
        dfs(i);
    }
    printf("%d\n", (int)ans.size());
    for(auto x: ans){
        printf("%d %d\n", x.first, x.second);
    }
}