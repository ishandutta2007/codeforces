#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n*2], ma=0, fo=0;
    long long an[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        ar[a+n]=ar[a];
        ma=max(ma, ar[a]);
    }
    if(ma==0)
    {
        fo=1;
        for(int a=0; a<n; a++) an[a]=1;
    }
    else
    {
        for(int a=n; a<n*2; a++)
        {
            if(ar[a]==ma and ar[a-1]<ma)
            {
                an[a%n]=ma;
                long long x=ma*2;
                for(int b=a-1; b>a-n; b--)
                {
                    x+=ar[b], an[b%n]=x;
                }
                fo=1;
                break;
            }
        }
    }
    if(fo)
    {
        cout<<"YES\n";
        for(int a=0; a<n; a++) printf("%lld ", an[a]);
    }
    else cout<<"NO";
}