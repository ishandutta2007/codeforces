#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
char t[100005];
int a[100005]={0};
bool cmp(int i)
{
    int j;
    if(a[i]-1>a[i+1]-a[i])
        return true;
    else if(a[i]-1<a[i+1]-a[i])
        return false;
    else
    {
        for(j=0;j<a[i]-1;j++)
        {
            if(t[j]>t[a[i]+j-1])
                return true;
            else if(t[j]<t[a[i]+j-1])
                return false;
        }
        return true;
    }
}

int main()
{
    int len,i,n=0;
    int ans=0;
    scanf("%s",t);
    len=strlen(t);
    for(i=0;i<len;i++)
        if(t[i]!='0')
        {
            n++;
            a[n]=i+1;
        }
    a[n+1]=len+1;
    //cout<<a[2]-a[1];
    for(i=1;i<=n;i++)
    {
        if(cmp(i))
            ans++;
        else
            ans=1;
    }
    cout<<ans<<endl;
    return 0;
}