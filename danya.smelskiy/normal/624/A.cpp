#include <bits/stdc++.h>
using namespace std;
long double d,l,x,y;
int main(){
    cin>>d>>l>>x>>y;
    x+=y;
    l-=d;
    long double ans;
    ans=l/x;
    cout<<fixed<<setprecision(20)<<ans;
}