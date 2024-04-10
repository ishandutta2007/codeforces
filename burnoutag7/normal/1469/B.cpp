#include<bits/stdc++.h>
using namespace std;

int n,m,r[105],b[105];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>r[i],r[i]+=r[i-1];
    cin>>m;
    for(int i=1;i<=m;i++)cin>>b[i],b[i]+=b[i-1];
    cout<<*max_element(r,r+1+n)+*max_element(b,b+1+m)<<'\n';
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