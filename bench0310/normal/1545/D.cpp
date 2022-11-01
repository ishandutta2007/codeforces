#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,k;
    cin >> m >> k;
    vector one(k,ll(0));
    vector two(k,ll(0));
    for(int i=0;i<k;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ll p;
            cin >> p;
            one[i]+=p;
            two[i]+=(p*p);
        }
    }
    ll sumx=one[0];
    ll sumx2=two[0];
    ll sumv=((one[k-1]-one[0])/(k-1));
    ll y=0;
    for(int i=1;i<k-1;i++) if(sumx+i*sumv!=one[i]) y=i;
    ll t1=0,t2=0;
    for(ll t=1;t<k-1;t++)
    {
        if(t!=y&&t1==0) t1=t;
        else if(t!=y&&t2==0) t2=t;
    }
    ll sumv2=((t2*two[t1]-t1*two[t2]+(t1-t2)*sumx2)/(t1*t2*(t1-t2)));
    ll sumxv=((two[t1]-sumx2-t1*t1*sumv2)/(2*t1));
    ll d=(sumx+y*sumv-one[y]);
    ll e=(sumx2+y*y*sumv2+2*y*sumxv-two[y]);
    ll r=((e-d*d)/(2*d));
    cout << y << " " << r+d << "\n";
    cout.flush();
    return 0;
}