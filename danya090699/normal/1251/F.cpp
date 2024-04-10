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
int rev(int x){return po(x, mod-2);}

int conv[2][19][sz], one[sz], w=po(3, (mod-1)/sz);

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
int q[sz];
main()
{
    one[0]=1;
    conv[0][0][0]=1, conv[0][0][1]=2;
    conv[1][0][0]=1, conv[1][0][1]=2, conv[1][0][2]=1;

    ntt(one, sz, w);
    ntt(conv[0][0], sz, w);
    ntt(conv[1][0], sz, w);

    for(int i=0; i<2; i++)
    {
        for(int j=1; j<19; j++)
        {
            for(int a=0; a<sz; a++) conv[i][j][a]=(1ll*conv[i][j-1][a]*conv[i][j-1][a])%mod;
        }
    }

    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[k];
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        q[x]++;
    }
    for(int a=0; a<k; a++) scanf("%d", &ar[a]);
    int qq;
    cin>>qq;
    int per[qq], an[qq];
    for(int a=0; a<qq; a++)
    {
        scanf("%d", &per[a]);
        an[a]=0;
    }
    for(int a=0; a<k; a++)
    {
        int st[2]={0, 0}, re[2][sz], cu[sz];
        for(int b=0; b<sz; b++) re[0][b]=one[b], re[1][b]=one[b];

        for(int b=1; b<ar[a]; b++)
        {
            if(q[b]==1) st[0]++;
            if(q[b]>1) st[1]++;
        }
        for(int i=0; i<2; i++)
        {
            for(int b=0; b<sz; b++) re[i][b]=one[b];
            int j=0;
            while(st[i])
            {
                if(st[i]&1)
                {
                    for(int b=0; b<sz; b++) re[i][b]=(1ll*re[i][b]*conv[i][j][b])%mod;
                }
                j++, st[i]>>=1;
            }
        }
        for(int b=0; b<sz; b++) cu[b]=(1ll*re[0][b]*re[1][b])%mod;
        ntt(cu, sz, rev(w));
        int rn=rev(sz);
        for(int b=0; b<sz; b++) cu[b]=(1ll*cu[b]*rn)%mod;

        for(int b=0; b<qq; b++)
        {
            int i=(per[b]-ar[a]*2-2)/2;
            if(i>=0 and i<sz) an[b]=(an[b]+cu[i])%mod;
        }
    }
    for(int a=0; a<qq; a++) printf("%d\n", an[a]);
}