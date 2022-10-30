#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
pair<int,int> a[2000005];



inline bool cmp(pair<int,int> a,pair<int,int> b){
    return (a.second-a.first>b.second-b.first);
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i].first;
    for (int i=1;i<=n;++i)
        cin>>a[i].second;
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;++i)
        if (i<=m) ans+=a[i].first;
        else {
            ans+=min(a[i].first,a[i].second);
        }
    cout<<ans;
}