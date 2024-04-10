#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int xs,ys;
int n;
int xx[100],yy[100];
int dp[(1<<24)+2];
pair<int,int> pred[(1<<24)+2];

long long get_dist(long long x,long long y,long long x2,long long y2){
    return (x-x2)*(x-x2)+(y-y2)*(y-y2);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>xs>>ys;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>xx[i]>>yy[i];
    for (int i=0;i<(1<<n);++i)
        dp[i]=inf;
    dp[0]=0;
    for (int i=0;i<(1<<n);++i) if (dp[i]!=inf) {
        for (int j=0;j<n;++j) if (!(i&(1<<j))){
            long long len1=get_dist(xs,ys,xx[j],yy[j]);
            int mask2=i;
            mask2=(mask2^(1<<j));
            if (dp[mask2]>dp[i]+len1+len1) {
                dp[mask2]=dp[i]+len1*2;
                pred[mask2]=make_pair(j,-1);
            }
            for (int k=j+1;k<n;++k) if (!(i&(1<<k))) {
                long long len2=get_dist(xs,ys,xx[k],yy[k]);
                long long len3=get_dist(xx[k],yy[k],xx[j],yy[j]);
                int mask=i;
                mask=(mask^(1<<j));
                mask=(mask^(1<<k));
                if (len1+len2+len3+dp[i]<dp[mask]) {
                    dp[mask]=len1+len2+len3+dp[i];
                    pred[mask]=make_pair(j,k);
                }
            }
            break;
        }
    }
    int mask=(1<<n)-1;
    cout<<dp[mask]<<'\n';
    vector<int> q;
    while (mask) {
        q.push_back(0);
        q.push_back(pred[mask].first+1);
        if (pred[mask].second!=-1) q.push_back(pred[mask].second+1);
        int x=pred[mask].first;
        int y=pred[mask].second;
        mask^=(1<<x);
        if (y!=-1) mask^=(1<<y);
    }
    q.push_back(0);
    for (int i=q.size()-1;i>=0;--i)
        cout<<q[i]<<" ";
}