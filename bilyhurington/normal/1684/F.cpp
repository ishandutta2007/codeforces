#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[200010];
pair<int,int> pr[200010];
bool cmp(pair<int,int> p1,pair<int,int> p2){
    return p1.second<p2.second;
}
vector<int> vec[200010];
void solve(){
    map<int,vector<int> > pos;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),vec[i].clear();
    for(int i=1;i<=n;i++) pos[a[i]].push_back(i);
    for(int i=1;i<=m;i++) scanf("%d %d",&pr[i].first,&pr[i].second);
    sort(pr+1,pr+m+1,cmp);
    for(int i=n,j=m,k=n+1;i>=1;i--){
        while(j>0&&pr[j].second>=i){
            k=min(k,pr[j].first);
            j--;
        }
        int t=lower_bound(pos[a[i]].begin(),pos[a[i]].end(),k)-pos[a[i]].begin();
        if(t<pos[a[i]].size()&&i>pos[a[i]][t]) vec[pos[a[i]][t]].push_back(i);
        // printf("1 %d %d\n",i,t);
    }
    sort(pr+1,pr+m+1);
    for(int i=1,j=1,k=0;i<=n;i++){
        while(j<=m&&pr[j].first<=i){
            k=max(k,pr[j].second);
            j++;
        }
        int t=upper_bound(pos[a[i]].begin(),pos[a[i]].end(),k)-pos[a[i]].begin()-1;
        if(t>=0&&i<pos[a[i]][t]) vec[i].push_back(pos[a[i]][t]);
        // printf("2 %d %d\n",i,t);
    }
    int maxn=0,minn=1e9;
    for(int i=1;i<=n;i++){
        for(auto x:vec[i]){
            maxn=max(maxn,i);
            minn=min(minn,x);
            // printf("L %d %d\n",i,x);
        }
    }
    if(minn>5e8){puts("0");return;}
    int ans=2e9;
    for(int i=1,j=maxn;i<=minn;i++){
        // printf("%d %d\n",i,j);
        ans=min(ans,j-i+1);
        for(auto x:vec[i]){
            j=max(j,x);
        }
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}