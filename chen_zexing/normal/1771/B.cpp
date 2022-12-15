#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
vector <int> v[100005];
int cnt[100005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a[i],&b[i]),cnt[i]=0;
            if(a[i]>b[i]) swap(a[i],b[i]);
            v[a[i]].push_back(i),v[b[i]].push_back(i);
        }
        long long ans=0;
        for(int i=1,r=1,c2=0,stp=0;i<=n;i++){
            while(r<=n&&!c2){
                if(!stp) {
                    for (auto t:v[r]) {
                        cnt[t]++;
                        if (cnt[t] == 2) c2++;
                    }
                }
                if(!c2) r++,stp=0;
                else stp=1;
            }
            ans+=r-i;
            for(auto t:v[i]){
                cnt[t]--;
                if(cnt[t]==1) c2--;
            }
            //cout<<i<<" "<<ans<<" "<<c2<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}