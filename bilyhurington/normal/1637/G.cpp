#include<bits/stdc++.h>
using namespace std;
int T,n,Log[100010],cnt[20];
map<int,int> S;
vector<pair<int,int> > Ans;
void pros(int x,int y){
    // printf("%d %d :\n",x,y);
    S[x]--;S[y]--;
    Ans.push_back(make_pair(x,y));
    S[x+y]++;S[abs(x-y)]++;
    // for(auto x:S) printf("%d %d\n",x.first,x.second);puts("");
}
void solve(int n,int m){//m,2*m...,n*m
    if(n<=1) return;
    int t=1<<Log[n];
    for(int i=1;i<=n-t;i++) pros((t-i)*m,(t+i)*m);
    solve(n-t,m*2);
    solve(t-1-(n-t),m);
}
void solve(){memset(cnt,0,sizeof(cnt));Ans.clear();
    scanf("%d",&n);S.clear();
    if(n==2){puts("-1");return;}
    for(int i=1;i<=n;i++) S[i]++;
    solve(n,1);for(int i=0;i<=16;i++) cnt[i]=S[1<<i];
    // for(int i=0;i<=3;i++) printf("%d ",cnt[i]);puts("");
    int t=-1;
    for(int i=16;i>=0;i--){
        if(cnt[i]>=2) t=i; 
    }if(t==-1){puts("-1");return;}
    cnt[t]-=2;pros(1<<t,1<<t);cnt[t+1]++;
    // for(int i=0;i<=3;i++) printf("%d ",cnt[i]);puts("");
    for(int i=0;i<=16;i++){
        if((1<<i)>=n){
            pros(0,1<<i);
            break;
        }int x=cnt[i]/2;
        // printf("%d %d\n",i,cnt[i]);
        for(int j=1;j<=x;j++){
            pros(1<<i,1<<i);
            pros(0,1<<(i+1));
            cnt[i]-=2;cnt[i+1]+=2;
        }
        if(cnt[i]){
            pros(0,1<<i);
            pros(1<<i,1<<i);
            cnt[i]--;cnt[i+1]++;
        }
    }
    printf("%d\n",(int)Ans.size());
    for(auto pr:Ans) printf("%d %d\n",pr.first,pr.second);
}
int main(){
    scanf("%d",&T);Log[0]=-1;
    for(int i=1;i<=100000;i++) Log[i]=Log[i>>1]+1;
    while(T--) solve();
    return 0;
}
// 0 2 2 8 8 8