//zhouAKngyang AK IOI!
#include<bits/stdc++.h>
using namespace std; 
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],b[1000003];
int nxt[1000003],lst[1000003];
bool vis[1000003];
int pos[1000003];
int main()
{
    for(int T=read(); T--;)
    {
        int n=read(),k=read();
        for(int i=1; i<=n; i++) a[i]=read(),pos[a[i]]=i;
        for(int i=1; i<=n; i++) nxt[i]=i+1,lst[i]=i-1,vis[i]=0; 
        vis[0]=vis[n+1]=1;
        for(int i=1; i<=k; i++) b[i]=pos[read()],vis[b[i]]=1;
        long long ans=1;
        for(int i=1; i<=k; i++) 
        if(vis[lst[b[i]]]) if(vis[nxt[b[i]]])
        {
            ans=0;
            break;
        }
        else
        {
            lst[nxt[nxt[b[i]]]]=b[i],nxt[b[i]]=nxt[nxt[b[i]]];
            vis[b[i]]=0;
        }
        else if(vis[nxt[b[i]]])
        {
            nxt[lst[lst[b[i]]]]=b[i],lst[b[i]]=lst[lst[b[i]]];
            vis[b[i]]=0;
        }
        else
        {
            ans<<=1,ans%=998244353;
            lst[nxt[nxt[b[i]]]]=b[i],nxt[b[i]]=nxt[nxt[b[i]]];
            vis[b[i]]=0;
        }
        printf("%lld\n",ans);
    }
	return 0;
}