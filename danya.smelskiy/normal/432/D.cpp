#include <bits/stdc++.h>
using namespace std;

string s;
vector<pair<int,int> > ans;
int p[100005];
int dp[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    int n=s.size();
    for (int i=1;i<n;++i) {
        int j=p[i-1];
        while (j && s[j]!=s[i]) j=p[j-1];
        if (s[j]==s[i]) ++j;
        p[i]=j;
        ++dp[j];
    }
    for (int i=n-1;i>0;--i) {
        dp[p[i-1]]+=dp[i];
    }
    ans.push_back(make_pair(n,1));
    n=p[n-1];
    while (n) {
        ans.push_back(make_pair(n,dp[n]+1));
        n=p[n-1];
    }
    cout<<ans.size()<<'\n';
    for (int i=ans.size()-1;i>=0;--i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}