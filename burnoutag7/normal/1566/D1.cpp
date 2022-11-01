#include<bits/stdc++.h>
using namespace std;

int n,m,s[305];
pair<int,int> a[305];
bool occ[305];

void mian(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].first;
        a[i].second=-i;
    }
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++){
        s[-a[i].second]=i;
    }
    int ans=0;
    memset(occ+1,0,m);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=s[i];j++)ans+=occ[j];
        occ[s[i]]=1;
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