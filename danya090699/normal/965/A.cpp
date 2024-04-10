#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
int main()
{
    int k, n, s, p;
    cin>>k>>n>>s>>p;
    cout<<de(de(n, s)*k, p);
}