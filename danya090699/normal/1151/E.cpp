#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0, pr;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        if(a)
        {
            if(x>pr) an+=(x-pr)*(n-x+1);
            if(x<pr) an+=x*(pr-x);
        }
        else an+=x*(n-x+1);
        pr=x;
    }
    cout<<an;
}