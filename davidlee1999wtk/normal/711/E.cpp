#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000003
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL ksm(LL a,LL b)
{
    LL c=1,d=a;
    while(b)
    {
        if(b&1)
            c=(c*d)%P;
        d=(d*d)%P;
        b>>=1;
    }
    return c;
}

LL ksm2(LL a,LL b)
{
    LL c=1,d=a;
    while(b)
    {
        if(b&1)
            c=(c*d);
        d=(d*d);
        b>>=1;
    }
    return c;
}

int main()
{
    LL n,k,tk,fz=1,fm,t,C=0,inv,i,K;
    cin>>n>>k;
    if(n<=60)
    {
        t=ksm2(2,n);
        if(k>t)
        {
            printf("1 1\n");
            return 0;
        }
    }
    tk=k-1;
    while(tk)
    {
        C+=tk/2;
        tk/=2;
    }
    inv=ksm(ksm(2,C),P-2);
    K=ksm(2,n);
    if(k>=P)
        fz=0;
    else
    {
        for(i=K-1;i>=K-k+1;i--)
            fz=fz*(i+P)%P;
        fz=fz*inv%P;
    }
    fm=ksm(K,k-1)*inv%P;

    fz=(fm-fz+P)%P;
    cout<<fz<<' '<<fm<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/