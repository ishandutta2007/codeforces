#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int a, b, c;
    cin>>a>>b>>c;
    int an=c*2+min(a, b)*2;
    if(a!=b) an++;
    cout<<an;
}