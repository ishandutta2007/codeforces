#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;
int main() {
    fast_io;
    int a,b,c,d,e,f;
    ll ans=0;
    cin >> a >> b >> c >> d >> e >> f;
    if(e>f){
        ans+=min(a,d)*e;
        d-=min(a,d);
        ans+=min(min(b,c),d)*f;
    }else{
        ans+=min(min(b,c),d)*f;
        d-=min(min(b,c),d);
        ans+=min(a,d)*e;
    }
    cout << ans;
    return 0;
}