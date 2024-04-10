#include<bits/stdc++.h>
using namespace std;

int n,l,x[105];

void mian(){
    cin>>n>>l;
    for(int i=0;i<n;i++)cin>>x[i];
    int ans=0;
    for(int i=0;i<l;i++){
        int cnt=0;
        for(int j=0;j<n;j++)cnt+=x[j]>>i&1;
        if(cnt>n/2)ans|=1<<i;
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