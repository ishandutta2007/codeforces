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
#define INF 100000000
#define fi first
#define se second
#define P 1000000007
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL sum=0,inv;
LL ksm(LL a,LL b,LL mod)
{
    LL c=1,d=a;
    while(b)
    {
        if(b&1)
            c=(c*d)%mod;
        d=(d*d)%mod;
        b>>=1;
    }
    return c;
}
int main()
{
    LL a,b,i,lim,ts;
    inv=ksm(2,P-2,P);
    cin>>a>>b;
    for(i=1;i<b;i++)
    {
        lim=i*a;
        ts=((i+lim)%P)*a%P*b%P*inv%P;
        sum=(sum+ts)%P;
        sum=(sum+i*a)%P;
    }
    cout<<sum<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);