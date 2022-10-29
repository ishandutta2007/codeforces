#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int N=500005;
#define int long long
const int MOD=(int)1e9+7;
int qpow(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1)ret=ret*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ret;
}

bool cmp(int x,int y){return x>y;}
int t=1,n,a[N];
char s[N];
void init()
{
    scanf("%lld",&n);
    scanf("%s",s+1);
    a[1]=a[2]=a[3]=a[4]=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='A') a[1]++;
        if(s[i]=='G') a[2]++;
        if(s[i]=='C') a[3]++;
        if(s[i]=='T') a[4]++;
    }
    sort(a+1,a+5);
}

void solve()
{
    int tmp=1;
    for(int i=3;i>=1;i--) if(a[i]==a[4]) tmp++;
    printf("%lld\n",qpow(tmp,n));
}

signed main()
{
    while(t--)
    {
        init();
        solve();
    }
    return 0;
}