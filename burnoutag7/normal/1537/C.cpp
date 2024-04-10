#include<bits/stdc++.h>
using namespace std;

int n,a[200005];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    if(n==2){
        cout<<a[1]<<' '<<a[2]<<'\n';
        return;
    }
    int pos=-1,mn=1e9;
    for(int i=1;i<n;i++){
        if(a[i+1]-a[i]<mn){
            mn=a[i+1]-a[i];
            pos=i;
        }
    }
    for(int i=pos+1;i<=n;i++)cout<<a[i]<<' ';
    for(int i=1;i<=pos;i++)cout<<a[i]<<' ';
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