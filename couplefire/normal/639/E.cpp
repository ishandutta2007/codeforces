#include <bits/stdc++.h>
using namespace std;
#define MAXN 150005

struct BIT{
    double bit[MAXN];
    const double INF = 1000000009;
    void reset(){fill(bit, bit+MAXN, -INF);}
    double query(int r){
        double res = -INF;
        for(; r>=0; r = (r&(r+1))-1) res = max(res, bit[r]);
        return res;
    }
    void upd(int ind, double val){
        for(; ind<MAXN; ind=ind|(ind+1)) bit[ind] = max(bit[ind], val);
    }
};

int n;
pair<double, double> arr[MAXN];
map<double, vector<pair<int, double>>, greater<double>> mp;
double minitime[MAXN], maxitime[MAXN];
map<double, int> compress;
BIT bit;
double totTime = 0;

void init(){
    cin >> n;
    int p[n], t[n];
    for(int i = 0; i<n; i++) cin >> p[i];
    for(int i = 0; i<n; i++) cin >> t[i], totTime += t[i];
    for(int i = 0; i<n; i++) arr[i] = {p[i], t[i]};
    sort(arr, arr+n);
    for(int i = 0; i<n; i++) mp[1.0*arr[i].first/arr[i].second].push_back({i, arr[i].second});
    double curtime = 0;
    for(auto &x : mp){
        double tmp = 0;
        for(auto bruh : x.second) tmp += bruh.second;
        for(auto bruh : x.second) minitime[bruh.first] = curtime+bruh.second, maxitime[bruh.first] = curtime+tmp;
        curtime += tmp;
    }
    int counter = 0;
    vector<double> v;
    for(int i = 0; i<n; i++) v.push_back(arr[i].first);
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i<v.size(); i++) compress[v[i]] = ++counter;
}

bool check(double mid){
    bit.reset();
    for(int i = 0; i<n; i++){
        double score = arr[i].first*(1-mid*maxitime[i]/totTime);
        // if(abs(mid-1.0)<1e-5) cout << score << endl;
        if(bit.query(compress[arr[i].first]-1) > score) return 0;
        bit.upd(compress[arr[i].first], arr[i].first*(1-mid*minitime[i]/totTime));
    }
    return 1;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();
    double lo = 0, hi = 1;
    for(int i = 0; i<50; i++){
        double mid = (lo+hi)/2;
        if(check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << endl;
}