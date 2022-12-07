#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, h;
    cin>>n>>h;
    for(int a=1; a<n; a++) cout<<fixed<<setprecision(10)<<sqrt(a*1.0/n)*h<<" ";
}