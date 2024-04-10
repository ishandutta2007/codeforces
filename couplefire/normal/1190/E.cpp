#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define EPS 1e-10

int n, m;
ld minD = 1e9;
vector<pair<ld, ld>> pts;
const ld pi = acos(-1.0);

bool check(ld d){
    if(d == 0.0000000) return 1;
    vector<pair<ld, ld>> ranges;
    for(int i = 0; i<n; i++){
        ld cur = atan2(pts[i].second,pts[i].first);
        ld dist = sqrt(pts[i].first*pts[i].first+pts[i].second*pts[i].second);
        ld curAng = acos(d/dist);
        if(cur-curAng < 0) cur += 2*pi;
        ranges.push_back({cur-curAng, cur+curAng});
        ranges.push_back({cur-curAng+2*pi, cur+curAng+2*pi});
    }
    sort(ranges.begin(), ranges.end());
    // for(auto x : ranges){
    //     cout << x.first/pi*180 << " " << x.second/pi*180 << endl;
    // }
    int nn = ranges.size();
    vector<int> f[20];
    fill(f, f+20, vector<int>(nn+1));
    int cur = nn-1;
    f[0][nn] = nn;
    for(int i = nn-1; i >=0; i--){
        while(ranges[cur].first > ranges[i].second) cur--;
        f[0][i] = cur+1;
    }
    for(int i = 1; i<20; i++){
        for(int j = 0; j<=nn; j++){
            f[i][j] = f[i-1][f[i-1][j]];
        }
    }
    for(int i = 0; i<n; i++){
        int v = i;
        int cur = 0;
        int x = m;
        while(x){
            if(x&1) v = f[cur][v];
            cur++; x >>= 1;
        }
        if(v >= i+n) return 1;
    }
    return 0;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout << setprecision(10);
    cin >> n >> m;
    pts.resize(n);
    for(int i = 0; i<n; i++) cin >> pts[i].first >> pts[i].second;
    for(int i = 0; i<n; i++){
        minD = min(minD, sqrt(pts[i].first*pts[i].first+pts[i].second*pts[i].second));
    }
    ld lo = 0, hi = minD;
    while(hi-lo > EPS){
        ld mid = (hi+lo)/2.0;
        if(check(mid)) lo = mid;
        else hi = mid;
    }
    // cout << check(0.1) << endl;
    cout << lo << endl;
}