#include <bits/stdc++.h>
using namespace std;
long long a,b;

int main(){
    cin>>a>>b;
    long long gcd=__gcd(a,b);
    long long nsk=(a*b)/gcd;
    long long x=(nsk-1)/a;
    long long y=(nsk-1)/b;
    if (a>b) ++x;
    else if (a<b) ++y;
    if (x>y) cout<<"Dasha";
    else if (x<y) cout<<"Masha";
    else cout<<"Equal";
}