#include <bits/stdc++.h>
using namespace std;
int n,x;
long long a[300005];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=n/2;++i){
        if (i%2==1){
            x=n-i+1;
            swap(a[i],a[x]);
        }
    }
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
}