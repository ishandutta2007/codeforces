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
ll n,k,cnt=0;
ll a[502],b[502];
bool cp(int x, int y){
    return a[x]<a[y];
}
int main() {
    fast_io;
    cin >> n >> k;
    for(int i=1; i<=k+1; i++){
        cout << "? ";
        for(int j=1; j<=k+1; j++){
            if(j!=i) cout << j << ' ';
        }
        cout << endl;
        cin >> b[i] >> a[i];
    }
    ll g[k+1];
    for(int i=1; i<=k+1; i++) g[i-1]=i;
    sort(g,g+k+1,cp);
    for(int i : g){
        if(b[i]==b[g[0]]) cnt++;
    }
    cout << "! " << k-cnt+1;
    return 0;
}