#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int sq(int x)
{
    int l=0, r=2e9;
    while(r-l>1)
    {
        int mid=(r+l)>>1;
        if(mid*mid<=x) l=mid;
        else r=mid;
    }
    return l;
}
int cb(int x)
{
    int l=0, r=2e6;
    while(r-l>1)
    {
        int mid=(r+l)>>1;
        if(mid*mid*mid<=x) l=mid;
        else r=mid;
    }
    return l;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    map <int, int> ma, ma2;
    for(int a=0; a<n; a++)
    {
        int x=sq(ar[a]);
        int y=cb(ar[a]);
        if(x*x==ar[a])
        {
            int x2=sq(x);
            if(x2*x2==x) ma[x2]+=4;
            else ma[x]+=2;
        }
        else if(y*y*y==ar[a]) ma[y]+=3;
        else
        {
            bool fo=0;
            for(int b=0; b<n; b++)
            {
                int d=__gcd(ar[a], ar[b]);
                if(d>1 and d<ar[a])
                {
                    fo=1, ma[d]++, ma[ar[a]/d]++;
                    break;
                }
            }
            if(fo==0) ma2[ar[a]]++;
        }
    }
    int an=1;
    for(auto it=ma.begin(); it!=ma.end(); it++) an=(an*((*it).second+1))%mod;
    for(auto it=ma2.begin(); it!=ma2.end(); it++) an=(an*((*it).second+1)*((*it).second+1))%mod;
    cout<<an;
}