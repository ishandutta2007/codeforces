#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll arr[(int)2e5+1];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        ll w;
        cin>>n>>w;
        ll totsum=0;
        ll a;
        ll largew=(w+1)/ll(2);
        vector<ll> oths;
        vector<ll> good;
        for(int i=0;i<n;i++){
            cin>>a;
            arr[i]=a;
            if(a>=largew&&a<=w)good.push_back(i+1);
            else if(a<largew&&totsum<largew){
                oths.push_back(i+1);
                totsum+=a;
            }
        }
        if(sz(good)){
            printf("1\n%lli\n",good[0]);
        }
        else if(totsum>=largew){
            printf("%d\n",sz(oths));
            for(auto x:oths)printf("%lli ",x);
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}