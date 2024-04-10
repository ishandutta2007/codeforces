#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        ll x,y;
        cin >> x >> y;
        array<ll,7> c;
        for(int i=1;i<=6;i++) cin >> c[i];
        swap(c[2],c[6]);
        swap(c[3],c[5]);
        ll res=(1ll<<62);
        if(x>=0&&y>=0) res=min(res,x*c[2]+y*c[6]);
        if(x<=0&&y>=0) res=min(res,(-x)*c[5]+y*c[6]);
        if(x<=0&&y<=0) res=min(res,(-x)*c[5]+(-y)*c[3]);
        if(x>=0&&y<=0) res=min(res,x*c[2]+(-y)*c[3]);
        if(x==y&&x>=0) res=min(res,x*c[1]);
        if(x==y&&x<=0) res=min(res,(-x)*c[4]);
        //h+1
        if(y>0)
        {
            ll t=x-y;
            if(t>=0) res=min(res,t*c[2]+y*c[1]);
            if(t<=0) res=min(res,(-t)*c[5]+y*c[1]);
        }
        //h-1
        if(y<0)
        {
            ll t=x-y;
            if(t>=0) res=min(res,t*c[2]+(-y)*c[4]);
            if(t<=0) res=min(res,(-t)*c[5]+(-y)*c[4]);
        }
        //v+1
        if(x>0)
        {
            ll t=y-x;
            if(t>=0) res=min(res,t*c[6]+x*c[1]);
            if(t<=0) res=min(res,(-t)*c[3]+x*c[1]);
        }
        //v-1
        if(x<0)
        {
            ll t=y-x;
            if(t>=0) res=min(res,t*c[6]+(-x)*c[4]);
            if(t<=0) res=min(res,(-t)*c[3]+(-x)*c[4]);
        }
        cout << res << "\n";
    }
    return 0;
}