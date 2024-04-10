#include <bits/stdc++.h>
using namespace std;


long double n;
long double a;
int x,y,z;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a;
    long double ans=1e9;
    for (long double i=3;i<=n;++i) {
        long double res=180.*(n-(i-1.))/n;
        if (ans-abs(res-a)>0.00000000001) {
            ans=abs(res-a);
            x=1;
            y=i-1;
            z=i;
        }
        res=180.*(n-(i-1.))/n;
        if (ans-abs(res-a)>0.00000000001) {
            ans=abs(res-a);
            x=1;
            y=i;
            z=i-1;
        }
    }
    cout<<x<<" "<<y<<" "<<z;
}