#include <bits/stdc++.h>
using namespace std;
long long n,x,y,a[1000001],z;

int main(){
    cin>>n;
    for (int i=2;i<=n;++i){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    cin>>z;
    cin>>x>>y;

    if (x>y) swap(x,y);
    cout<<min(a[y]-a[x],a[x]+z+a[n]-a[y]);
}