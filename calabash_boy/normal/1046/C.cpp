#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define PB(x) push_back(x)
#define rep(i,l,r) for (ll i = l,_ = r;i< _;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);


int main(){
    int n,d;
    cin>>n>>d;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    map<int,int> p;
    int tar;
    cin>>tar;
    tar += a[d-1];
    rep(i,0,n-1){
        int x;
        cin>>x;
        p[x] ++;
    }
    int ans = 0;
    for (int i=n-1;i>=0;i--){
        if (i == d-1)continue;
        auto it = p.lower_bound(tar - a[i]);
        if (it  == p.end()){
            ans ++;
            it --;
            it->second --;
            if (it->second == 0){
                p.erase(it);
            }
        }else if (it->first + a[i] == tar){
            ans ++;
            it->second --;
            if (it->second == 0){
                p.erase(it);
            }
        }else if (it != p.begin()){
            ans ++;
            it --;
            it->second --;
            if (it->second == 0){
                p.erase(it);
            }
        }else{
            break;
        }
    }
    cout<<n-ans<<endl;
    return 0;
}