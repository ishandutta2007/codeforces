#include <bits/stdc++.h>
using namespace std;
int k,a,b,n;
int main(){
    cin>>a>>b>>n;
    k=1;
    while (n>0){
        if (k%2==1) n-=__gcd(a,n);
        else    n-=__gcd(b,n);
        ++k;
    }
    if (k%2==0) cout<<"0";
    else cout<<"1";
}