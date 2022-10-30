#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
    cin>>n;
    long long ans=1;
    for (int i=2;i<=sqrt(n);++i){
        if (n%i==0){
            ans*=i;
            while (n%i==0){
                n/=i;
            }
        }
    }
    if (n>1) ans*=n;
    cout<<ans;
}