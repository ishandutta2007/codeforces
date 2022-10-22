#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 1e6 + 100;
ll n,m;
int main(){
    cin >> n >> m;
    ll a[n],b[n],s1=0,s2=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        s1+=a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
        s2+=b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    set<ll> ans;
    for(int i=0; i<n; i++){
        ll c[n];
        ll k=(b[i]-a[0]+m)%m;
        for(int j=0; j<n; j++){
            c[j]=(a[j]+k)%m;
        }
        sort(c,c+n);
        bool d=true;
        for(int j=0; j<n; j++) {
            if (c[j] != b[j]) d = false;
        }
        if(d) ans.insert(k);
    }
    cout << *ans.begin();
    return 0;
}