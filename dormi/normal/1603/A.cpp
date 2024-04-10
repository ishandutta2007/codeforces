#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
const ll MV=2e9;
ll gc[MN+2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        ll a;
        cin>>n;
        gc[1]=1;
        for(int i=2;i<=n+1;i++){
            if(gc[i-1]>MV)gc[i]=gc[i-1];
            gc[i]=gc[i-1]*ll(i)/__gcd(gc[i-1],ll(i));
        }
        bool work=true;
        for(int i=1;i<=n;i++){
            cin>>a;
            int lo=1,hi=n+1;
            while(lo!=hi){
                int mid=(lo+hi+1)/2;
                if(a%gc[mid]==0)lo=mid;
                else hi=mid-1;
            }
            if(lo>i)work=false;
        }
        if(work)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}