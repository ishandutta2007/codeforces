#include <bits/stdc++.h>
using namespace std;

long long x,y,z;
int main(){
    cin>>x>>y>>z;
    long long a=y/x+z/x;
    if (y>a*x || z>a*x || a==0) cout<<"-1";
    else cout<<a;
}