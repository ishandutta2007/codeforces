#include <bits/stdc++.h>
using namespace std;
const int mod=998244353, sz=(1<<20);

int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
int rev(int x){return po(x, mod-2);}

void ntt(int *A, int n, int w)
{
    int stw[n];
    stw[0]=1;
    for(int a=1; a<n; a++) stw[a]=(1ll*w*stw[a-1])%mod;
    for(int a=0, b=0; a<n; a++)
    {
        if(a<b) swap(A[a], A[b]);
        int i=(n>>1);
        while(b&i)
        {
            b-=i, i>>=1;
        }
        b+=i;
    }
    int cs=n;
    for(int i=1; i<n; i<<=1)
    {
        cs>>=1;
        for(int a=0; a<n; a+=(i<<1))
        {
            int st=0;
            for(int b=a; b<a+i; b++)
            {
                int x=A[b], y=(1ll*stw[st]*A[b+i])%mod;
                A[b]=x+y;
                if(A[b]>=mod) A[b]-=mod;
                A[b+i]=x-y;
                if(A[b+i]<0) A[b+i]+=mod;
                st+=cs;
            }
        }
    }
}

void mul(int *A, int *B, int *re, int n)
{
    int w=po(3, (mod-1)/n);
    ntt(A, n, w);
    ntt(B, n, w);
    for(int a=0; a<n; a++) re[a]=(1ll*A[a]*B[a])%mod;
    ntt(re, n, rev(w));
    int rn=rev(n);
    for(int a=0; a<n; a++) re[a]=(1ll*re[a]*rn)%mod;
    for(int a=n; a<n*2; a++) re[a]=0;
}

int A[sz], f[sz];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, y;
    cin>>n>>x>>y;
    if(x+y-2<=n-1 and min(x, y)>=1)
    {
        if(n-1==0) cout<<1;
        else
        {
            int m=1;
            while(m<n-1) m<<=1;
            for(int a=0; a<n-1; a++)
            {
                A[a*4]=a, A[a*4+1]=1;
            }
            for(int a=n-1; a<m; a++) A[a*4]=1;
            for(int a=1; a<m; a<<=1)
            {
                for(int b=0; b<m*4; b+=a*8) mul(A+b, A+(b+a*4), A+b, a*4);
            }
            f[0]=1;
            for(int a=1; a<=n; a++) f[a]=(1ll*f[a-1]*a)%mod;
            int c=(1ll*((1ll*f[x+y-2]*rev(f[y-1]))%mod)*rev(f[x-1]))%mod;
            int an=(1ll*A[x+y-2]*c)%mod;
            cout<<an;
        }
    }
    else cout<<0;
}