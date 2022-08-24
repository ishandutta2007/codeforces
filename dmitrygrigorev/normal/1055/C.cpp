#include <bits/stdc++.h>
#define int long long

using namespace std;
int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int la, ra, ta, lb, rb, tb;
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    int g = gcd(ta, tb);
    int d = (((lb - la) % g) +g)%g;
    int ans=0;
    ans = max(ans, min(ra-la+1-d, rb-lb+1));
    d = (((la - lb) % g) +g)%g;
    ans = max(ans, min(rb-lb+1-d, ra-la+1));
    cout << ans;


}