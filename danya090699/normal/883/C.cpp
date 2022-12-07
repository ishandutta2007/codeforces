#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
int de(int a, int b)
{
    int re=a/b;
    if(a%b>0) re++;
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int f, t, t0, an=inf;
    cin>>f>>t>>t0;
    int a1, t1, p1;
    cin>>a1>>t1>>p1;
    int a2, t2, p2;
    cin>>a2>>t2>>p2;
    if(t1>t2)
    {
        swap(t1, t2), swap(a1, a2), swap(p1, p2);
    }
    if(t2<t0)
    {
        int yk=0;
        for(int a=f; a>=0; a--)
        {
            while(yk+a<f)
            {
                int ti=a*t1+yk*t2+(f-a-yk)*t0;
                if(ti<=t) break;
                else yk++;
            }
            if(a*t1+yk*t2+(f-a-yk)*t0<=t) an=min(an, de(a, a1)*p1+de(yk, a2)*p2);
        }
    }
    else
    {
        if(t1<t0)
        {
            for(int a=0; a<=f; a++)
            {
                if(a*t1+(f-a)*t0<=t) an=min(an, de(a, a1)*p1);
            }
        }
        else
        {
            if(t0*f<=t) an=0;
        }
    }
    if(an==inf) cout<<-1;
    else cout<<an;
}