//think:1D->2D->3D
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int N=1000005;
const int inf=(int)1e9+1;
const ll INF=(ll)5e18;  

int n,bl[N];

void solve()
{
    scanf("%d",&n);
    if(n<=5)
    {
        if(n==3) puts("0");
        else puts("1");
        return;
    }
    int now1=4,now2=5;
    while(now1<=n||now2<=n)
    {
        if(now1==n||now2==n) {puts("1"); return;}
        int tmp1=now1,tmp2=now2;
        now1=tmp1+tmp2+1; now2=tmp1+tmp1+1;
    }
    puts("0");
}

signed main()
{
    int TTT=1; //scanf("%d",&TTT);
    while(TTT--){solve();}
    return 0;
}