#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<map>
#define INF 1000000000
#define N 1000005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int K,n,a[N],b[N];
int vl[N],vr[N],c[N];
LL ans;
void solve(int L,int R)
{
    if(L==R) return;
    int mid=(L+R)>>1,i,p1=mid,p2=mid+1,S=0,Sl=0,Sr=0,Ml=0,Mr=0,t;
    while(p1>=L||p2<=R)
    {
        if((max(b[p1],Ml)<=max(b[p2],Mr)||p2>R)&&p1>=L)
        {
            Ml=max(b[p1],Ml);
            S=(S+a[p1])%K;
            Sl=(Sl+a[p1])%K;
            c[p1]=Sl;
            vl[Sl]++;
            p1--;
            t=(Ml-Sl+K)%K;
            ans+=vr[t];
        }
        else
        {
            Mr=max(b[p2],Mr);
            S=(S+a[p2])%K;
            Sr=(Sr+a[p2])%K;
            c[p2]=Sr;
            vr[Sr]++;
            p2++;
            t=(Mr-Sr+K)%K;
            ans+=vl[t];
        }
    }
    for(i=L;i<=mid;i++)
        vl[c[i]]--;
    for(i=mid+1;i<=R;i++)
        vr[c[i]]--;
    solve(L,mid);
    solve(mid+1,R);
}

int main()
{
    int i;
    cin>>n>>K;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
        a[i]%=K;
        //sum[i]+=a[N];
    }
    solve(1,n);
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);