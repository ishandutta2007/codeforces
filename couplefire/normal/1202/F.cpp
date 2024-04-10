#include <bits/stdc++.h>
using namespace std;

bool contain(int a, int b, int c){return a <= c && c <= b;}

pair<int, int> x(int a, int b, int lo, int hi){
    int ll = max(a, lo);
    int hh = min(b, hi);
    if(ll > hh) return {2000000009, -2000000009};
    return {ll, hh};
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b; cin >> a >> b;
    if(a == 0 || b == 0){
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    int ROOT = max((int)sqrt(a+b)-5, 1);
    for(int k = 1; k<=ROOT; k++){
        int s = (a+b)/k;
        int hi1 = a/s, lo1 = ceil(0.0+a/(s+1.0));
        int hi2 = b/s, lo2 = ceil(0.0+b/(s+1.0));
        if(lo1 > hi1) continue;
        if(lo2 > hi2) continue;
        if(contain(lo2, hi2, k-lo1) || contain(lo2, hi2, k-hi1) || contain(lo1, hi1, k-lo2) || contain(lo1, hi1, k-hi2)){
            ans++;
            // cout << k << " no" << endl;
        }
    }
    for(int s = (a+b)/ROOT-1; s>=1; s--){
        int hi = (a+b)/s, lo = ceil(0.0+(a+b)/(s+1.0));
        if((a+b) % (s+1) == 0) lo++;
        int hi1 = a/s, lo1 = ceil(0.0+a/(s+1.0));
        int hi2 = b/s, lo2 = ceil(0.0+b/(s+1.0));
        if(lo1 > hi1) continue;
        if(lo2 > hi2) continue;
        int lll = min({x(lo2+lo1, hi2+hi1, lo, hi).first, x(lo2+hi1, hi2+hi1, lo, hi).first, x(lo1+lo2, hi1+lo2, lo, hi).first, x(lo1+hi2, hi1+hi2, lo, hi).first});
        int hhh = max({x(lo2+lo1, hi2+hi1, lo, hi).second, x(lo2+hi1, hi2+hi1, lo, hi).second, x(lo1+lo2, hi1+lo2, lo, hi).second, x(lo1+hi2, hi1+hi2, lo, hi).second});
        if(lll == 2000000009 || hhh == -2000000009) continue;
        ans += hhh-lll+1;
        // for(int i = lll; i<=hhh; i++) cout << i << " " << lll << " " << hhh << endl;
    }
    cout << ans << endl;
}