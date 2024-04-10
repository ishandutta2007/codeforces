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
#define INF 1000000000
#define N 500005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL a,b,T,sl[N],sr[N],v[N];
int n;
char s[N];
int main()
{
    cin>>n>>a>>b>>T;
    scanf("%s",s+1);
    int i,ans=0,l,r;
    for(i=1;i<=n;i++)
        if(s[i]=='w')
            v[i]=b;
    sl[1]=v[1]+1;
    if(sl[1]>T)
    {
        printf("0\n");
        return 0;
    }
    for(i=2;i<=n;i++)
        sl[i]=sl[i-1]+a+1+v[i];
    sr[n+1]=0;
    for(i=n;i;i--)
        sr[i]=sr[i+1]+a+1+v[i];
    l=n,r=n+1;
    while(l>=1)
    {
        while(sl[l]>T) l--;
        while(sl[l]+sr[r]+(l-1)*a<=T&&l<r)
            r--;
        r++;
        r=min(r,n+1);
        ans=max(ans,(n-r+2)+(l-1));
        l--;
    }
    //debug(ans);
    sl[1]=0;
    for(i=2;i<=n;i++)
        sl[i]=sl[i-1]+a+1+v[i];
    sr[n+1]=v[1]+1;
    for(i=n;i;i--)
        sr[i]=sr[i+1]+a+1+v[i];
    l=1,r=1;
    while(r<=n+1)
    {
        while(sr[r]>T) r++;
        while(sl[l]+sr[r]+(n+1-r)*a<=T&&l<r)
            l++;
        l--;
        l=max(l,1);
        ans=max(ans,(n-r+2)+(l-1));
        r++;
    }
    cout<<min(ans,n)<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))