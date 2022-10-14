#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node
{
    int l,r;
}x[200003],q[200003],pos[200003];
vector<int> Q[200003];
int f,r,len;
int fa[200003],ans[200003],sum[200003];
int find(int k)
{
	if(k!=fa[k]) fa[k]=find(fa[k]);
	return fa[k];
}
int main()
{
    int n=read();
    for(int i=1;i<=n;i++) x[i].l=read(),len=read(),fa[i]=i,x[i].r=x[i].l+len;
	int m=read();
	for(int i=1;i<=m;i++) q[i].l=read(),q[i].r=read(),Q[q[i].l].push_back(i);
    deque<int> qs;
    for(int i=n;i>0;i--)
    {
        pos[i]=x[i];        
        while(!qs.empty() && pos[qs.front()].l<=pos[i].r)
        {
            pos[i].r=max(pos[i].r,pos[qs.front()].r);
            fa[find(qs.front())]=i;
            qs.pop_front();
        }
        if(!qs.empty())
        sum[i]=sum[qs.front()]+pos[qs.front()].l-pos[i].r;
        else sum[i]=0;
        qs.push_front(i);
        for(int j=0;j<Q[i].size();j++)
        {
            int id=Q[i][j],t=q[id].r;
            ans[id]=sum[i]-sum[find(t)];  
        }
    }
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}