#include <bits/stdc++.h>
using namespace std;
long long n,m,z;
int main(){
    cin>>n>>m>>z;
    long long x=__gcd(n,m);
    x=(n*m)/x;
    cout<<z/x;
}