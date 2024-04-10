#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int x;
    cin>>x;
    int A=1, B=x;
    for(int a=1; a*a<=x; a++)
    {
        if(x%a==0)
        {
            int y=x/a;
            if(__gcd(a, y)==1 and max(A, B)>max(a, y)) A=a, B=y;
        }
    }
    cout<<A<<" "<<B;
}