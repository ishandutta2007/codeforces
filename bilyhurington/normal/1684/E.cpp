#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[100010],sum[100010],cnt[100010],id[100010];
void solve(){
    map<int,int> mp;
    scanf("%d %d",&n,&k);
    for(int i=0;i<=n;i++) sum[i]=0,cnt[i]=0,id[i]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mp[a[i]]++;
    }
    vector<pair<int,int> > vec;
    vector<int> ys;
    for(auto pr:mp) vec.push_back(pr),ys.push_back(pr.second);
    ys.push_back(0);sort(ys.begin(),ys.end());
    ys.erase(unique(ys.begin(),ys.end()),ys.end());
    for(int i=0;i<ys.size();i++) id[ys[i]]=i;
    int ans=1e9,tot=vec.size()-1,C=0;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(mp.find(i-1)!=mp.end());
    for(int i=n;i>=0;i--){
        while(tot>=0&&vec[tot].first>=i){
            cnt[id[vec[tot].second]]++;
            tot--;C++;
        }
        if(i-sum[i]>k) continue;
        int t=k,tmp=C;
        for(int j=1;j<ys.size();j++){
            int x=cnt[j],y=ys[j];
            if(t>=x*y){t-=x*y;tmp-=x;continue;}
            tmp-=t/y;break;
        }
        ans=min(ans,tmp);
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}