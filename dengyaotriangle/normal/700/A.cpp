#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int n,l,v1,v2,k,g;

int main(){
    cin>>n>>l>>v1>>v2>>k;
    g=(n+k-1)/k;
    double h=l/(1.0+2.0*(g-1)*v1/(v1+v2));
    double t=h/v2+(l-h)/v1;
    cout<<fixed<<setprecision(20)<<t;
    return 0;
}