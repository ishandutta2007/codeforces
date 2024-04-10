#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003];
int A[100003],B[100003],la=0,lb=0;
int O[100003],qwq[100003],fyy[100003],cnt=0;
void print(int x,int y,int z)
{
    O[++cnt]=x,qwq[cnt]=y,fyy[cnt]=z;
    return ;
}
void pr()
{
    printf("%lld\n",cnt);
    for(int i=1; i<=cnt; ++i) printf("%lld %lld %lld\n",O[i],qwq[i],fyy[i]);
}
signed main()
{
    int n=read(),m=read();
    if(m==1)
    {
        int a=read(),b=read(),c=read();
        puts("1");
        printf("%lld %lld %lld\n",read(),read(),read());
        return 0;
    }
    for(int i=1,x,y,z; i<=m; i++)
    {
        x=read(),y=read(),z=read();
        a[x]-=z,a[y]+=z;
    }
    for(int i=1; i<=n; i++) if(a[i]<0) 
    {
        A[++la]=i;
    }
    else if(a[i]>0) B[++lb]=i;
    if(la==0)
    {
        puts("0");
        return 0;
    }
    for(int cur=1,t=1,r=-a[A[1]]; cur<=la; cur++,r=-a[A[cur]])
    {
        while(1)
        {
            if(t>lb) return 0;
            if(r==0) break;
            if(a[B[t]]>=r) 
            {
                print(A[cur],B[t],r);
                a[B[t]]-=r;
                if(a[B[t]]==0) ++t;
                break;
            }
            else
            {
                print(A[cur],B[t],a[B[t]]);
                r-=a[B[t]];
                ++t;
            }
        }
    }
    pr();
	return 0;
}