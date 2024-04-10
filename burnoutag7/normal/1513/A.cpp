#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,k;
    cin>>n>>k;
    if(k>n-1>>1){
        cout<<"-1\n";
        return;
    }
    for(int i=1;i<=k;i++)cout<<i<<' '<<n+1-i<<' ';
    for(int i=k+1;i<=n-k;i++)cout<<i<<' ';
    cout<<'\n';
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