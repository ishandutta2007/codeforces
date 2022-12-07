#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    int os=n%m;
    cout<<min(a*((m-os)%m), b*os);
}