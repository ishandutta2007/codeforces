#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    long long n; cin >> n;
    long long mp[n+2];
    for(long long i = 0; i<n; i++){
        long long a; cin >> a;
        mp[i+1]=a;
    }
    mp[0] = 0;
    mp[n+1]=n+1;
    long long ans = 0;
    for(long long i = 1; i<=n; i++){
        long long a = mp[i];
        long long b = mp[i-1];
        long long c = mp[i+1];
        long long temp = a*(n+1-a)-min({a, b, c})*(n+1-max({a, b, c}));
        long long upper = n+1;
        long long lower = 0;
        if(b >= a) upper = min(upper, b);
        if(c >= a) upper = min(upper, c);
        if(b <= a) lower = max(lower, b);
        if(c <= a) lower = max(lower, c);
        temp += (upper-a) * (a-lower);
        ans += temp;
    }
    cout << ans/2 << endl;
}