#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
lli dp[MAXN][(1<<7)];
pair<lli,vector<lli>> score[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,p,k;
    cin>>n>>p>>k;
    for(int i=1;i<=n;i++){
        cin>>score[i].first;
    }
    for(int i=1;i<(1<<p);i++)dp[0][i]=LLONG_MIN;
    lli a;
    for(int i=1;i<=n;i++){
        for(int j=0;j<p;j++){
            cin>>a;
            score[i].second.push_back(a);
        }
    }
    sort(score+1,score+n+1,greater<pair<lli,vector<lli>>>());
    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<p);j++){
            dp[i][j]=dp[i-1][j]+(i-1-__builtin_popcount(j)>=k?0:score[i].first);
            for(int l=0;l<p;l++){
                if(j&(1<<l)){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-(1<<l)]+score[i].second[l]);
                }
            }
        }
    }
    printf("%lli\n",dp[n][(1<<p)-1]);
    return 0;
}