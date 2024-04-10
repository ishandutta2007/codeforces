#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=1001;
ll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll am=0;
    for(int i=0;i<n;i+=2){
        ll mirequired=1;
        ll sum=0;
        for(int j=i+1;j<=n;j++){
            if(j%2==1){
                ll tesum=sum+mirequired;
                if(arr[i]>=mirequired&&arr[j]>=tesum){
                    ll lam=arr[i]-mirequired,ram=arr[j]-tesum;
                    am+=min(lam,ram)+1;
                }
            }
            if(j%2==0)sum+=arr[j];
            else sum-=arr[j];
            mirequired=max(mirequired,-sum);
        }
    }
    printf("%lli\n",am);
    return 0;
}