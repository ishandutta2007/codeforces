#include <bits/stdc++.h>

using namespace std;

const int N=10000000;
int d[N+1];

void ini()
{
    for(int i=0;i<=N;i++) d[i]=i;
    for(int o=2;o*o<=N;o++)
    {
        if(d[o]!=o) continue;
        for(int i=o*o;i<=N;i+=o)
        {
            if(d[i]==i) d[i]=o;
        }
    }
}

vector<pair<int,int>> factorise(int a)
{
    vector<pair<int,int>> v;
    v.push_back({d[a],0});
    int now=a;
    while(now!=1)
    {
        if(d[now]!=v.back().first) v.push_back({d[now],0});
        v.back().second++;
        now/=d[now];
    }
    return v;
}

int main()
{
    ini();
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> a(n),b(m);
    vector<int> one(N+1,0),two(N+1,0);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        vector<pair<int,int>> v=factorise(a[i]);
        for(pair<int,int> p:v) one[p.first]+=p.second;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
        vector<pair<int,int>> v=factorise(b[i]);
        for(pair<int,int> p:v) two[p.first]+=p.second;
    }
    for(int i=1;i<=N;i++) tie(one[i],two[i])=make_pair(one[i]-min(one[i],two[i]),two[i]-min(one[i],two[i]));
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
    {
        int t=1;
        vector<pair<int,int>> v=factorise(a[i]);
        for(pair<int,int> p:v)
        {
            for(int j=0;j<min(one[p.first],p.second);j++) t*=p.first;
            one[p.first]-=min(one[p.first],p.second);
        }
        printf("%d%c",t," \n"[i==n-1]);
    }
    for(int i=0;i<m;i++)
    {
        int t=1;
        vector<pair<int,int>> v=factorise(b[i]);
        for(pair<int,int> p:v)
        {
            for(int j=0;j<min(two[p.first],p.second);j++) t*=p.first;
            two[p.first]-=min(two[p.first],p.second);
        }
        printf("%d%c",t," \n"[i==m-1]);
    }
    return 0;
}