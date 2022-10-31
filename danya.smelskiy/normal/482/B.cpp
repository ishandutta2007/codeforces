#include <bits/stdc++.h>
using namespace std;
long long n,m,l,r,x;
long long q[30][100005];
long long dp[30][100005];
long long last;
vector<pair<pair<long long,long long>,long long> > v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>l>>r>>x;
        for (int j=0;j<30;++j) {
            if ((x&(1<<j))) {
                q[j][l]++;
                q[j][r+1]--;
            }
        }
        v.push_back(make_pair(make_pair(l,r),x));
    }
    for (int i=0;i<30;++i) {
        last=0;
        for (int j=1;j<=n;++j){
            dp[i][j]=dp[i][j-1];
            last+=q[i][j];
            if (last>0)
            dp[i][j]++;
        }
    }
    for (int i=0;i<v.size();++i){
        l=v[i].first.first;
        r=v[i].first.second;
        x=v[i].second;
        for (int j=0;j<30;++j)
        if ((x&(1<<j))) {
                if (dp[j][r]-dp[j][l-1]!=r-l+1) {

                    cout<<"NO";
                    return 0;
                }
        } else {
                if (dp[j][r]-dp[j][l-1]==r-l+1) {
                    cout<<"NO";
                    return 0;
                }
        }
    }
    cout<<"YES"<<'\n';
    for (long long i=1;i<=n;++i){
        long long p=1;
        long long res=0;
        for (long long j=0;j<30;++j){
            if (dp[j][i]-dp[j][i-1]) res=res+p;
            p+=p;
        }
        cout<<res<<" ";
    }
}