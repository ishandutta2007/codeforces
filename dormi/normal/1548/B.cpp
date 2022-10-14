#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
ll arr[MN],diff[MN];
struct seg{
    ll t[2*MN];
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind]=diff[le];
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind]=__gcd(t[left],t[right]);
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return 0;
        if(le>=l&&ri<=r)return t[ind];
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return __gcd(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1){
            printf("1\n");
            continue;
        }
        for(int i=0;i<n-1;i++)diff[i]=abs(arr[i+1]-arr[i]);
        tree.mt(0,0,n-2);
        int r=-1;
        int ans=1;
        for(int i=0;i<n-1;i++){
            while(r+1<n-1&&tree.query(0,0,n-2,i,r+1)!=1)r++;
            ans=max(ans,r-i+2);
        }
        printf("%d\n",ans);
    }
    return 0;
}