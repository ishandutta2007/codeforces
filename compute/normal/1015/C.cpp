#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int dis[100007];
    long long ori,com;
    long long sumo=0,sumc=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&ori,&com);
        sumo+=ori;
        dis[i]=ori-com;
        sumc+=com;
    }
    if(sumo<=m)
    {
        cout<<0<<endl;
        return 0;
    }
    if(sumc>m)
    {
        cout<<-1<<endl;
        return 0;
    }
    sort(dis,dis+n,cmp);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        sumo-=dis[i];
        if(sumo<=m)
        {
            cnt=i+1;
            break;
        }
    }
        cout<<cnt<<endl;
    return 0;
}