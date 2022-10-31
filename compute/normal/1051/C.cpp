#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int s[105];
    int vis[105];
    map<int,int> cnt;
    memset(vis,0,sizeof(vis));
    int mark;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
        cnt[s[i]]++;
    }
    int nice=0,two=0,multi=0;
    for(auto it=cnt.begin();it!=cnt.end();++it)
    {
        if(it->second==1) {nice++;vis[it->first]=1;}
        else if(it->second==2) two++;
        else {multi++;mark=it->first;}
    }
    if(nice%2==0)
    {
        puts("YES");
        int cc=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[s[i]]==1&&cc<nice/2)
            {
                printf("B");
                cc++;
            }
            else printf("A");
        }
        printf("\n");
    }
    else{
        if(multi==0) puts("NO");
        else{
            puts("YES");
            int cc=0;
            for(int i=1;i<=n;i++)
            {
                if(s[i]==mark)
                {
                    printf("A");
                    mark=-1;
                }
                else if(vis[s[i]]==1&&cc<nice/2)
                {
                    printf("A");
                    cc++;
                }
                else printf("B");
            }
            printf("\n");
        }
    }
    return 0;
}