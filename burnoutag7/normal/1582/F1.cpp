#include<bits/stdc++.h>
using namespace std;

int n,a[100005],f[512];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<512;j++)if(f[j]<a[i]){
            f[j^a[i]]=min(f[j^a[i]],a[i]);
        }
    }
    int ans=0;
    for(int i=0;i<512;i++)ans+=f[i]!=0x3f3f3f3f;
    cout<<ans<<'\n';
    for(int i=0;i<512;i++)if(f[i]!=0x3f3f3f3f){
        cout<<i<<' ';
    }

    return 0;
}