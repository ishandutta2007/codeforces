#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>arr[i];
        if(k==1)printf("%d\n",(n-2+1)/2);
        else{
            int cnt=0;
            for(int i=2;i<n;i++){
                if(arr[i]>arr[i-1]+arr[i+1]){
                    cnt++;
                }
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}