#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, be=0;
    cin>>n>>m;
    int ar[n+2], su=0;
    ar[0]=0, ar[n+1]=m;
    for(int a=1; a<=n; a++) scanf("%d", &ar[a]);
    for(int a=n; a>=0; a--)
    {
        int all=m-ar[a+1], d=ar[a+1]-ar[a];
        if(a%2==0)
        {
            if(ar[a]+1<ar[a+1])
            {
                int cu=(d-1+all-su)-(d+su);
                be=max(be, cu);
            }
            su+=ar[a+1]-ar[a];
        }
        else
        {
            if(ar[a]+1<ar[a+1])
            {
                int cu=(d-1+all-su)-su;
                be=max(be, cu);
            }
        }
    }
    cout<<su+be;
}