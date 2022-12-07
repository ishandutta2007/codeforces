#include <bits/stdc++.h>
using namespace std;
const double pi=3.14159265;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, r;
    cin>>n>>r;
    double si=sin(pi/n);
    double x=(si*r)/(1-si);
    cout<<fixed<<setprecision(10)<<x;
}