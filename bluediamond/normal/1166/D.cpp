#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100;
ll nr[N];
ll t[N];
ll co[N];

bool ex=0;

bool ok(ll a,ll b,ll c,int st)
{
        a*=nr[st+1];
        if(a>b)
        {
                ex=1;
                return 0;
        }
        ll df=b-a;
        for(int j=0;j<=st;j++)
        {
                co[j]=nr[st-j];
                df-=co[j];
                if(df<0) return 0;
        }
        for(int j=0;j<=st;j++)
        {
                ll k=min(c-1,df/co[j]);
                df-=co[j]*k;
                t[j]=k+1;
        }
        return (df==0);
}

void solve(ll a,ll b,ll c)
{
        ex=0;
        if(a==b)
        {
                cout<<"1 "<<a<<"\n";
                return;
        }
        if(b<=a+c)
        {
                cout<<"2 "<<a<<" "<<b<<"\n";
                return;
        }
        int st=0;
        for(st=0;st<=50 && (ex==0);st++)
        {
                if(ok(a,b,c,st))
                {
                        break;
                }
        }
        if(ok(a,b,c,st)==0)
        {
                cout<<"-1\n";
                return;
        }
        ll sm=a;
        cout<<st+2<<" ";
        cout<<a<<" ";
        for(int j=0;j<=st;j++)
        {
                cout<<sm+t[j]<<" ";
                sm+=(sm+t[j]);
        }
        cout<<"\n";
}

int main()
{
        nr[0]=1;
        nr[1]=1;
        for(int j=2;j<N;j++)
        {
                nr[j]=2*nr[j-1];
        }
        int test;
        cin>>test;
        for(int tc=1;tc<=test;tc++)
        {
                ll a,b,c;
                cin>>a>>b>>c;
                solve(a,b,c);
        }
        return 0;
}