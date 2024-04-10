#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
int arr[MN];
int n;
int getam(int loc){
    if(loc<=0||loc>=n-1)return 0;
    if(arr[loc]<arr[loc-1]&&arr[loc]<arr[loc+1])return 1;
    if(arr[loc]>arr[loc-1]&&arr[loc]>arr[loc+1])return 1;
    return 0;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int am=0;
        int ma=0;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++){
            if(getam(i))am++;
            int l=getam(i-1),m=getam(i),r=getam(i+1),old=arr[i],le=(i-1>=0?arr[i-1]:0),ri=(i+1<n?arr[i+1]:0);
            for(auto x:{0,min(le,ri),min(le,ri)+1,max(le,ri),int(1e9)+1}){
                arr[i]=x;
                ma=max(ma,l-getam(i-1)+m-getam(i)+r-getam(i+1));
            }
            arr[i]=old;
        }
        printf("%d\n",am-ma);
    }
    return 0;
}