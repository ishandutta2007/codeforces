#include <bits/stdc++.h>
using namespace std;



string s,ss;
int f[100005];
bool used[2][100005];
int dp[2][100005];
int p[100005][26];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss;
    for (int i=1;i<ss.size();++i) {
        int j=f[i];
        while (j && ss[i]!=ss[j]) j=f[j];
        if (ss[i]==ss[j]) ++j;
        f[i+1]=j;
    }
    p[0][ss[0]-'a']=1;
    for (int i=1;i<ss.size();++i) {
        for (int j=0;j<26;++j) {
            if (ss[i]-'a'==j) p[i][j]=i+1;
            else p[i][j]=p[f[i]][j];
        }
    }
    int x=0,y=1;
    used[0][0]=true;
    for (int i=1;i<=s.size();++i) {
        swap(x,y);
        memset(used[x],false,sizeof(used[x]));
        memset(dp[x],0,sizeof(dp[x]));
        for (int j=0;j<(int)ss.size();++j)  if (used[y][j]) {
            for (int k=0;k<26;++k) {
                if (s[i-1]!='?' && k!=s[i-1]-'a') continue;
                int nxt=p[j][k];
                if (nxt==ss.size()) {
                    dp[x][f[nxt]]=max(dp[x][f[nxt]],dp[y][j]+1);
                    used[x][f[nxt]]=true;
                } else {
                    dp[x][nxt]=max(dp[x][nxt],dp[y][j]);
                    used[x][nxt]=true;
                }
            }
        }
    }
    int res=0;
    for (int i=0;i<=ss.size();++i)
        res=max(res,dp[x][i]);
    cout<<res;
}