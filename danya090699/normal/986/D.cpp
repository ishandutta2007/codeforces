#include <bits/stdc++.h>
using namespace std;
const int sz=(1<<20), bl=1e6;

const int mod1=998244353, w1=3;//998244353=7*17*(2^23)+1

const int mod2=897581057, w2=3;//897581057=107*(2^23)+1

int po(int x, int y, int mod)
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
int rev(int x, int mod){return po(x, mod-2, mod);}

void ntt(int *A, int n, int w, int mod)
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

void copy(int *A2, int *A, int n)
{
    for(int a=0; a<n; a++) A2[a]=A[a];
}



void mul(int (*A)[sz], int (*B)[sz], int *re, int n, int *mod, int *w)
{
    int C[2][n];
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n; a++) C[i][a]=(1ll*A[i][a]*B[i][a])%mod[i];
        ntt(C[i], n, rev(w[i], mod[i]), mod[i]);
        int rn=rev(n, mod[i]);
        for(int a=0; a<n; a++) C[i][a]=(1ll*C[i][a]*rn)%mod[i];
    }

    long long pr=0;
    for(int i=0; i<n; i++)
    {
        int m1=mod[0], os1=C[0][i], m2=mod[1], os2=C[1][i];
        if(m1<m2)
        {
            swap(m1, m2), swap(os1, os2);
        }
        int a=m2, b=os1-os2, m=m1;//a*x=b(mod m)
        if(b<0) b+=m;
        int x=(1ll*b*rev(a, m))%m;
        long long va=1ll*m2*x+os2;
        va+=pr;
        re[i]=va%bl, pr=va/bl;
    }
}

void mul2(int *A, int *an, int n, int x)
{
    int pr=0;
    for(int a=0; a<n; a++)
    {
        an[a]=(A[a]*x+pr)%bl, pr=(A[a]*x+pr)/bl;
    }
}
bool comp(int *A, int *B, int n)//true if A<=B
{
    for(int a=n-1; a>=0; a--)
    {
        if(A[a]<B[a]) return true;
        if(A[a]>B[a]) return false;
    }
    return true;
}

int cu[sz], re[sz], ch[sz], te[sz];
int A[2][sz], B[2][sz];
char s[sz*2];
int main()
{
    //freopen("input.txt", "r", stdin);
    gets(s);
    int m=0;
    while(s[m]>='0' and s[m]<='9') m++;
    for(int a=0; a<m; a+=6)
    {
        int st=1;
        for(int b=a; b<min(a+6, m); b++)
        {
            ch[a/6]+=st*(s[m-1-b]-'0'), st*=10;
        }
    }

    int st=floor(m*1.0/log10(3)), n=2;
    st=max(0, st-3);
    int st2=st;
    cu[0]=3, re[0]=1;
    while(st)
    {
        int mod[2]={mod1, mod2}, w[2]={po(w1, (mod1-1)/n, mod1), po(w2, (mod2-1)/n, mod2)};

        copy(A[0], cu, n), copy(A[1], cu, n);
        ntt(A[0], n, w[0], mod[0]);
        ntt(A[1], n, w[1], mod[1]);

        if(st&1)
        {
            copy(B[0], re, n), copy(B[1], re, n);
            ntt(B[0], n, w[0], mod[0]);
            ntt(B[1], n, w[1], mod[1]);

            mul(A, B, re, n, mod, w);
        }
        st>>=1;
        if(st)
        {
            mul(A, A, cu, n, mod, w);
            for(int a=n/2; a<n; a++)
            {
                if(cu[a])
                {
                    n*=2;
                    break;
                }
            }
        }
    }
    for(int a=n-1; a>=0; a--)
    {
        if(re[a])
        {
            n=max(m/6+1, a+1);
            break;
        }
    }
    n+=10;
    while(1)
    {
        mul2(re, te, n, 9);
        if(comp(te, ch, n))
        {
            mul2(re, te, n, 3);
            copy(re, te, n), st2++;
        }
        else break;
    }
    int l=0, r=9;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        mul2(re, te, n, mid);
        if(comp(ch, te, n)) r=mid;
        else l=mid;
    }
    int an=st2*3;
    if(r<=5)
    {
        if(r==1)
        {
            if(st2==0) an++;
        }
        else an+=r;
    }
    else if(r==6) an+=5;
    else an+=6;
    cout<<an;
}