#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n,m;
vector<int> q,v[200005];
long long s[200005],dp[200005];
map<int,int> mt;
int last;
pair<int,int> a[100005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    q.push_back(0);
    q.push_back(n);
    for (int i=1;i<=m;++i) {
        cin>>a[i].first>>a[i].second;
        q.push_back(a[i].first);
        q.push_back(a[i].second);
    }
    sort(q.begin(),q.end());
    for (int i=0;i<q.size();++i) {
        if (i && q[i]!=q[i-1]) ++last;
        mt[q[i]]=last;
    }
    for (int i=1;i<=m;++i) {
        a[i].first=mt[a[i].first];
        a[i].second=mt[a[i].second];
        v[a[i].second].push_back(a[i].first);
    }
    dp[0]=1;
    s[0]=1;
    for (int i=1;i<=last;++i) {
        s[i]=s[i-1];
        for (int j=0;j<v[i].size();++j) {
            int x=v[i][j];
            dp[i]=(dp[i]+s[i-1]-(x ? s[x-1] : 0)+md)%md;
        }
        s[i]=(s[i]+dp[i])%md;
    }
    cout<<dp[last];
}