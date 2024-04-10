#include<bits/stdc++.h>
using namespace std;

int n,a[200005];

void mian(){
    cin>>n;
    int pos=-1,p=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p^=a[i];
        if(!p&&i&1)pos=i;
    }
    if(p||pos==-1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    if(n&1){
        cout<<n-2<<'\n';
        for(int i=1;i<=n-2;i+=2)cout<<i<<' ';
        for(int i=n-4;i>=1;i-=2)cout<<i<<' ';
        cout<<'\n';
        return;
    }
    cout<<max(pos-2,0)+max(n-pos-2,0)<<'\n';
    for(int i=1;i<=pos-2;i+=2)cout<<i<<' ';
    for(int i=pos-4;i>=1;i-=2)cout<<i<<' ';
    for(int i=pos+1;i<=n-2;i+=2)cout<<i<<' ';
    for(int i=n-4;i>=pos+1;i-=2)cout<<i<<' ';
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