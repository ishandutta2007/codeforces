#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],sum;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int j=n;j>0;--j){
        sum+=a[j];
        if (sum>=m){
            cout<<n-j+1;
            return 0;
        }
    }
    cout<<n;
}