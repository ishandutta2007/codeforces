#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
int flag,ans=100000000;
bool finded=false;
map<int,int> che_1,che_2;
void dfs(int a,int depth)
{
    if(flag==1)
        che_1[a]=depth;
    else
        che_2[a]=depth;
    depth++;
    if(a%2==0)
    {
        //printf("%d %d\n",a/2,che_1[5]);
        if(flag==2&&che_1[(a/2)]!=0)
        {
            ans=min(ans,depth+che_1[(a/2)]-1);
            finded=true;
            //return;
        }
        if(!(che_1[(a/2)]||che_2[(a/2)]))
        {
            if(flag==1)
                dfs(a/2,depth);
            if(flag==2)
                dfs(a/2,depth);
        }
    }
    if(a%3==0)
    {
        if(flag==2&&che_1[(a/3)]!=0)
        {
            ans=min(ans,depth+che_1[(a/3)]-1);
            finded=true;
            //return;
        }
        if(!(che_1[(a/3)]||che_2[(a/3)]))
        {
            if(flag==1)
                dfs(a/3,depth);
            if(flag==2)
                dfs(a/3,depth);
        }
    }
    if(a%5==0)
    {
        if(flag==2&&che_1[(a/5)]!=0)
        {
            ans=min(ans,depth+che_1[(a/5)]-1);
            finded=true;
            //return;
        }
        if(!(che_1[(a/5)]||che_2[(a/5)]))
        {
            if(flag==1)
                dfs(a/5,depth);
            if(flag==2)
                dfs(a/5,depth);
        }
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    if(a==b)
    {
      printf("0\n");
      return 0;
    }
    flag=1;
    dfs(a,1);
    flag=2;
    if(che_1[b]!=0)
    {
        printf("%d\n",che_1[b]-1);
        return 0;
    }
    dfs(b,0);
    if(finded)
        printf("%d\n",ans);
    else
        printf("-1\n");
    return 0;
}