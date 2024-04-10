#include<bits/stdc++.h>
using namespace std;

int n,a[75];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=n-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)if(i!=j){
            int cur=2;
            for(int k=1;k<=n;k++)if(k!=i&&k!=j){
                if((a[i]-a[j])*(i-k)==(a[i]-a[k])*(i-j))cur++;
            }
            ans=min(ans,n-cur);
        }
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