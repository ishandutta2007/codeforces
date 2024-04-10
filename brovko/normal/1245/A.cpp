#include <bits/stdc++.h>
#define int long long

using namespace std;
int t, a, b;
vector <string> v;
int gcd(int x, int y)
{
    if(x==0)
        return y;
    return gcd(y%x, x);
}

int32_t main()
{
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> a >> b;
        if(gcd(a, b)==1)
            v.push_back("Finite");
        else v.push_back("Infinite");
    }
    for(int i=0;i<t;i++)
        cout << v[i] << "\n";
    return 0;
}