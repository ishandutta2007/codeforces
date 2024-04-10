#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,k,vr[200005],hr[200005],x[300005],y[300005];
map<int,int> vmp[200005],hmp[200005];

void mian(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>vr[i];
        vmp[i].clear();
    }
    for(int i=1;i<=m;i++){
        cin>>hr[i];
        hmp[i].clear();
    }
    for(int i=1;i<=k;i++){
        cin>>x[i]>>y[i];
        int vid=upper_bound(vr+1,vr+n+1,x[i])-vr-1;
        int hid=upper_bound(hr+1,hr+m+1,y[i])-hr-1;
        if(vr[vid]!=x[i]){
            vmp[vid][y[i]]++;
        }
        if(hr[hid]!=y[i]){
            hmp[hid][x[i]]++;
        }
    }
    ll ans=0;
    for(int i=1;i<n;i++){
        int tot=0;
        for(auto [pos,cnt]:vmp[i]){
            tot+=cnt;
            ans-=(ll)cnt*(cnt-1)/2;
        }
        ans+=(ll)tot*(tot-1)/2;
    }
    for(int i=1;i<m;i++){
        int tot=0;
        for(auto [pos,cnt]:hmp[i]){
            tot+=cnt;
            ans-=(ll)cnt*(cnt-1)/2;
        }
        ans+=(ll)tot*(tot-1)/2;
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}