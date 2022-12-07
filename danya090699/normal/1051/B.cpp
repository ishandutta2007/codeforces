#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int l, r;
    cin>>l>>r;
    cout<<"YES\n";
    for(int a=l; a<r; a+=2) cout<<a<<" "<<a+1<<"\n";
}