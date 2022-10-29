#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int inf=(int)5e18;
const int N=120000;
int n,a[N],m,b[N];
int pre[N],nxt[N];
int q[N],top=0;
int _abs(int x){return x<0 ? -x : x;}
void solve(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i>1) b[i-1]=_abs(a[i]-a[i-1]);
    }
    b[0]=b[n]=inf; q[++top]=0;
    for(int i=1;i<=n;i++){
        while(b[q[top]]<b[i]) nxt[q[top]]=i, top--;
        pre[i]=q[top]; q[++top]=i;
    }
    //for(int i=1;i<=n;i++) cout<<b[i]<<" "; cout<<endl;
    //for(int i=1;i<=n;i++) cout<<i<<" "<<pre[i]<<" "<<nxt[i]<<endl;
    while(m--){
        int ans=0;
        int l,r; scanf("%lld%lld",&l,&r);
        r--;
        for(int i=l;i<=r;i++){
            int L=max(l,pre[i]+1);
            int R=min(r,nxt[i]-1);
            ans+=(R-i+1)*(i-L+1)*b[i];
        }
        printf("%lld\n",ans);
    }
}

signed main()
{
    int TTT=1; //scanf("%d",&TTT);
    while(TTT--){solve();}
    return 0;
}