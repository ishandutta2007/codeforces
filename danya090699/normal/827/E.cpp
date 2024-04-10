#include <bits/stdc++.h>
using namespace std;
const int sz=(1<<20), mod=998244353;
int A[sz], B[sz], C[sz], stw[sz];

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
}

const int bsz=1e6;
char buf[bsz];
int byk;
void nst()
{
    gets(buf), byk=0;
}
void g_in(int &a)
{
    a=0;
    while(buf[byk]>='0' and buf[byk]<='9')
    {
        a=a*10+buf[byk]-'0', byk++;
    }
    byk++;
}
void g_s(string &s)
{
    while(buf[byk]=='V' or buf[byk]=='K' or buf[byk]=='?')
    {
        s.push_back(buf[byk]), byk++;
    }
    byk++;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    nst(), g_in(t);
    for(int i=0; i<t; i++)
    {
        int m, n=1;
        string s;
        nst(), nst(), g_in(m), nst(), g_s(s);
        int an[m+1];
        while(n<m) n<<=1;
        n<<=1;

        for(int a=0; a<n; a++)
        {
            A[a]=0, B[a]=0;
        }
        for(int a=0; a<m; a++)
        {
            an[a+1]=0;
            if(s[a]=='V') A[a]=1;
            if(s[a]=='K') B[m-1-a]=1;
        }

        mul(A, B, C, n);
        for(int a=0; a<m; a++) if(C[m+a]) an[a+1]=1;

        for(int a=0; a<n; a++)
        {
            A[a]=0, B[a]=0;
        }
        for(int a=0; a<m; a++)
        {
            if(s[a]=='K') A[a]=1;
            if(s[a]=='V') B[m-1-a]=1;
        }
        mul(A, B, C, n);
        for(int a=0; a<m; a++) if(C[m+a]) an[a+1]=1;

        int q=m;
        for(int a=1; a<=m; a++)
        {
            for(int b=a; b<=m; b+=a)
            {
                if(an[b])
                {
                    an[a]=1;
                    break;
                }
            }
            q-=an[a];
        }
        printf("%d\n", q);
        for(int a=1; a<=m; a++) if(an[a]==0) printf("%d ", a);
        printf("\n");
    }
}