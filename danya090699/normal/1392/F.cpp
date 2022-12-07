#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, su=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int h;
        scanf("%lld", &h);
        su+=h-a;
    }
    for(int a=0; a<n; a++)
    {
        int h=a+su/n;
        if(a<su%n) h++;
        printf("%lld ", h);
    }
}