#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define N 105
#define INF 1000000000
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
char s[N][N];
int len[N];
int vis[N],del[N];
int main()
{
    int n,m,i,j,x,y;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        scanf("%s",s[i]);
        len[i]=strlen(s[i]);
    }
    for(i=1;i<=m;i++)
    {
        cin>>y;
        del[y]=1;
        if(i==1)
            x=y;
        else
        {
            if(len[x]!=len[y])
            {
                printf("No\n");
                return 0;
            }
            for(j=0;j<len[x];j++)
                if(s[x][j]!=s[y][j])
                    vis[j]=1;
        }
    }
    for(i=1;i<=n;i++)
        if(!del[i])
            if(len[i]==len[x])
            {
                for(j=0;j<len[x];j++)
                    if(!vis[j])
                        if(s[x][j]!=s[i][j])
                            break;
                if(j==len[x])
                {
                    printf("No\n");
                    return 0;
                }
            }
    printf("Yes\n");
    for(j=0;j<len[x];j++)
        if(vis[j])
            printf("?");
        else printf("%c",s[x][j]);
    cout<<endl;
    return 0;
}