#include <bits/stdc++.h>
using namespace std;
int n,x,a[1000];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        a[x]=i;
    }
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
}