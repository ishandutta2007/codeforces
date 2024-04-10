#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}
int suym(int l, int r){
    if (l > r) return 0;
    return l*(r-l+1) + (r-l+1)*(r-l)/2;
}
main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int m, a, b;
    cin >> m >> a >> b;
    int g = gcd(a, b);
    int tet=m;
    a /= g, b /= g, m /= g;
    //cout << m << " " << a << " " << b << endl;
    int sum = (a+b-1);
    int ans = suym(a+b+1, m+1);
    int now = 0;
    int mx = 0;
    //cout << ans << endl;
    int sas=0;
    for (int i=0; i < a+b; i++){
        if (mx <= m) sas++;
        ans += max(min(a+b-1,m)-mx+1, (int) 0);
        if (now >= b) now -= b;
        else now += a;
        mx = max(mx, now);
    }
    ans *= g;
    if (m >= a+b) ans -= (g-1-tet%g)*(m+1);
    else{
        ans -= (g-1-tet%g)*sas;
    }
    cout << ans << endl;
}