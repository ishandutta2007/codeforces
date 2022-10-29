#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
inline void readi(int &x);
const int maxn=1000000;
int n,k,a[maxn+5],b[2*maxn+5],maxa,mina;

void init()
{
    readi(n),readi(k);
    maxa=0;mina=maxn*2;
    for(int i=1;i<=n;i++)
    {
        readi(a[i]),b[a[i]]++;
        maxa=max(a[i],maxa);
        mina=min(a[i],mina);
    }
    for(int i=1;i<=maxa+maxa+2;i++)
        b[i]+=b[i-1];
}

bool work(int d)
{
    int cnt=0;
    for(int i=d;i<=maxa;i+=d)
        cnt+=b[i+k]-b[i-1];
    return cnt==n;
}

int main()
{
    init();
    if(mina<=k+1){printf("%d\n",mina);return 0;}
    for(int i=mina;i>k;i--)
        if(work(i)){printf("%d\n",i);return 0;}
    return 0;
}

inline void readi(int &x)
{char c;for(c=getchar();c>'9'||c<'0';c=getchar());
x=c^'0';for(c=getchar();c>='0'&&c<='9';c=getchar())x=x*10+(c^'0');}