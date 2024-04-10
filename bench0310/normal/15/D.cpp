#include <bits/stdc++.h>

using namespace std;
const int N=1005;

int arr[N][N],r[N][N],q[N][N];
long long sum[N][N];
bool vis[N][N];

int main()
{
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int o=1;o<=n;o++)
    {
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&arr[o][i]);
            sum[o][i]=sum[o-1][i]+sum[o][i-1]-sum[o-1][i-1]+arr[o][i];
        }
    }
    for(int o=1;o<=n;o++)
    {
        deque<int> d;
        for(int i=1;i<=b;i++)
        {
            while(!d.empty()&&d.back()>arr[o][i]) d.pop_back();
            d.push_back(arr[o][i]);
        }
        r[o][1]=d.front();
        for(int i=2;i+b-1<=m;i++)
        {
            while(!d.empty()&&d.back()>arr[o][i+b-1]) d.pop_back();
            d.push_back(arr[o][i+b-1]);
            if(!d.empty()&&d.front()==arr[o][i-1]) d.pop_front();
            r[o][i]=d.front();
        }
    }
    for(int i=1;i<=m;i++)
    {
        deque<int> d;
        for(int o=1;o<=a;o++)
        {
            while(!d.empty()&&d.back()>r[o][i]) d.pop_back();
            d.push_back(r[o][i]);
        }
        q[1][i]=d.front();
        for(int o=2;o+a-1<=n;o++)
        {
            while(!d.empty()&&d.back()>r[o+a-1][i]) d.pop_back();
            d.push_back(r[o+a-1][i]);
            if(!d.empty()&&d.front()==r[o-1][i]) d.pop_front();
            q[o][i]=d.front();
        }
    }
    vector<pair<long long,int>> v,res;
    for(int o=1;o+a-1<=n;o++)
    {
        for(int i=1;i+b-1<=m;i++)
        {
            v.push_back({sum[o+a-1][i+b-1]-sum[o+a-1][i-1]-sum[o-1][i+b-1]+sum[o-1][i-1]-1ll*a*b*q[o][i],N*o+i});
        }
    }
    sort(v.begin(),v.end());
    for(pair<long long,int> p:v)
    {
        int e=p.second/N;
        int f=p.second%N;
        if(vis[e][f]==0&&vis[e+a-1][f]==0&&vis[e][f+b-1]==0&&vis[e+a-1][f+b-1]==0)
        {
            res.push_back(p);
            for(int o=e;o<=e+a-1;o++)
            {
                for(int i=f;i<=f+b-1;i++)
                {
                    vis[o][i]=1;
                }
            }
        }
    }
    printf("%d\n",res.size());
    for(pair<long long,int> p:res)
    {
        printf("%d %d %I64d\n",p.second/N,p.second%N,p.first);
    }
    return 0;
}