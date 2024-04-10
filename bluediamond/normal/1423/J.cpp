#include <bits/stdc++.h>

using namespace std;

#define int long long
const int M=(int) 1e9+7;

int rep(int x)
{
        x%=M;
        if (x<0)
                return x+M;
        return x;
}


int mul(int a,int b)
{
        a=rep(a);
        b=rep(b);
        return rep(a*b);
}

int pw(int a,int b)
{
        a=rep(a);
        int r=1;
        while (b)
        {
                if (b&1)
                        r=mul(r,a);
                a=mul(a,a);
                b/=2;
        }
        return r;
}

int dv(int a,int b)
{
        return mul(a,pw(b,M-2));
}

int gauss(int x)
{
        x=mul(x,x+1);
        x=dv(x,2);
}

int f(int x)
{
        x/=2;
        x+=2;
        int sol=0;
        sol+=gauss(x/2);
        sol+=gauss(x-x/2-1);
        sol=rep(sol);
        return sol;
}

signed main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);


        int t;
        cin>>t;
        while (t--)
        {
                int n;
                cin>>n;
                cout<<f(n)<<"\n";
        }
}