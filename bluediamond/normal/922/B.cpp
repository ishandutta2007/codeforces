#include <bits/stdc++.h>
using namespace std;
long long n,ans=0,cif[50],c;
int main()
{
    cin>>n;
    for(int a=1;a<=n;a++)
        for(int b=1;b<=n;b++)
        {
            c=a^b;
            c=0^c;
            if(c!=0 and c<=n and a+b>c and a+c>b and b+c>a)
                ans++;
        }
    cout<<ans/6;
    return 0;
}
/**
**/