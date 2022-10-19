#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[100010],pt[100010],ps[100010];
long long sum[100010];
vector<int> stu[100010];
int minn[200010][20],Log[200010];
int Ask(int l,int r){
    // printf("Ask %d %d\n",l,r);
    if(l>r) return 2e9;
    int t=Log[r-l+1];
    // printf("%d %d %d\n",t,minn[l][t],minn[r-(1<<t)+1][t]);
    return min(minn[l][t],minn[r-(1<<t)+1][t]);
}
void solve(){
    scanf("%d %d",&n,&m);vector<pair<double,int> > vec;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        vec.push_back(make_pair(a[i],i));
    }
    for(int i=1,k,x;i<=m;i++){
        scanf("%d",&k);
        while(k--){
            scanf("%d",&x);sum[i]+=x;
            stu[i].push_back(x);
        }vec.push_back(make_pair(1.0L*sum[i]/stu[i].size(),-i));
    }sort(vec.begin(),vec.end());
    for(int i=vec.size()-1,val=0;i>=0;i--){
        if(vec[i].second>0) pt[vec[i].second]=i,val++;
        else ps[-vec[i].second]=i,val--;
        minn[i][0]=val;
        // printf("%d %lf %d %d\n",i,vec[i].first,vec[i].second,val);
    }
    Log[0]=-1;for(int i=1;i<=vec.size();i++) Log[i]=Log[i>>1]+1;
    for(int i=1;i<20;i++){
        for(int j=0;j+(1<<i)-1<vec.size();j++){
            minn[j][i]=min(minn[j][i-1],minn[j+(1<<(i-1))][i-1]);
        }
    }
    for(int i=1;i<=m;i++){
        for(auto x:stu[i]){
            double nt=1.0L*(sum[i]-x)/(stu[i].size()-1);
            int t=upper_bound(vec.begin(),vec.end(),make_pair(nt,0))-vec.begin(),minn;
            // printf("%lf %d %d\n",nt,t,ps[i]);
            if(t>ps[i]) minn=min(Ask(t,vec.size()-1),min(Ask(ps[i]+1,t)-1,Ask(0,ps[i]-1)));
            else minn=min(Ask(ps[i]+1,vec.size()-1),min(Ask(t,ps[i]-1)+1,Ask(0,t)));
            printf("%d",minn<0?0:1);
        }
    }puts("");
    for(int i=0;i<=n+1;i++){
        a[i]=sum[i]=Log[i]=0;
        stu[i].clear();pt[i]=ps[i]=0;
        memset(minn[i],0,sizeof(minn[i]));
    }
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}