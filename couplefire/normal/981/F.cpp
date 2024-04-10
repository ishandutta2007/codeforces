#include<cstdio>
#include<cstring>
#include<algorithm>
#define ri register int
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const int inf=1<<30;
int n,m;
int a[maxn],b[maxn*3];
 
bool check(ll x){
    int lef=1,rig=n*3;
    for(ri i=1;i<=n;i++){
        while(a[i]-b[lef]>x) lef++;
        while(b[rig]-a[i]>x) rig--;
        lef++; rig++;
    }
    return lef<=rig;
}
 
int main(){
    scanf("%d%d",&n,&m);
    for(ri i=1;i<=n;i++) scanf("%d",&a[i]);
    for(ri i=1;i<=n;i++){
        scanf("%d",&b[i]);
        b[i+n]=b[i]+m;
        b[i+n*2]=b[i]-m;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n*3+1);
    ll l=0,r=inf;
    while(l<r){
        ll mid=l+r>>1ll;
        check(mid)?r=mid:l=mid+1;		
    }
    printf("%lld",l);
    return 0;
}