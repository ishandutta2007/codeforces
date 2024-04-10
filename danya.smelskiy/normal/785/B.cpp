#include <bits/stdc++.h>
using namespace std;


int n,m;
pair<long long ,long long > a[200005];
pair<long long,long long> b[200005];
long long  ans;
inline bool cmp1(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
inline bool cmp2(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
    }
    cin>>m;
    for (int i=1;i<=m;++i)
        cin>>b[i].first>>b[i].second;
    sort(a+1,a+n+1,cmp1);
    sort(b+1,b+m+1,cmp2);
    ans=max(0ll,b[m].first-a[1].second);
    sort(a+1,a+n+1,cmp2);
    sort(b+1,b+m+1,cmp1);
    ans=max(ans,max(0ll,a[n].first-b[1].second));
    cout<<ans;
}