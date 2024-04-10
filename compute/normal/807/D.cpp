#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int arr[120][120],solve[6]={0},value[6],cnt=0;
int calc(int i,int id)
{
    int ac;
    if(arr[id][i]==-1)
        return 0;
    if(arr[0][i]==-1||arr[1][i]==-1||arr[0][i]<arr[1][i])
        ac=solve[i];
    else ac=cnt+solve[i];
    if(n/ac>=32)
        value[i]=3000;
    else if(n/ac>=16)
        value[i]=2500;
    else if(n/ac>=8)
        value[i]=2000;
    else if(n/ac>=4)
        value[i]=1500;
    else if(n/ac>=2)
        value[i]=1000;
    else value[i]=500;
    return value[i]*(1-arr[id][i]/250.0);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<5;j++)
            {
                scanf("%d",&arr[i][j]);
                if(arr[i][j]>=0)
                    solve[j]++;
            }
    int flag=1;
    int scorev=0,scorep=0;
    for(int j=0;j<5;j++)
    {
        scorev+=calc(j,0);
        scorep+=calc(j,1);
    }
    if(scorev>scorep)
    {
        cout<<cnt<<endl;
        flag=0;
    }
    for(int i=0;i<10000;i++)
    {
        if(!flag)
            break;
        scorev=0,scorep=0;
        n++;
        cnt++;
        for(int j=0;j<5;j++)
        {
            scorev+=calc(j,0);
            scorep+=calc(j,1);
        }
        if(scorev>scorep)
        {
            cout<<cnt<<endl;
            flag=0;
            break;
        }
    }
    if(flag)
        cout<<"-1"<<endl;
    return 0;
}