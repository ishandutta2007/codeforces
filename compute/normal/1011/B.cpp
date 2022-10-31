#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int n,m,a[105],t;
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        cin>>t;
        a[t]++;
    }
    int cnt=0,ans=1,flag;
    for(int i=0;i<101;i++)
    {
        cnt=0;
        for(int j=0;j<101;j++)
        {
            cnt+=a[j]/ans;
            if(cnt>=n)
                flag=1;
            else flag=0;
        }
        if(flag)
            ans++;
        else break;
    }
    cout<<ans-1<<endl;
    return 0;
}