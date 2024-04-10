#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(re*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int x, n;
    cin>>x>>n;
    vector <int> pr;
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            pr.push_back(a);
            while(x%a==0) x/=a;
        }
    }
    if(x>1) pr.push_back(x);
    int an=1;
    for(int a=0; a<pr.size(); a++)
    {
        int x=pr[a], cu=x;
        while(cu<=n)
        {
            an=(an*po(x, n/cu))%mod;
            if(n/cu>=x) cu*=x;
            else break;
        }
    }
    cout<<an;
}