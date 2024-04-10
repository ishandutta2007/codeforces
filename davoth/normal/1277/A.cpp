#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;
int t;
int main() {
    fast_io;
    cin >> t;
    while(t--){
        ll n,ans=0,cnt=1,k=1;
        cin >> n;
        int m=n;
        while(n>=10) n/=10,ans+=9,cnt++;
        ans+=n;
        for(int i=1; i<cnt; i++) k*=10,k++;
        if(m<n*k) ans--;
        cout << ans << '\n';
    }
    return 0;
}