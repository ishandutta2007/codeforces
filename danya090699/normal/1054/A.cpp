#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int x, y, z, t1, t2, t3;
    cin>>x>>y>>z>>t1>>t2>>t3;
    if(abs(x-y)*t1>=(abs(z-x)+abs(x-y))*t2+t3+t3+t3) cout<<"YES";
    else cout<<"NO";
}