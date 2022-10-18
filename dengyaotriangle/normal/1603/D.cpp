#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;

int prm[maxn],prc;
bool ntp[maxn];
int mu[maxn];
long long p[maxn];
struct poi{
    int val;
    long long lsum;
};
vector<poi> vec[maxn];
bool operator<(const poi&a,const poi&b){
    return a.val<b.val;
}

const int maxk=20;
long long dp[maxk][maxn];

void solve(int id,int l,int r,int kl,int kr){
    if(kl>kr)return;
    int km=(kl+kr)/2;
    int cid=-1;
    auto it=upper_bound(vec[km].begin(),vec[km].end(),poi{l+1,0});
    long long g=it->lsum+(it->val-(l+1))*(((it-1)->lsum-it->lsum)/(it->val-(it-1)->val));
    for(int i=l;i<km&&i<=r;i++){
        long long cur=dp[id][i]+g;
        g-=p[km/(i+1)];
        if(cur<dp[id+1][km])dp[id+1][km]=cur,cid=i;
    }
    solve(id,l,cid,kl,km-1);
    solve(id,cid,r,km+1,kr);
}
int main(){
    mu[1]=1;
    for(int i=2;i<maxn;i++){
        if(!ntp[i]){
            prm[++prc]=i;
            mu[i]=-1;
        }
        for(int j=1;i*prm[j]<maxn;j++){
            ntp[i*prm[j]]=1;
            if(i%prm[j])mu[i*prm[j]]=-mu[i];
            else{
                mu[i*prm[j]]=0;
                break;
            }
        }
    }
    for(int i=1;i<maxn;i++)if(mu[i]){
        for(int j=1;i*j<maxn;j++){
            int l=i*j,r=i*(j+1);
            long long cur=mu[i]*j*(long long)(j+1)/2;
            p[l]+=cur;
            if(r<maxn)p[r]-=cur;
        }
    }
    for(int i=1;i<maxn;i++)p[i]+=p[i-1];
    for(int i=1;i<maxn;i++){
        vec[i].reserve(sqrt(i)*2+1);
        for(int j=1;j<=i;j++){
            int cd=i/j;
            int rj=i/cd;
            vec[i].push_back(poi{j,p[cd]*(long long)(rj-j+1)});
            j=rj;
        }
        vec[i].push_back(poi{i+1,0});
        for(int j=vec[i].size()-1;j;j--)vec[i][j-1].lsum+=vec[i][j].lsum;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[1][0]=0;
    for(int i=1;i<maxn;i++)dp[1][i]=i*(long long)(i+1)/2;
    for(int k=2;k<maxk;k++){
        dp[k][0]=0;
        solve(k-1,0,maxn-1,1,maxn-1);
    }
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<dp[min(k,maxk-1)][n]<<'\n';
    }
    return 0;
}