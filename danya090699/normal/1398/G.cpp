#include <bits/stdc++.h>
using namespace std;
const int sz=1<<19, mod=998244353;
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

const int w=po(3, (mod-1)/sz);
int A[sz], B[sz];

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

const int sz2=1e6+10;
int an[sz2];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, y;
    cin>>n>>x>>y;
    for(int a=0; a<=n; a++)
    {
        int p;
        scanf("%d", &p);
        A[p]=1, B[x-p]=1;
    }
    ntt(A, sz, w);
    ntt(B, sz, w);
    for(int a=0; a<sz; a++) A[a]=1ll*A[a]*B[a]%mod;
    ntt(A, sz, po(w, mod-2));
    for(int a=1; a<=x; a++)
    {
        if(A[a+x])
        {
            int l=(y+a)*2;
            for(int b=l; b<sz2; b+=l) an[b]=l;
        }
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int l;
        scanf("%d", &l);
        if(an[l]) printf("%d ", an[l]);
        else printf("-1 ");
    }
}