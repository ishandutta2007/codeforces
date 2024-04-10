#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int bl=1000;
int a[1000003];//let's orz zhouAKngyang!!!
int opt[500000],l[500000],r[500000],x[500000];
int tag,mx,f[100003],fa[1000003],cnt[100003],ans[100003];
//ffaposposcnt
int n=read(),m=read();
inline int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
inline void merge(int s,int t)//move s->t
{
    //f[s]=find(f[s]),f[t]=find(f[t]);
    if(f[t]) a[f[s]]=t,fa[f[s]]=f[t],cnt[t]+=cnt[s],f[s]=cnt[s]=0;
    else a[f[s]]=t,f[t]=f[s],cnt[t]=cnt[s],cnt[s]=f[s]=0;
    return ;
}
signed main()
{
    for(int i=1; i<=n; ++i) a[i]=read();
    for(int i=0; i<m; ++i) opt[i]=read(),l[i]=read(),r[i]=read(),x[i]=read();
    for(int i=1; i<=n; i+=bl) 
    {
        tag=0,mx=0;
        memset(f,0,sizeof(f)),memset(cnt,0,sizeof(cnt));
        for(int k=i; k<i+bl&&k<=n; ++k) (mx<a[k])&&(mx=a[k]),(f[a[k]])?(fa[k]=f[a[k]]):(f[a[k]]=fa[k]=k),++cnt[a[k]];
        //xlazy
        for(int j=0; j<m; j++) if(opt[j]==1)
        {
            assert(mx<=100001);
            if(mx-tag<=x[j] || r[j]<i || l[j]>=i+bl) continue;
            if(l[j]<=i && r[j]>=i+bl-1)//
            {
                if(mx-tag>(x[j]<<1)) 
                {
                    for(int k=1; k<=x[j]; k++) merge(k+tag,k+tag+x[j]);
                    tag+=x[j];
                }
                else 
                {
                    for(int k=x[j]+1; k<=mx-tag; k++) merge(k+tag,k+tag-x[j]);
                    mx=min(mx,tag+x[j]);
                }
                //Merge~
            }
            else//
            {
                for(int k=i; k<i+bl&&k<=n; ++k) a[k]=a[find(k)];
                //
                for(int k=i; k<i+bl&&k<=n; ++k) f[a[k]]=cnt[a[k]]=0;
                int L=max(l[j],i),R=min(r[j],i+bl-1);
                for(int k=L; k<=R; ++k) (a[k]>x[j]+tag)&&(a[k]-=x[j]),f[a[k]]=cnt[a[k]]=0;
                mx=0;
                for(int k=i; k<i+bl; ++k) (mx<a[k])&&(mx=a[k]),(f[a[k]])?(fa[k]=f[a[k]]):(f[a[k]]=fa[k]=k),++cnt[a[k]];
            }
        }
        else
        { 
            if(mx<x[j]+tag || r[j]<i || l[j]>=i+bl) continue;
            if(l[j]<=i && r[j]>=i+bl-1) ans[j]+=cnt[x[j]+tag];
            else 
            {
                for(int k=i; k<i+bl&&k<=n; ++k) a[k]=a[find(k)];
                int L=max(l[j],i),R=min(r[j],i+bl-1);
                for(int k=L; k<=R; ++k) if(a[k]==x[j]+tag) ++ans[j];
            }
        }
    }
    for(int i=0; i<m; i++) if(opt[i]==2) printf("%d\n",ans[i]);
    return 0;
}