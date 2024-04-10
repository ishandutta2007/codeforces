#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
bool vis[10003];
int p[10003],a[5003],ans[5003],cnt;
unordered_set<int> s;
signed main()
{
	int n=read();
    for(int i=2; i<=10000; i++) if(!vis[i])
    {
        p[++cnt]=i*i;
        for(int j=2; i*j<=10000; j++) vis[i*j]=1;
    }
    for(int i=1; i<=n; i++) 
    {
        int f=1;
        a[i]=read();
        if(a[i]<0) a[i]*=-1,f=-1;
        else if(a[i]==0) continue;
        for(int j=1; j<=cnt; j++) while(a[i]%p[j]==0) a[i]/=p[j];
        a[i]*=f;
    }
    for(int i=1; i<=n; i++)
    {
        s.clear();
        bool f=0;
        for(int j=i; j<=n; j++)
        {
            if(a[j]) s.insert(a[j]);
            ++ans[max((int)s.size(),1)];
        }
    }
    for(int i=1; i<=n; i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}