#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5050,mod=1e9+7;
int n,m,a[N],l[N],r[N],cnt[N][N],ans1=-1,ans2;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),r[a[i]]++;
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        for(int j=y;j<=n;j++)cnt[x][j]++;
    }
    for(int i=0;i<=n;i++){
        if(i)l[a[i]]++,r[a[i]]--;
        int x=a[i],y=l[x];
        if(i&&cnt[x][y]-cnt[x][y-1]==0)continue;
        int now1=0,now2=1;
        if(i){
            now1++;now2=cnt[x][y]-cnt[x][y-1];
            int pp=cnt[x][r[x]]-(r[x]>=l[x]);
            if(pp)now1++,now2=1ll*now2*pp%mod;
        }
        for(int j=1;j<=n;j++)if(j!=x){
            int mn=l[j],mx=r[j];
            if(mn>mx)swap(mn,mx);
            if(cnt[j][mx]){
                if(!cnt[j][mn])now1++,now2=1ll*now2*cnt[j][mx]%mod;
                else if(cnt[j][mx]==1)now1++,now2=2ll*now2*cnt[j][mx]%mod;
                else now1+=2,now2=1ll*now2*cnt[j][mn]%mod*(cnt[j][mx]-1)%mod;
            }
        }
        if(now1>ans1)ans1=now1,ans2=now2;
        else if(now1==ans1)(ans2+=now2)%=mod;
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}