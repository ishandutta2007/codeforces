#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000009ll

long long up(long long a, long long d){return (a+d-1)/d;}
long long down(long long a, long long d){return a/d;}

void solve(){
    long long n, m, k; cin >> n >> m >> k;
    long long pr = 0;
    vector<long long> vals(m+1);
    for(int i = 0; i<m; i++){
        long long a; cin >> a; vals[i] = a-pr;
        pr = a;
    }
    vals[m] = n-pr; m++;
    k = k+m;
    long long lo = 1, hi = n+1;
    while(lo < hi){
        long long mid = lo+(hi-lo)/2ll;
        long long cnt = 0;
        for(int i = 0; i<m; i++) cnt += up(vals[i], mid);
        if(cnt <= k) hi = mid;
        else lo = mid+1;
    }
    long long mx = lo;
    lo = 1, hi = n+1;
    while(lo < hi){
        long long mid = lo+(hi-lo+1)/2ll;
        long long cnt = 0;
        for(int i = 0; i<m; i++) cnt += down(vals[i], mid);
        if(cnt >= k) lo = mid;
        else hi = mid-1;
    }
    long long mn = lo;
    // cout << mn << " " << mx << endl;
    // for(auto x : vals) cout << x << " ";
    // cout << endl;
    for(int i = 0; i<m; i++) mn = min(mn, vals[i]);
    vector<pair<long long, long long>> arr;
    for(int i = 0; i<m; i++){
        long long d = down(vals[i], mn);
        assert(d != 0ll);
        if(up(vals[i], d) > mx){
            long long a = up(vals[i], mn);
            if(vals[i]%mn == 0) a++;
            long long b = down(vals[i], mx);
            if(vals[i]%mx == 0) b--;
            arr.push_back({down(vals[i], a), up(vals[i], b)});
        }
    }
    // for(auto p : arr) cout << p.first << " " << p.second << endl;
    long long ans = INF;
    long long curhi = mx, curlo = mn;
    sort(arr.begin(), arr.end(), [&](pair<long long, long long> a, pair<long long, long long> b){return a.second > b.second;});
    for(auto p : arr){
        curhi = p.second;
        ans = min(ans, curhi-curlo);
        curlo = min(curlo, p.first);
    }
    ans = min(ans, mx-curlo);
    cout << ans << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}