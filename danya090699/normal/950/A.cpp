#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, r, a;
    cin>>l>>r>>a;
    if(l>r) swap(l, r);
    r-=l;
    r=min(r, a);
    cout<<(l+(r+a)/2)*2;
}