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
        int n,a1,a2;
        cin >> n;
        int a[n];
        bool c=false;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n-1; i++){
            if(abs(a[i+1]-a[i])>=2) c=true,a1=i+1,a2=i+2;
        }
        if(!c) cout << "NO\n";
        else cout << "YES\n" << a1 << ' ' << a2 << '\n';
    }
    return 0;
}