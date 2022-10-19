#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010],b[100010];
void solve(){
    scanf("%d",&n);
    vector<int> v[2];
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) v[a[i]].push_back(b[i]);
    if(v[0].size()==v[1].size()){
        long long ans=0;int minn=2e9;
        for(int i=1;i<=n;i++){
            ans+=b[i];
            minn=min(minn,b[i]);
        }
        printf("%lld\n",2*ans-minn);
        return;
    }
    long long ans=0;
    for(int i=1;i<=n;i++) ans+=2*b[i];
    if(v[0].size()<v[1].size()) swap(v[0],v[1]);
    sort(v[0].begin(),v[0].end());
    for(int i=0;i<(int)v[0].size()-(int)v[1].size();i++) ans-=v[0][i];
    printf("%lld\n",ans); 
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}