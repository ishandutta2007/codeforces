#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll arr[(int)1e5+1];
vector<ll> larger,smaller;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,d,m;
    cin>>n>>d>>m;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>m)larger.push_back(arr[i]);
        else smaller.push_back(arr[i]);
    }
    sort(larger.begin(),larger.end(),greater<>());
    sort(smaller.begin(),smaller.end());
    for(int i=1;i<sz(larger);i++)larger[i]+=larger[i-1];
    for(int i=sz(smaller)-2;i>=0;i--)smaller[i]+=smaller[i+1];
    int curam=(sz(larger)+d)/(d+1);
    int needed=d-(sz(larger)-((d+1)*max(0,(curam-1))+1)-1);
    ll ans=0;
    if(sz(smaller))ans+=smaller[0];
    if(curam-1>=0)ans+=larger[curam-1];
    if(needed<=sz(smaller)&&curam+1<=sz(larger)){
        ll teans=0;
        if(needed<sz(smaller))teans+=smaller[needed];
        teans+=larger[curam+1-1];
        ans=max(teans,ans);
    }
    for(int i=2;;i++){
        ll teans=0;
        if(needed+(i-1)*(d+1)<=sz(smaller)) {
            if(needed + (i - 1) * (d + 1)<sz(smaller))teans += smaller[needed + (i - 1) * (d + 1)];
            if(curam+i<=sz(larger)){
                teans += larger[curam + i-1];
                ans = max(teans, ans);
            }
            else break;
        }
        else break;
    }
    printf("%lli\n",ans);
    return 0;
}