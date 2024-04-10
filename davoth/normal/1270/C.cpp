#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll q;
int main() {
    fast_io;
    cin >> q;
    while(q--){
        ll n,sum=0,xr=0;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i],sum+=a[i],xr=xr^a[i];
        if(xr*2==sum) {
            cout << 0 << '\n';
            continue;
        }
        ll k=sum%2;
        ll p=1;
        while(sum>=p) p*=2;
        k+=p;
        xr^=k;
        xr*=2;
        sum+=k;
        ll g=(xr-sum)/2;
        cout << 3 << '\n' << k << ' ' << g << ' ' << g << '\n';
    }
    return 0;
}