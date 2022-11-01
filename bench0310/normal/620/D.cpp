#include <bits/stdc++.h>

using namespace std;

const int N=2000;
int n,m;
vector<long long> a(N);
vector<long long> b(N);
long long one=0;
long long two=0;

array<long long,3> solve_one()
{
    set<pair<long long,int>> s;
    for(int i=0;i<m;i++) s.insert({b[i],i});
    long long d=one-two;
    array<long long,3> res={abs(one-two),0,0};
    for(int i=0;i<n;i++)
    {
        long long x=a[i];
        auto it=s.lower_bound({x-d/2,0});
        if(it!=s.end())
        {
            long long y=(*it).first;
            long long t=abs((one-x+y)-(two-y+x));
            if(t<res[0]) res={t,i,(*it).second};
        }
        if(it!=s.begin())
        {
            it=prev(it);
            long long y=(*it).first;
            long long t=abs((one-x+y)-(two-y+x));
            if(t<res[0]) res={t,i,(*it).second};
        }
    }
    return res;
}

array<long long,5> solve_two()
{
    set<tuple<long long,int,int>> s;
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            s.insert({b[i]+b[j],i,j});
        }
    }
    long long d=one-two;
    array<long long,5> res={abs(one-two),0,0,0,0};
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            long long x=a[i]+a[j];
            auto it=s.lower_bound({x-d/2,0,0});
            if(it!=s.end())
            {
                long long y=get<0>(*it);
                long long t=abs((one-x+y)-(two-y+x));
                if(t<res[0]) res={t,i,j,get<1>(*it),get<2>(*it)};
            }
            if(it!=s.begin())
            {
                it=prev(it);
                long long y=get<0>(*it);
                long long t=abs((one-x+y)-(two-y+x));
                if(t<res[0]) res={t,i,j,get<1>(*it),get<2>(*it)};
            }
        }
    }
    return res;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        one+=a[i];
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%I64d",&b[i]);
        two+=b[i];
    }
    array<long long,1> x={abs(one-two)};
    array<long long,3> y=solve_one();
    array<long long,5> z=solve_two();
    if(x[0]<=y[0]&&x[0]<=z[0]) printf("%I64d\n0\n",x[0]);
    else if(y[0]<=x[0]&&y[0]<=z[0]) printf("%I64d\n1\n%I64d %I64d\n",y[0],y[1]+1,y[2]+1);
    else printf("%I64d\n2\n%I64d %I64d\n%I64d %I64d\n",z[0],z[1]+1,z[3]+1,z[2]+1,z[4]+1);
    return 0;
}