#include<bits/stdc++.h>
using namespace std;
const int N=3005;
const int inf=(int)1e9;
int t,n,a[N],pos[N],bl[N];

int vis[N];
int getmex()
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) vis[a[i]]=1;
    int now=0;
    while(vis[now]) now++;
    return now;
}

bool judge()
{
    for(int i=1;i<n;i++) if(a[i+1]<a[i]) return 0;
    return 1;
}

vector<int> ans;
int main()
{
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        memset(pos,0,sizeof(pos));
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
        int now=getmex(); ans.clear();
        int ttt=2*n;
        for(int i=0;i<ttt;i++)
        {
            now=getmex();
            if(judge()) break;
            if(now==n)
            {
                ans.push_back(n);
                a[n]=now;
                n--;
            }
            else
            {
                ans.push_back(now+1);
                a[now+1]=now;
                
            }
        }
        printf("%d\n",(int)ans.size());
        for(int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}