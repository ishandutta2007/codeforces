#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, b, p, x, a2=1, an=0;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(re*x)%p;
        y>>=1, x=(x*x)%p;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>a>>b>>p>>x;
    for(int n=0; n<p-1; n++)
    {
        int n2=(b*po(a2, p-2))%p, n3=n;
        if(n3<n2) n3+=p-1;
        int os=n2+(n3-n2)*p;
        an+=x/(p*(p-1))+(x%(p*(p-1))>=os);
        a2=(a2*a)%p;
    }
    cout<<an;
}