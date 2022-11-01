#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#define For(i,x,y) for (int i=x;i<y;i++)
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid (L+R>>1)
using namespace std;
const int N=350000+19,oo=(1<<30)-1,Len=20000000;
typedef long long LL;
struct Iron
{
    LL D;int m,p;LL r;
    bool operator < (const Iron& B) const {return D<B.D;}
} A[N];
int ID[N*4],Q[N],x0,y0,f,w,n,x,y,m,p,r,Qr,Qx;
LL D[N];
char Buf[Len],*B=Buf;
inline int IN()
{
    int c,x,f;
    while (!isdigit(c=*B++)&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
    while (isdigit(c=*B++)) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}
inline void Update(int x)
{
    ID[x]=A[ID[Lsn]].m<A[ID[Rsn]].m?ID[Lsn]:ID[Rsn];
}
inline void Build(int x,int L,int R)
{
    if (L==R) {ID[x]=L;return;}
    Build(Lsn,L,Mid),Build(Rsn,Mid+1,R);
    Update(x);
}
inline int Query(int x,int L,int R)
{
    if (R<=Qr) return ID[x];
    int res,t;
    res=Query(Lsn,L,Mid);
    if (Qr>Mid&&A[t=Query(Rsn,Mid+1,R)].m<A[res].m) res=t;
    return res;
}
inline void Modify(int x,int L,int R)
{
    if (L==R) {A[L].m=oo;return;}
    Qx<=Mid?Modify(Lsn,L,Mid):Modify(Rsn,Mid+1,R);
    Update(x);
}
inline int Find(LL x)
{
    int L=1,R=n,res=0;
    while (L<=R) if (D[Mid]<=x) res=Mid,L=Mid+1;else R=Mid-1;
    return res;
}
  
int main()
{
    fread(Buf,1,Len,stdin);
    x0=IN(),y0=IN(),A[0].p=IN(),A[0].r=IN(),n=IN();
    A[0].r*=A[0].r;Q[f=1]=0;
    For(i,1,n+1)
    {
        x=IN(),y=IN(),m=IN(),p=IN(),r=IN();
        A[i]=(Iron){1LL*(x-x0)*(x-x0)+1LL*(y-y0)*(y-y0),m,p,1LL*r*r};
    }
    sort(A+1,A+n+1);A[0].m=oo+1;
    For(i,1,n+1) D[i]=A[i].D;
    Build(1,1,n);
    while (f>w)
    {
        w++;int t,x=Q[w];
        if ((Qr=upper_bound(D+1,D+n+1,A[x].r)-D-1)>=1)
            while (~(t=Query(1,1,n))&&A[t].m<=A[x].p) Q[++f]=Qx=t,Modify(1,1,n);
    }
    printf("%d\n",f-1);
}