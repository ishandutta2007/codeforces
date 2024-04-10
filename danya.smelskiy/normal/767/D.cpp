#include <bits/stdc++.h>
using namespace std;

inline bool cmp(pair<long long,int> a,pair<long long,int> b){
    return a.first>b.first;
}
long long n,m,k,x;
long long a[10000005];
pair<long long ,int> b[10000005];
inline bool chek(int x){
    for (int i=x;i>0;--i){
        long long y=b[i].first;
        long long z=x-i+1;
        if ((y+1)*k-a[y]<z) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i){
        cin>>x;
        ++a[x];
    }
    for (int i=1;i<=m;++i){
        cin>>b[i].first;
        b[i].second=i;
    }
    sort(b+1,b+m+1,cmp);
    for (int i=1;i<=1e7+1;++i){
        a[i]+=a[i-1];
        if (a[i]>(i+1)*k){
            cout<<"-1";
            return 0;
        }
    }
    if (a[0]>k){
        cout<<"-1";
        return 0;
    }
    int l=0;
    int r=m;
    while (l<r-1){
        int mid=(l+r)/2;
        if (chek(mid)) l=mid;
        else r=mid;
    }
    if (chek(r)) l=r;
    cout<<l<<'\n';
    for (int i=1;i<=l;++i)
        cout<<b[i].second<<" ";
}