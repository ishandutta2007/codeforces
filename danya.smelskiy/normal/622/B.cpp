#include <bits/stdc++.h>
using namespace std;
char c;
long long x,y,z;
int main(){
    cin>>x>>c>>y;
    cin>>z;
    z%=24*60;
    x=x*60+y;
    x+=z;
    x%=24*60;
    long long y=x/60;
    x%=60;
    if (y<10) cout<<"0"<<y;
    else cout<<y;
    cout<<":";
    if (x<10) cout<<"0"<<x;
    else cout<<x;
}