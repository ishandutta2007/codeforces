#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int m, b, an=0;
    cin>>m>>b;
    for(int a=0; a<=b; a++)
    {
        int x=((a*m)*(a*m+1)/2)*(b-a+1), y=((b-a)*(b-a+1)/2)*(a*m+1);
        an=max(an, x+y);
    }
    cout<<an;
}