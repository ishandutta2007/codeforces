#include <bits/stdc++.h>

using namespace std;

bool valid(int x)
{
        if(x<=5)
                return 1;
        for(int d=2;d*d<=x;d++)
                if(x%d==0)
                        return 0;
        return 1;
}

typedef long long ll;
int mod;

int mul(int a,int b)
{
        return a*(ll)b%mod;
}

int expow(int a,int b)
{
        int r=1;
        while(b)
        {
                if(b&1)
                        r=mul(r,a);
                a=mul(a,a);
                b>>=1;
        }
        return r;
}

int inv(int a)
{
        return expow(a,mod-2);
}

int dv(int a,int b)
{
        return mul(a,inv(b));
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int n;
        cin>>n;
        if(!valid(n))
        {
                cout<<"NO\n";
                return 0;
        }
        cout<<"YES\n";
        if(n==4)
        {
                cout<<"1\n3\n2\n4\n";
                return 0;
        }
        mod=n;
        int x=1;
        cout<<x<<"\n";
        int curp=x;
        for(int i=2;i<=n;i++)
        {
                int y=dv(i,curp);
                curp=mul(curp,y);
                if(y==0)
                        y=n;
                cout<<y<<"\n";
        }
        cout<<"\n";

        return 0;
}