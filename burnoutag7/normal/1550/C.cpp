#include<bits/stdc++.h>
using namespace std;

int n,a[200005];

void mian(){
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int inc[3]={a[i],(int)1e9+1,(int)1e9+1},dec[3]={a[i]};
        int j;
        for(j=i+1;j<=n;j++){
            for(int k=2;k>=0;k--){
                if(k==0||a[j]>=inc[k-1])inc[k]=min(inc[k],a[j]);
                if(k==0||a[j]<=dec[k-1])dec[k]=max(dec[k],a[j]);
            }
            if(inc[2]!=1e9+1||dec[2]){
                break;
            }
        }
        ans+=j-i;
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