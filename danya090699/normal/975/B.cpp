#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    const int n=14;
    int ar[n], an=0;
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<n; a++)
    {
        int cu=0;
        for(int b=0; b<n; b++)
        {
            int nu=b-(a+1)%n;
            if(nu<0) nu+=n;
            int va=ar[b];
            if(b==a) va=0;
            va+=ar[a]/n;
            if(nu<ar[a]%n) va++;
            if(va%2==0) cu+=va;
        }
        an=max(an, cu);
    }
    cout<<an;
}