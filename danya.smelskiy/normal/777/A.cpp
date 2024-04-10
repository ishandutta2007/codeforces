#include <bits/stdc++.h>
using namespace std;
int n,x,ans;
int a[15];
int main(){
    cin>>n;
    cin>>x;
    n%=6;
    a[0]=0;
    a[1]=1;
    a[2]=2;
    for (int i=1;i<=n;++i){
        if (i%2==1) swap(a[0],a[1]);
        else swap(a[1],a[2]);
    }
    cout<<a[x];
}