#include<bits/stdc++.h>
using namespace std;

int n,k,z;
int a[100005],pre[100005],mx[100005];

void mian(){
    cin>>n>>k>>z;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=a[i]+pre[i-1];
    }
    for(int i=1;i<=n;i++){
        mx[i]=max(mx[i-1],a[i]+a[i+1]);
    }
    mx[n]=mx[n-1];
    int ans=0;
    for(int ml=0;ml<=z;ml++){
        k-=ml*2;
        if(k>=0)ans=max(ans,pre[k+1]+mx[k+1]*ml);
        k+=ml*2;
    }
    cout<<ans<<endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        mian();
    }

    return 0;
}