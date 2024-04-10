#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
const ll mod=998244353;
int arr[MN];
int arr2[MN];
bool appear[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        for(int i=1;i<=n;i++)cin>>arr[i],appear[i]=false;
        vector<int> pos,vals;
        bool work=true;
        for(int i=1;i<=n;i++){
            cin>>arr2[i];
            if(arr2[i]==-1){
                pos.push_back(arr[i]-s);
            }
            else{
                if(arr2[i]<arr[i]-s){
                    work=false;
                }
                appear[arr2[i]]=true;
            }
        }
        if(!work){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;i++)if(!appear[i])vals.push_back(i);
        reverse(vals.begin(),vals.end());
        sort(pos.begin(),pos.end(),greater<>());
        int ptr=0;
        ll ans=1;
        for(int i=0;i<sz(pos);i++){
            while(ptr<sz(vals)&&vals[ptr]>=pos[i]){
                ptr++;
            }
            ans=ans*(ptr-i)%mod;
        }
        printf("%lli\n",ans);
    }
    return 0;
}