#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int sz=(1<<18);

int S[6][sz], T[6][sz], stw[sz];
bool sm[sz][6][6], us[6];

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

void ntt(int* A, int n, int w)
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
    for(int a=0; a<n; a++) C[a]=(1ll*A[a]*B[a])%mod;
    ntt(C, n, rev(w));
    int rn=rev(n);
    for(int a=0; a<n; a++) C[a]=(1ll*C[a]*rn)%mod;
}

void dfs(int v, int i)
{
    us[v]=1;
    for(int a=0; a<6; a++) if(sm[i][v][a] and us[a]==0) dfs(a, i);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin>>s>>t;
    int n=1;
    while(n<max(int(s.size()), int(s.size()))) n<<=1;
    n<<=1;
    int w=po(3, (mod-1)/n);

    for(int a=0; a<s.size(); a++) S[s[a]-'a'][a]=1;
    for(int a=0; a<t.size(); a++) T[t[a]-'a'][int(s.size())-1-a]=1;

    for(int a=0; a<6; a++)
    {
        ntt(S[a], n, w);
        ntt(T[a], n, w);
    }
    for(int a=0; a<6; a++)
    {
        for(int b=0; b<6; b++)
        {
            if(a!=b)
            {
                int ve[n];
                mul(S[a], T[b], ve, n);
                for(int c=0; c<=int(s.size())-int(t.size()); c++)
                {
                    int i=int(s.size())-1+c;
                    if(ve[i])
                    {
                        sm[c][a][b]=1, sm[c][b][a]=1;
                    }
                }
            }
        }
    }
    for(int i=0; i<=int(s.size())-int(t.size()); i++)
    {
        for(int a=0; a<6; a++) us[a]=0;
        int an=6;
        for(int a=0; a<6; a++)
        {
            if(us[a]==0)
            {
                dfs(a, i), an--;
            }
        }
        printf("%d ", an);
    }
}