#include <bits/stdc++.h>
using namespace std;
long long x,y,z;
int main(){
    cin>>x>>y>>z;
    cout<<min(x,min(y/2,z/4))*7;
}