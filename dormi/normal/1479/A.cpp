#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+3;
int arr[MN];
int cnt=0;
int query(int i){
    if(arr[i]!=0)return arr[i];
    cnt++;
    if(cnt==101)assert(0);
    printf("? %d\n",i);
    int v;
    cin>>v;
    if(v==-1)assert(0);
    return v;
}
int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
    setbuf(stdout,NULL);
    int n;
    cin>>n;
    int lo=1,hi=n;
    arr[0]=INT_MAX,arr[n+1]=INT_MAX;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        int l=query(mid-1),m=query(mid),r=query(mid+1);
        if(m<l&&m<r){
            printf("! %d\n",mid);
            return 0;
        }
        if(m<l)lo=mid+1;
        else hi=mid-1;
    }
    printf("! %d\n",lo);
    return 0;
}