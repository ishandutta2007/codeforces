#include<bits/stdc++.h>
using namespace std;

int n,k,x[105],y[105];

void mian(){
    cin>>n>>k;
    int ans=-1;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++){
        bool f=true;
        for(int j=1;j<=n;j++){
            if(abs(x[i]-x[j])+abs(y[i]-y[j])>k)f=false;
        }
        if(f)ans=1;
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