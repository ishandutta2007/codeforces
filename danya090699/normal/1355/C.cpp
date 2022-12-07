#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(int l, int r)
{
    return (l+r)*(r-l+1)/2;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int A, B, C, D, an=0;
    cin>>A>>B>>C>>D;
    for(int a=C; a<=D; a++)
    {
        int l=max(B, a+1-A), r=max(B, a+1-B);
        if(r<=C)
        {
            int q=B-A+1;
            if(l>C) q-=l-C, l=C;
            l=C-l+1, r=C-r+1;
            an+=f(l, r)+(q-(r-l+1))*r;
        }
    }
    cout<<an;
}