#include<bits/stdc++.h>
using namespace std;

int n,a[105],b[105],c[105],p[105];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]!=p[i-1])p[i]=a[i];
        else if(b[i]!=p[i-1])p[i]=b[i];
        else p[i]=c[i];
    }
    if(p[n-1]!=a[n]&&p[1]!=a[n])p[n]=a[n];
    else if(p[n-1]!=b[n]&&p[1]!=b[n])p[n]=b[n];
    else p[n]=c[n];
    for(int i=1;i<=n;i++){
        cout<<p[i]<<' ';
    }
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