#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int pr[sz], nu=2;
void f(int n, int k, int rt)
{
    if(n>1)
    {
        if(k==0)
        {
            pr[nu]=rt, f(n/2, k, nu++);
            pr[nu]=rt, f(n/2, k, nu++);
        }
        else if(k==1)
        {
            for(int x=1; ; x=x*2+1)
            {
                int y=n-1-x;
                if(x*2+1==y)
                {
                    pr[nu]=rt, f(x, 0, nu++);
                    pr[nu]=rt, f(y, 0, nu++);
                    break;
                }
                if(min(x, y)*2>max(x, y))
                {
                    pr[nu]=rt, f(x, 0, nu++);
                    pr[nu]=rt, f(y, 1, nu++);
                    break;
                }
            }
        }
        else if(k==2)
        {
            if(__builtin_popcount(n-1)!=1)
            {
                pr[nu++]=rt, pr[nu]=rt, f(n-2, k-1, nu++);
            }
            else
            {
                pr[nu]=rt, f(3, 0, nu++);
                pr[nu]=rt, f(n-4, 1, nu++);
            }
        }
        else if(k==3 and n==11)
        {
            pr[nu]=rt, f(3, 0, nu++);
            pr[nu]=rt, f(7, 2, nu++);
        }
        else
        {
            pr[nu++]=rt, pr[nu]=rt, f(n-2, k-1, nu++);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    if(n==1 and k==0)
    {
        cout<<"YES\n0";
        return 0;
    }
    if(n%2==0)
    {
        cout<<"NO";
        return 0;
    }
    if((n-3)/2<k)
    {
        cout<<"NO";
        return 0;
    }
    if(__builtin_popcount(n+1)==1 and k==1)
    {
        cout<<"NO";
        return 0;
    }
    if(__builtin_popcount(n+1)!=1 and k==0)
    {
        cout<<"NO";
        return 0;
    }
    if(n==9 and k==2)
    {
        cout<<"NO";
        return 0;
    }
    pr[1]=0, f(n, k, 1);
    cout<<"YES\n";
    for(int a=1; a<=n; a++) printf("%d ", pr[a]);
}