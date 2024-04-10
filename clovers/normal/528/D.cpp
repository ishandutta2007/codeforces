#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1400005;
const int MOD=998244353;
const int inf=(int)1e9;
int ADD(int x,int y){return x+y>=MOD ? x+y-MOD : x+y;}
int MUL(int x,int y){return 1ll*x*y%MOD;}

int qpow(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1) ret=MUL(ret,x);
        x=MUL(x,x); y>>=1;
    }
    return ret;
}

namespace Poly{
    int a[N],b[N],rev[N];
    int wn[N],wn_1[N];
    void getinv()
    {
        for(int h=1;h<N;h<<=1) wn[h]=qpow(3,(MOD-1)/h),wn_1[h]=qpow(wn[h],MOD-2); 
    }
    int getlen(int n)
    {
        int len=1;
        while(len<n) len<<=1;
        return len;
    }
    void getrev(int len)
    {
        rev[0]=0; rev[len-1]=len-1;
        for(int i=1;i<len-1;i++) rev[i]=(rev[i>>1]>>1)+(i&1 ? len>>1 : 0);
    }
    void ntt(int a[],int len,int flag)
	{
		for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
		for(int h=1;h<len;h<<=1)
		{
			int Wn=(flag==-1 ? wn_1[h<<1] : wn[h<<1]);
			int tmp1,tmp2;
			for(int i=0;i<len;i+=h*2)
			{
				int w=1;
				for(int j=i;j<i+h;j++)
				{
					tmp1=a[j],tmp2=1LL*a[j+h]*w%MOD;
					a[j]=(tmp1+tmp2)%MOD;
					a[j+h]=(tmp1-tmp2+MOD)%MOD;
					w=1LL*w*Wn%MOD;
				}
			}
		}
		if(flag==-1)
		{
			int inv_len=qpow(len,MOD-2);
			for(int i=0;i<=len;i++) a[i]=MUL(a[i],inv_len);
		}
	}
    void multi(int *a,int *b,int n)
    {
        int len=getlen(n+n-1);
        getrev(len);
        ntt(a,len,1); ntt(b,len,1);
        for(int i=0;i<len;i++) a[i]=MUL(a[i],b[i]);
        ntt(a,len,-1);
    }
}

int n,k,m,val[N],ti[N];
char S[N],T[N];
int a[N],b[N];
void solve(char C)
{
    memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
    int pre=-inf,num=0;
    for(int i=1;i<=m;i++) b[i-1]=(T[i]==C ? 1 : 0),num+=(T[i]==C);
    for(int i=1;i<=n;i++) pre=(S[i]==C ? i : pre),a[i-1]=(pre+k>=i);
    pre=inf;
    for(int i=n;i>=1;i--) pre=(S[i]==C ? i : pre),a[i-1]|=(pre-k<=i);
    reverse(b,b+m);
    Poly::multi(a,b,n+m-1);
    for(int i=0;i<n;i++) val[i]+=(a[i+m-1]==num)*num;
}

int main()
{
    Poly::getinv();
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s",S+1); scanf("%s",T+1);
    solve('A'); solve('G'); solve('C'); solve('T');
    int ans=0;
    for(int i=0;i<n;i++) ans+=(val[i]==m);
    cout<<ans<<endl;
    return 0;
}