#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n, s, en, an;
    cin>>n>>s;
    en=min(s+1000, n);
    an=n-en;
    for(int a=s; a<=en; a++)
    {
        int cu=a, su=0;
        while(cu>0)
        {
            su+=cu%10;
            cu/=10;
        }
        if(a-su>=s) an++;
    }
    cout<<an;
}