#include<bits/stdc++.h>
using namespace std;
const int N=4400005;
const int MOD=998244353;
int MUL(int x,int y){return 1ll*x*y%MOD;}
int ADD(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
inline int read(){
    int ret=0; char c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c<='9'&&c>='0') ret=(ret<<3)+(ret<<1)+c-'0',c=getchar();
    return ret;
}
const int G=3;
const int IG=332748118;
int wn[N],wn_1[N];

int qpow(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1) ret=MUL(ret,x);
        x=MUL(x,x);
        y>>=1;
    }
    return ret;
}

namespace Poly{
    int rev[N];
    void getrev(int len){
        rev[0]=0; rev[len-1]=len-1;
        for(int i=1;i<len-1;i++) rev[i]=(rev[i>>1]>>1)+(i&1 ? len>>1 : 0);
    }
    void ntt(int *a,int len,int flag){
        for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
        for(int h=1;h<len;h<<=1)
        {
            int w=(flag==-1 ? wn_1[h<<1] : wn[h<<1]);
            for(int i=0;i<len;i+=h*2)
            {
                int W=1;
                for(int j=i;j<i+h;j++)
                {
                    int tmp1=a[j],tmp2=MUL(W,a[j+h]);
                    a[j]=ADD(tmp1,tmp2);
                    a[j+h]=(tmp1-tmp2+MOD)%MOD;
                    W=MUL(W,w);
                }
            }
        }
        if(flag==-1)
        {
            int tmp=qpow(len,MOD-2);
            for(int i=0;i<len;i++) a[i]=MUL(tmp,a[i]);
        }
    }
}

int len=1,n,m,t[N],a[N],b[N];
void init()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) t[i]=read();
    while(len<=m) len<<=1;
    len<<=1;
    for(int i=1;i<=n;i++) a[t[i]]=1;
    for(int i=1;i<=m;i++) b[i]=a[i];
    Poly::getrev(len);
    for(int h=1;h<=len;h<<=1) wn[h]=qpow(3,(MOD-1)/h),wn_1[h]=qpow(IG,(MOD-1)/h);
}

vector<int> ans;
void solve()
{
    Poly::ntt(a,len,1);
    for(int i=0;i<len;i++) a[i]=MUL(a[i],a[i]);
    Poly::ntt(a,len,-1);
    for(int i=1;i<=m;i++) if(a[i]&&!b[i]) 
    {
        puts("NO");
        exit(0);
    }
    for(int i=1;i<=m;i++) if(!a[i]&&b[i]) ans.push_back(i);
    puts("YES");
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
    cout<<endl;
}

int main()
{
    init();
    solve();
    return 0;
}