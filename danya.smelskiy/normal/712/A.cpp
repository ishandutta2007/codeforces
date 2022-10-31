#include <bits/stdc++.h>
using namespace std;
long long n,a[100001];
long long b[100001],nep,par;
int main(){
        cin>>n;
        for (int i=1;i<=n;++i)
            cin>>a[i];
        if (n%2==0) par+=a[n]; else nep+=a[n];
        b[n]=a[n];
        for (int i=n-1;i>0;--i){
            if (i%2==0){
                b[i]=a[i]+nep-par;
                par+=b[i];
            }else{
                b[i]=a[i]+par-nep;
                nep+=b[i];
            }
        }
        for (int i=1;i<=n;++i)
            cout<<b[i]<<" ";
}