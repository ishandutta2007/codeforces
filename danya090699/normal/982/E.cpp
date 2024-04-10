#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=4e18;
int ef(int x)
{
    int re=1;
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            int q=1;
            while(x%a==0)
            {
                x/=a, q*=a;
            }
            re*=q-q/a;
        }
    }
    if(x!=1) re*=(x-1);
    return re;
}
int po(int x, int y, int mod)
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
int f(int a, int b, int mod)
{
    if(a==0)
    {
        if(b==0) return 0;
        else return -1;
    }
    else
    {
        int d=__gcd(a, mod);
        if(b%d==0)
        {
            a/=d, b/=d, mod/=d;
            return (b*po(a, ef(mod)-1, mod))%mod;
        }
        else return -1;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, x, y, vx, vy;
    cin>>n>>m>>x>>y>>vx>>vy;
    if(vx==0)
    {
        if(x==0)
        {
            if(vy>0) cout<<0<<" "<<m;
            else cout<<0<<" "<<0;
        }
        else if(x==n)
        {
            if(vy>0) cout<<n<<" "<<m;
            else cout<<n<<" "<<0;
        }
        else cout<<-1;
    }
    else if(vy==0)
    {
        if(y==0)
        {
            if(vx>0) cout<<n<<" "<<0;
            else cout<<0<<" "<<0;
        }
        if(y==m)
        {
            if(vx>0) cout<<n<<" "<<m;
            else cout<<0<<" "<<m;
        }
        else cout<<-1;
    }
    else
    {
        int coor[4][2]={{0, 0}, {n, 0}, {0, m}, {n, m}}, p[4]={0, 1, 2, 3};
        int px=x, py=y;
        if(vx==1 and vy==-1)
        {
            x=m-py, y=px, swap(n, m);
            p[0]=2, p[1]=0, p[2]=3, p[3]=1;
        }
        if(vx==-1 and vy==-1)
        {
            x=n-px, y=m-py;
            p[0]=3, p[1]=2, p[2]=1, p[3]=0;
        }
        if(vx==-1 and vy==1)
        {
            x=py, y=n-px, swap(n, m);
            p[0]=1, p[1]=3, p[2]=0, p[3]=2;
        }
        int p1=x+(m-y), p2=x+(m-y)+m;
        int q1=f((2*m)%n, (n-p1%n)%n, n);
        int q2=f((2*m)%n, (n-p2%n)%n, n);

        if(q1!=-1) q1=p1+q1*(m*2);
        else q1=inf;
        if(q2!=-1) q2=p2+q2*(m*2);
        else q2=inf;

        if(q1==inf and q2==inf) cout<<-1;
        else
        {
            int an;
            if(q1<q2)
            {
                if((q1/n)%2==0) an=2;
                else an=3;
            }
            else
            {
                if((q2/n)%2==0) an=0;
                else an=1;
            }
            cout<<coor[p[an]][0]<<" "<<coor[p[an]][1];
        }
    }
}