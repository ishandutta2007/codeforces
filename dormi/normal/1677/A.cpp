#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=5001;
int bit[2][MN];
int arr[MN];
int n;
void update(int t, int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[t][loc]+=val;
}
int query(int t, int loc){
    int sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[t][loc];
    return sum;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            bit[0][i]=bit[1][i]=0;
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)bit[1][j]=0;
            for(int j=n;j>=i+1;j--){
                ans+=ll(query(0,arr[j]-1))*ll(query(1,arr[i]-1));
                update(1,arr[j],1);
            }
            update(0,arr[i],1);
        }
        printf("%lli\n",ans);
    }
    return 0;
}