#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
const int inf=(int)1e9;
typedef pair<int,int> pii; 
const double Div=100000.0;
const double PI=acos(-1);
void checkmin(double &x,double y){if(x>y) x=y;}
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

struct Complex{
    double x,y;
    Complex(double x=0,double y=0):x(x),y(y){}
    Complex operator + (const Complex &A) const{
        return Complex(A.x+x,A.y+y);
    }
    Complex operator - (const Complex &A) const{
        return Complex(x-A.x,y-A.y);
    }
    Complex operator * (const Complex &A) const{
        return Complex(x*A.x-y*A.y,x*A.y+A.x*y);
    }
};

namespace Poly{
    Complex a[N],b[N];
    int rev[N];
    int getlen(int n){
        int len=1;
        while(len<n) len<<=1;
        return len;
    }
    void getrev(int len){
        rev[0]=0; rev[len-1]=len-1;
        for(int i=1;i<len-1;i++) rev[i]=(rev[i>>1]>>1)+(i&1 ? len>>1 : 0);
    }
    void fft(Complex *a,int len,int flag){
        for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
        for(int h=1;h<len;h<<=1)
        {
            Complex wn=Complex(cos(2*PI/(h<<1)),flag*sin(2*PI/(h<<1)));
            for(int i=0;i<len;i+=(h<<1))
            {
                Complex w=Complex(1,0);
                for(int j=i;j<i+h;j++)
                {
                    Complex tmp1=a[j],tmp2=a[j+h]*w;
                    a[j]=tmp1+tmp2;
                    a[j+h]=tmp1-tmp2;
                    w=w*wn;
                }
            }
        }
        if(flag==-1) for(int i=0;i<len;i++) a[i].x/=len;
    }
    void multi(Complex *a,Complex *b,int len)
    {
        fft(a,len,1); fft(b,len,1);
        for(int i=0;i<len;i++) a[i]=a[i]*b[i];
        fft(a,len,-1);
    }
}

int n,m,t,x;
double p[102][20005];
double dp[55][N],g[101][N];
struct Edge{
    int from,to,cost;
}E[105];

int dis[55][55];
void init()
{
    n=read(); m=read(); t=read(); x=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=inf;
    for(int i=1;i<=m;i++)
    {
        E[i].from=read(); E[i].to=read(); E[i].cost=read();
        dis[E[i].from][E[i].to]=E[i].cost;
        for(int j=1;j<=t;j++) 
        {
            p[i][j]=read()*1.0/Div;
        }
        reverse(p[i]+1,p[i]+t+1);
        for(int j=1;j<=t;j++) g[i][j]=g[i][j-1]+p[i][j];
        reverse(p[i]+1,p[i]+t+1);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=t;j++) dp[i][j]=1.0*inf;
    for(int i=0;i<=t;i++) dp[n][i]=0;
    for(int i=1;i<=m;i++)  
        for(int j=1;j<=t;j++) g[i][j]=g[i][j]*(dis[E[i].to][n]+x);
}

//the right code is using the latter time to update previous time
//this is easy to understand, for the possibility is based on time,using the commom trick
//but why not try another direction? for the sum of the possibility of one edge is 1

//------ans:there is more than one edge transform to the situation dp[i][time],
//so the sum of the possibility of the terminate vertex will be more than one, but if we reverse the edge the sum will be 1 
//besides, if we use the positive direction,there are multiple situation in the end
//but when we reverse it,there is only one
Complex a[N],b[N];
void cdq(int l,int r)
{
    if(l==r)
    {
        for(int i=1;i<=m;i++) 
        {
            checkmin(dp[E[i].from][l],g[i][l]+E[i].cost);
        }
        return;
    }
    int mid=(l+r)>>1;
    cdq(mid+1,r);
    int nn=r-l+1,mm=r-mid;
    int len=Poly::getlen(nn+mm-1);
    Poly::getrev(len);
    for(int i=1;i<=m;i++)//f[E[i].from][t]=\sum_{j=1~t} f[E[i].to][t+j]*P[i][j]+cost
    {
    	b[0]=0;
    	for(int j=0;j<=r-mid-1;j++) a[j]=Complex(dp[E[i].to][r-j],0);
    	for(int j=1;j<=r-l;j++) b[j]=Complex(1.0*p[i][j],0);
    	for(int j=r-mid;j<len;j++) a[j]=Complex(0,0);
    	for(int j=r-l+1;j<len;j++) b[j]=Complex(0,0);
    	Poly::multi(a,b,len);
    	for(int j=l;j<=mid;j++) g[i][j]=g[i][j]+a[r-j].x;
    }
    cdq(l,mid);
}

int main()
{
	init();
	cdq(0,t);
    printf("%.6lf\n",min(dp[1][0],(dis[1][n]+x)*1.0));
    return 0;
}