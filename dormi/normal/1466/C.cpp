#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int dp[26][26];
pair<pii,pii> mi[2][26];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        int cur=0;
        for(int j=0;j<26;j++)mi[cur][j]={{0,(j+1)%26},{0,(j+2)%26}};
        for(int i=1;i<=sz(a);i++){
            for(int j=0;j<26;j++)mi[!cur][j]={{MN,-1},{MN,-1}};
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    if(j==k)dp[j][k]=MN;
                    else{
                        if(mi[cur][j].first.second==k)dp[j][k]=mi[cur][j].second.first+((a[i-1]-'a')==k?0:1);
                        else dp[j][k]=mi[cur][j].first.first+((a[i-1]-'a')==k?0:1);
                    }
                    if(pii{dp[j][k],j}<mi[!cur][k].first)mi[!cur][k].second=mi[!cur][k].first,mi[!cur][k].first={dp[j][k],j};
                    else if(pii{dp[j][k],j}<mi[!cur][k].second)mi[!cur][k].second={dp[j][k],j};
                }
            }
            cur=!cur;
        }
        int ans=MN;
        for(int j=0;j<26;j++)for(int k=0;k<26;k++)ans=min(ans,dp[j][k]);
        printf("%d\n",ans);
    }
    return 0;
}