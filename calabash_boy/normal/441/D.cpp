#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std ;
int n,m ;
int nxt[3005],vis[3005] ;
vector <pair<int,int> > ans ;
int cal()
{
    memset(vis,0,sizeof(vis)) ;
    int st=1 ;
    int cnt=0 ;
    for(int i=1 ;i<=n ;i++)
        if(!vis[i])
        {
            vis[i]=st++ ;
            int res=1 ;
            for(int j=nxt[i] ;!vis[j] ;j=nxt[j])
            {
                vis[j]=vis[i] ;
                res++ ;
            }
            cnt+=(res-1) ;
        }
    return cnt ;
}
int main()
{
    scanf("%d",&n) ;
    for(int i=1 ;i<=n ;i++)
        scanf("%d",&nxt[i]) ;
    scanf("%d",&m) ;
    while(1)
    {
        int ret=cal() ;
        if(ret==m)break ;
        if(ret<m)//1ret+1 1 
        {
            for(int i=2 ;i<=n ;i++)
                if(vis[i]!=vis[1])
                {
                    swap(nxt[1],nxt[i]) ;
                    ans.push_back(make_pair(1,i)) ;
                    break ;
                }
        }
        else//ret-1 
        {
            int i,j ;
            for(i=1 ;i<=n ;i++)
                if(nxt[i]!=i)break ;
            for(int j=i+1 ;j<=n ;j++)
                if(vis[j]==vis[i])
                {
                    swap(nxt[i],nxt[j]) ;
                    ans.push_back(make_pair(i,j)) ;
                    break ;
                }
        }
    }
    printf("%d\n",ans.size()) ;
    for(int i=0 ;i<ans.size() ;i++)
        printf("%d %d ",ans[i].first,ans[i].second) ;
    return 0 ;
}