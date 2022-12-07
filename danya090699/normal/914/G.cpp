#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7, sz=1<<17;
int sum(int x, int y)
{
    int re=x+y;
    if(re>=mod) re-=mod;
    return re;
}
int dif(int x, int y)
{
    int re=x-y;
    if(re<0) re+=mod;
    return re;
}
int mul(int x, int y)
{
    return (1ll*x*y)%mod;
}
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=mul(re, x);
        y>>=1;
        x=mul(x, x);
    }
    return re;
}
int q[sz], fib[sz], A[sz], B[sz], C[sz], rev2=po(2, mod-2);

void transform(int *A, int n, bool invert, string type)
{
    int i=n>>1;
    if(invert) i=1;
    while(i>0 and i<n)
    {
        int a=0;
        while(a<n)
        {
            for(int b=a; b<a+i; b++)
            {
                int x=A[b], y=A[b+i];
                if(type=="and")
                {
                    if(!invert) A[b]=sum(x, y), A[b+i]=y;
                    else A[b]=dif(x, y), A[b+i]=y;
                }
                if(type=="xor")
                {
                    A[b]=sum(x, y), A[b+i]=dif(x, y);
                    if(invert) A[b]=mul(A[b], rev2), A[b+i]=mul(A[b+i], rev2);
                }
            }
            a+=i<<1;
        }
        if(!invert) i>>=1;
        else i<<=1;
    }
}
int main()
{
    fib[0]=0, fib[1]=1;
    for(int a=2; a<sz; a++) fib[a]=sum(fib[a-1], fib[a-2]);
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        q[x]++;
    }
    for(int mask=0; mask<sz; mask++)
    {
        for(int mask2=mask; ; mask2=(mask2-1)&mask)
        {
            A[mask]=sum(A[mask], mul(q[mask^mask2], q[mask2]));
            if(mask2==0) break;
        }
        A[mask]=mul(A[mask], fib[mask]);
    }

    for(int a=0; a<sz; a++) B[a]=mul(q[a], fib[a]);

    int te[sz], te2[sz];
    for(int a=0; a<sz; a++) te[a]=q[a], te2[a]=q[a];
    transform(te, sz, 0, "xor");
    transform(te2, sz, 0, "xor");
    for(int a=0; a<sz; a++) C[a]=mul(te[a], te2[a]);
    transform(C, sz, 1, "xor");
    for(int a=0; a<sz; a++) C[a]=mul(C[a], fib[a]);

    transform(A, sz, 0, "and");
    transform(B, sz, 0, "and");
    transform(C, sz, 0, "and");
    for(int a=0; a<sz; a++)
    {
        A[a]=mul(A[a], B[a]);
        A[a]=mul(A[a], C[a]);
    }
    transform(A, sz, 1, "and");

    int an=0;
    for(int a=1; a<sz; a<<=1) an=sum(an, A[a]);
    cout<<an;
}