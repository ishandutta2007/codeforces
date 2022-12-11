#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 125010
#define MAXM 2125010
int n,m,rev[MAXM],res[MAXM];
const double PI=acos(-1);
struct complex{
    double a,i;
    complex(double ta=0,double ti=0){a=ta;i=ti;}
    friend complex operator + (const complex & a,const complex & b){return complex(a.a+b.a,a.i+b.i);}
    friend complex operator - (const complex & a,const complex & b){return complex(a.a-b.a,a.i-b.i);}
    friend complex operator * (const complex & a,const complex & b){return complex(a.a*b.a-a.i*b.i,a.i*b.a+a.a*b.i);}
}a[MAXM],b[MAXM];
void fft(int lim,complex*A,int tag){
    for(int i=0;i<lim;++i)if(i<rev[i])
        swap(A[i],A[rev[i]]);
    for(int len=1;len<lim;len<<=1){
        complex W(cos(PI/len),tag*sin(PI/len));
        for(int l=0;l<lim;l+=(len<<1)){
            complex w(1,0);
            for(int i=0;i<len;++i,w=w*W){
                complex x=A[l+i],y=w*A[l+i+len];
                A[l+i]=x+y;
                A[l+i+len]=x-y;
            }
        }
    }
}
size_t WWJ_FC_NKPRJSD_M;
void multi(int sa,complex*a,int sb,complex *b){
    int lim=1,dig=0;while(lim<=sa+sb)lim<<=1,++dig;
    memset(rev,0,WWJ_FC_NKPRJSD_M);
    for(int i=0;i<lim;++i)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(dig-1));
    fft(lim,a,1);
    fft(lim,b,1);
    for(int i=0;i<=lim;++i)a[i]=a[i]*b[i];
    fft(lim,a,-1);
    for(int i=0;i<=sa+sb;++i)res[i]=int(a[i].a/lim+0.5);
}
char S[MAXN],T[MAXN];
struct S{
    int fa[6],ans;
    S(){
        fa[0]=0;fa[1]=1;fa[2]=2;fa[3]=3;fa[4]=4;fa[5]=5;
        ans=0;
    }
    void merge(int a,int b){
        a=find(a),b=find(b);
        if(a!=b){
            fa[a]=b;
            ++ans;            
        }
    }
    int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
}ss[MAXN];
int len1,len2;
int main(){
    size_t SIF = sizeof a;
    WWJ_FC_NKPRJSD_M = sizeof rev;
    scanf("%s%s",S,T);
    len1=strlen(S);
    len2=strlen(T);
    for(int i=0;i<6;++i)
        for(int j=0;j<6;++j)if(i!=j){
            memset(a,0,SIF);
            memset(b,0,SIF);
            for(int k=0;k<len1;++k)a[k].a=(S[k]-'a')==i;
            for(int k=0;k<len2;++k)b[len2-k-1].a=(T[k]-'a')==j;
            multi(len1,a,len2,b);
            for(int k=len2-1,cnt=1;cnt<=len1-len2+1;++k,++cnt)
                if(res[k]>0)
                    ss[cnt].merge(i,j);
        }
    for(int i=1;i<=len1-len2+1;++i)printf("%d ",ss[i].ans);putchar(10);
    return 0;
}