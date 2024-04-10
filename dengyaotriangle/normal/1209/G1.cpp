#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=200006;

int n,q,z;
int a[maxn];
int foc[maxn],loc[maxn],occ[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        occ[a[i]]++;
        z=max(z,a[i]);
    }
    for(int i=1;i<=n;i++)loc[a[i]]=i;
    for(int i=n;i>=1;i--)foc[a[i]]=i;
    int lp=1;
    int ans=n;
    while(lp<=n){
        int rp=loc[a[lp]];
        int mx=occ[a[lp]];
        for(int i=lp;i<=rp;i++){
            rp=max(rp,loc[a[i]]);
            mx=max(mx,occ[a[i]]);
        }
        ans-=mx;
        lp=rp+1;
    }
    cout<<ans;
    return 0;
}