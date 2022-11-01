#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld pi=3.14159265358979;

inline ld cot(const ld &a){
    return 1/tan(a);
}

int T,n;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n;
        n*=2;
        ld apo=cot(pi/n)/2;
        ld ia=(ld)90/n;
        ld x=sqrt(apo*apo+0.25);
        cout<<fixed<<setprecision(10)<<x*sin((90-ia)*pi/180)*2<<endl;
    }

    return 0;
}