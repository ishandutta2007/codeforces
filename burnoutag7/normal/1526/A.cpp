#include<bits/stdc++.h>
using namespace std;

int n,a[55],b[55];

void mian(){
    cin>>n;
    for(int i=1;i<=n*2;i++)cin>>a[i];
    sort(a+1,a+1+n*2);
    for(int i=1;i<=n;i++){
        b[i*2-1]=a[i];
    }
    for(int i=n+1;i<=n*2;i++){
        b[(i-n)*2]=a[i];
    }
    for(int i=1;i<=n*2;i++)cout<<b[i]<<' ';
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