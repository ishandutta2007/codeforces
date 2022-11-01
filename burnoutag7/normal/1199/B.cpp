#include<bits/stdc++.h>
using namespace std;

double x,h,l;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>h>>l;
    x=(l*l-h*h)/2/h;
    //cout<<x<<endl;
    cout<<setprecision(10)<<x<<endl;

    return 0;
}