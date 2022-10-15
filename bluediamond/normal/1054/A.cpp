#include <bits/stdc++.h>

using namespace std;



int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        int x, y, z, t1, t2, t3;
        cin>>x>>y>>z>>t1>>t2>>t3;
        int str=abs(x-y)*t1;
        int ele=abs(z-x)*t2+t3+t3+abs(x-y)*t2+t3;
        cout<<((ele<=str)?"YES":"NO")<<"\n";

        return 0;
}