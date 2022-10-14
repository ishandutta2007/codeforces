#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> v[1003];
vector<int> id[1003];
int d[1003]={-1},dep;
void dfs(int x,int fa)
{
    d[x]=d[fa]+1,id[d[x]].push_back(x),dep=max(dep,d[x]);
    for(int y:v[x]) if(y!=fa) dfs(y,x);
}
signed main()
{
    for(int T=read(); T--;)
    {
        int n=read();
        for(int i=1; i<=n; i++) v[i].clear();
        for(int i=0; i<=1000; i++) id[i].clear();
        for(int i=1,p,q; i<n; i++) p=read(),q=read(),v[p].push_back(q),v[q].push_back(p);
        printf("? %d ",n);
        for(int i=1; i<=n; i++) printf("%d ",i);
        puts(""),fflush(stdout);
        int x=read(),y=read();
        dep=0,dfs(x,0);
        int l=(y+1)>>1,r=min(y,dep),ans=1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            printf("? %d ",(int)id[mid].size());
            for(int t:id[mid]) printf("%d ",t);
            puts(""),fflush(stdout); 
            int p=read(),q=read();
            if(q==y) ans=p,l=mid+1; else r=mid-1;
        }
        for(int i=0; i<=n; i++) id[i].clear();
        dfs(ans,0);
        printf("? %d ",(int)id[y].size());
        for(int t:id[y]) printf("%d ",t);
        puts(""),fflush(stdout); 
        int p=read(),q=read();
        printf("! %d %d\n",ans,p),fflush(stdout);
		char s[13];
		scanf("%s",s);
		if(s[0]=='I') return 0;
    }
	return 0;
}