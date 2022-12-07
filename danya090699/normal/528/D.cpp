#include <bits/stdc++.h>
using namespace std;
const int mod=998244353, sz=(1<<20);
char sy[4]={'A', 'T', 'G', 'C'};

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

int stw[sz];

void ntt(int *A, int n, int w)
{
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

void mul(int *A, int *B, int *C, int n)
{
    int w=po(3, (mod-1)/n);
    //int w=po(5, (1<<20)/n);
    ntt(A, n, w);
    ntt(B, n, w);
    for(int a=0; a<n; a++) C[a]=(1ll*A[a]*B[a])%mod;
    ntt(C, n, rev(w));
    int rn=rev(n);
    for(int a=0; a<n; a++) C[a]=(1ll*C[a]*rn)%mod;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    string s, t;
    cin>>n>>m>>k>>s>>t;
    n=1;
    while(n<s.size()) n<<=1;
    n<<=1;
    m=int(s.size())-int(t.size())+1;
    int A[n], B[n], C[n], an[m];
    for(int a=0; a<m; a++) an[a]=1;
    for(int i=0; i<4; i++)
    {
        for(int a=0; a<n; a++)
        {
            A[a]=0, B[a]=0;
        }
        for(int a=0; a<s.size(); a++)
        {
            if(s[a]==sy[i])
            {
                A[a]=1;
                for(int b=a-1; b>=max(0, a-k); b--)
                {
                    if(s[b]==sy[i]) break;
                    A[b]=1;
                }
                for(int b=a+1; b<=min(int(s.size())-1, a+k); b++)
                {
                    if(s[b]==sy[i]) break;
                    A[b]=1;
                }
            }
        }
        int q=0;
        for(int a=0; a<t.size(); a++)
        {
            if(t[a]==sy[i])
            {
                B[int(s.size())-1-a]=1, q++;
            }
        }
        mul(A, B, C, n);
        for(int a=0; a<m; a++) if(C[int(s.size())-1+a]<q) an[a]=0;
    }
    int q=0;
    for(int a=0; a<m; a++) q+=an[a];
    cout<<q;
}