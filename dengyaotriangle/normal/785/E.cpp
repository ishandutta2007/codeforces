#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=210005;
const int ks=512;

vector<int> val[maxn/ks];
int n,q;
int a[maxn];

inline int qry(int l,int r,int vl,int vr){
    if(l>r)return 0;
    if(l/ks==r/ks){
        int ans=0;
        for(int i=l;i<=r;i++)if(a[i]>=vl&&a[i]<=vr)ans++;
        return ans;
    }else{
        int ans=0;
        for(int i=l;i/ks==l/ks;i++)if(a[i]>=vl&&a[i]<=vr)ans++;
        for(int i=r;i/ks==r/ks;i--)if(a[i]>=vl&&a[i]<=vr)ans++;
        for(int p=l/ks+1;p<r/ks;p++){
            ans+=upper_bound(val[p].begin(),val[p].end(),vr)-lower_bound(val[p].begin(),val[p].end(),vl);
        }
        return ans;
    }
}

inline void chg(int p,int v){
    a[p]=v;
    int ki=p/ks;
    val[ki].clear();
    for(int i=p-1;i&&i/ks==ki;i--)val[ki].push_back(a[i]);
    for(int i=p;i/ks==ki;i++)val[ki].push_back(a[i]);
    sort(val[ki].begin(),val[ki].end());
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)a[i]=i;
    for(int i=1;i<=n;i++)val[i/ks].push_back(i);
    long long cans=0;
    while(q--){
        int l,r;cin>>l>>r;
        if(l!=r){
            if(l>r)swap(l,r);
            if(a[l]<a[r]){
                cans++;
                cans+=qry(l+1,r-1,a[l],a[r])*2;
            }else{
                cans--;
                cans-=qry(l+1,r-1,a[r],a[l])*2;
            }
            int pr=a[r],pl=a[l];
            chg(l,pr);chg(r,pl);
        }
        cout<<cans<<'\n';
    }
    return 0;
}