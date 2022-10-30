#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    const int INF = 1e9;
    int n; cin >> n; int psum = 0;
    int hi = INF, lo = -INF;
    for(int i = 0; i<n; ++i){
        int a, b; cin >> a >> b;
        if(b==1) lo = max(lo, -psum+1900);
        else hi = min(hi, -psum+1899);
        psum += a;
    }
    if(lo>hi){cout << "Impossible" << '\n'; exit(0);}
    if(hi==INF){cout << "Infinity" << '\n'; exit(0);}
    cout << hi+psum << '\n';
}