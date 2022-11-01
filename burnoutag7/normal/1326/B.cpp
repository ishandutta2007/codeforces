#include<bits/stdc++.h>
using namespace std;

int n,mx;
int b[200005];
int a[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        a[i]=b[i]+mx;
        mx=max(a[i],mx);
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;

    return 0;
}