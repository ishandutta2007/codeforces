#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(int a, int b)
{
    return ((a+b)*(b-a+2))/4;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int l, r;
        cin>>l>>r;
        int l1=l, l2=l, r1=r, r2=r, su=0;
        if(l1%2==0) l1++;
        if(r1%2==0) r1--;
        if(l2%2) l2++;
        if(r2%2) r2--;
        if(l1<=r1) su-=f(l1, r1);
        if(l2<=r2) su+=f(l2, r2);
        cout<<su<<"\n";
    }
}