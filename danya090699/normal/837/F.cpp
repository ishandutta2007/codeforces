//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e3, inf=2e18;
int tr[sz][sz];
int gcd(int a, int b)
{
    if(b==0) return a;
    else return gcd(b, a%b);
}
int pl(int a, int b){return min(a+b, inf);}
int um(int a, int b)
{
    if(a==0 or b==0) return 0;
    else
    {
        if(inf/b<a) return inf;
        else return a*b;
    }
}
int get(int c, int n)
{
    c=min(c, n-c);
    if(n<sz) return tr[n][c];
    else if(c<8)
    {
        int an=1;
        for(int a=1; a<=c; a++)
        {
            int ch=n+1-a, zn=a;
            int x=gcd(ch, zn);
            ch/=x, zn/=x;
            an/=zn;
            an=um(an, ch);
            if(an==inf) break;
        }
        return an;
    }
    else return inf;
}
main()
{
    for(int a=0; a<sz; a++)
    {
        tr[a][0]=1, tr[a][a]=1;
        for(int b=1; b<a; b++) tr[a][b]=pl(tr[a-1][b-1], tr[a-1][b]);
    }
    //freopen("input.txt", "r", stdin);
    int n, k, ok=0;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]);
        if(ar[a]>=k) ok=1;
    }
    if(ok) cout<<0;
    else
    {
        int l=0, r=1e18+10;
        while(r-l>1)
        {
            int mid=(l+r)/2, va=0;
            for(int a=0; a<n; a++)
            {
                if(ar[a]>0)
                {
                    va=pl(va, um(ar[a], get(n-1-a, (n-1-a)+(mid-1))));
                }
                if(va>=k) break;
            }
            if(va>=k) r=mid;
            else l=mid;
        }
        cout<<r;
    }
}