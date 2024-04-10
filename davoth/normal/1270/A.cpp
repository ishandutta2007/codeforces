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
        int n,k1,k2;
        cin >> n >> k1 >> k2;
        bool c=false;
        for(int i=0; i<k1; i++){
            int x;
            cin >> x;
            if(x==n) c=true;
        }
        for(int i=0; i<k2; i++) {
            int x;
            cin >> x;
        }
        if(c) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}