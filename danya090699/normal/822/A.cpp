//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, f=1;
    cin>>a>>b;
    for(int i=1; i<=min(a, b); i++) f*=i;
    cout<<f;
}