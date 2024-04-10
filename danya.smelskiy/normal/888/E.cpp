#include <bits/stdc++.h>
using namespace std;




map<long long,bool> used;
vector<long long> v;
int n;
long long m;
long long a[100];
long long ans;

inline void add(long long x){
    if (used[x]==false) {
        used[x]=true;
        v.push_back(x);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        a[i]%=m;
    }
    if (n==1) {
        cout<<a[1];
        return 0;
    }
    int mid=(1+n)/2;
    int len=n-mid;
    add(0);
    for (int i=1;i<(1<<len);++i) {
        long long s=0;
        for (int j=0;j<len;++j)
        if (i&(1<<j)) {
            s+=a[mid+1+j];
        }
        s%=m;
        ans=max(ans,s);
        add(s);
    }
    sort(v.begin(),v.end());
    len=mid;
    for (int i=1;i<(1<<mid);++i) {
        long long s=0;
        for (int j=0;j<len;++j) {
            if (i&(1<<j)) {
                s+=a[j+1];
            }
        }
        s%=m;
        ans=max(ans,s);
        int l=0;
        int r=v.size();
        while (l<r-1) {
            int midd=(l+r)>>1;
            if (v[midd]<=m-s-1ll) l=midd;
            else r=midd;
        }
        if (v[r]<=m-s-1ll) l=r;
        ans=max(ans,(v[l]+s)%m);
        ans=max(ans,(v[(int)v.size()-1]+s)%m);
    }
    cout<<ans;
}