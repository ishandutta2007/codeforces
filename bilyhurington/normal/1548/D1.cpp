#include<bits/stdc++.h>
using namespace std;
int n,cnt[2][2],cnt2[2][2];
pair<int,int> P[6010];
int main(){
    scanf("%d",&n);
    cnt2[0][0]=cnt2[0][1]=cnt2[1][0]=cnt2[1][1]=n;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&P[i].first,&P[i].second);
        cnt[(P[i].first>>1)&1][(P[i].second>>1)&1]++;
        cnt2[(P[i].first>>1)&1][(P[i].second>>1)&1]--;
    }
    long long ans=0;
    ans+=1ll*cnt[0][0]*(cnt[0][0]-1)*(cnt[0][0]-2)/6;
    ans+=1ll*cnt[0][1]*(cnt[0][1]-1)*(cnt[0][1]-2)/6;
    ans+=1ll*cnt[1][0]*(cnt[1][0]-1)*(cnt[1][0]-2)/6;
    ans+=1ll*cnt[1][1]*(cnt[1][1]-1)*(cnt[1][1]-2)/6;
    ans+=1ll*cnt[0][0]*(cnt[0][0]-1)*cnt2[0][0]/2;
    ans+=1ll*cnt[0][1]*(cnt[0][1]-1)*cnt2[0][1]/2;
    ans+=1ll*cnt[1][0]*(cnt[1][0]-1)*cnt2[1][0]/2;
    ans+=1ll*cnt[1][1]*(cnt[1][1]-1)*cnt2[1][1]/2;
    printf("%lld\n",ans);
    // system("pause");
    return 0;
}