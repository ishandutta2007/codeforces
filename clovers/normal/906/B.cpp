#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m;
vector<int> s[N],a[N];
int flag=0;

int main()
{
    scanf("%d%d",&n,&m);
    if(n==1&&m==1)
    {
        puts("YES");
        puts("1");
        return 0;
    }
    if((n<=3&&m<=2)||(n<=2&&m<=3))
    {
        puts("NO");
        return 0;
    }
    if(n==3&&m==3)
    {
        puts("YES");
        puts("1 3 8");
        puts("5 9 4");
        puts("7 2 6");
        return 0;
    }
    if(n>m) swap(n,m), flag=1;
    int cnt=0;
    if(!flag)
    {
        for(int i=1;i<=n;i++) 
        {
            for(int j=1;j<=m;j++) s[i].push_back(++cnt);
        }
    }
    if(flag)
    {
        for(int i=1;i<=n;i++) 
        {
            for(int j=1;j<=m;j++) s[i].push_back(0);
        }
        for(int j=0;j<m;j++)
        {
            for(int i=1;i<=n;i++) s[i][j]=++cnt;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(m>4)
        {
            if(i&1)
            {
                for(int j=m-1;j>=0;j-=2) a[i].push_back(s[i][j]);
                for(int j=m-2;j>=0;j-=2) a[i].push_back(s[i][j]);
            }
            else
            {
                for(int j=m-2;j>=0;j-=2) a[i].push_back(s[i][j]);
                for(int j=m-1;j>=0;j-=2) a[i].push_back(s[i][j]);
            }
        }
        else
        {
            for(int j=m-2;j>=0;j-=2) a[i].push_back(s[i][j]);
            for(int j=m-1;j>=0;j-=2) a[i].push_back(s[i][j]);
            if(i%2==0) reverse(a[i].begin(),a[i].end());
        }
        if(i%2==0) swap(a[i-1],a[i]);
    }
    puts("YES");
    if(!flag)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<m;j++) printf("%d ",a[i][j]); puts("");
        }
    }
    else
    {
        for(int j=0;j<m;j++)
        {
            for(int i=1;i<=n;i++) printf("%d ",a[i][j]); puts("");
        }
    }
    return 0;
}