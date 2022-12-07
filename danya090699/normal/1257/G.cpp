#include <bits/stdc++.h>
using namespace std;
const int sz=(1<<19), mod=998244353;

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

vector <int> sp;
int ar[sz];
void build(int *ar, int n, int l, int r)
{
    if(l==r) ar[0]=1;
    else if(r-l==1)
    {
        for(int a=0; a<sp[l]; a++) ar[a]=1;
    }
    else
    {
        int l2=l, su=0, x[n], y[n];
        while(l<r and su+sp[l]<n/2) su+=sp[l++];

        build(ar, n/2, l2, l);
        for(int a=0; a<n; a++) x[a]=0;
        for(int a=0; a<n/2; a++) x[a]=ar[a], ar[a]=0;

        l2=l, su=0;
        while(l<r and su+sp[l]<n/2) su+=sp[l++];

        build(ar+n/2, n/2, l2, l);
        for(int a=0; a<n; a++) y[a]=0;
        for(int a=0; a<n/2; a++) y[a]=ar[a+n/2], ar[a+n/2]=0;

        ar[0]=1;
        if(l<r)
        {
            for(int a=0; a<sp[l]; a++) ar[a]=1;
        }

        int w=po(3, (mod-1)/n);
        ntt(x, n, w);
        ntt(y, n, w);
        ntt(ar, n, w);

        for(int a=0; a<n; a++)
        {
            ar[a]=(1ll*ar[a]*x[a])%mod;
            ar[a]=(1ll*ar[a]*y[a])%mod;
        }

        ntt(ar, n, rev(w));
        int rn=rev(n);
        for(int a=0; a<n; a++) ar[a]=(1ll*ar[a]*rn)%mod;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        ma[x]++;
    }
    for(auto it=ma.begin(); it!=ma.end(); it++) sp.push_back((*it).second+1);
    sort(sp.begin(), sp.end());
    build(ar, sz, 0, sp.size());
    cout<<ar[n/2];
}