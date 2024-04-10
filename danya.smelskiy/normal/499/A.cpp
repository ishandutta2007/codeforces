#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[100001];
int n,m;
long long ans;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i].first;
        cin>>a[i].second;
    }
    ans+=(a[1].first-1)%m;
    ans+=a[1].second-a[1].first+1;
    for (int i=2;i<=n;++i){
        ans+=(a[i].first-a[i-1].second-1)%m;
        ans+=(a[i].second-a[i].first+1);
    }
    cout<<ans;
}