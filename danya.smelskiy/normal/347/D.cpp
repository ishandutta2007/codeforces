#include <bits/stdc++.h>
using namespace std;

struct st{
    int x,y,z;
};
string s[3];
int p[1005];
int Automat[105][27];
st pred[101][101][101];
int dp[101][101][101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=0;i<3;++i)
        cin>>s[i];
    for (int i=1;i<s[2].size();++i){
        int x=p[i-1];
        while (x && s[2][x]!=s[2][i]) x=p[x-1];
        if (s[2][x]==s[2][i]) ++x;
        p[i]=x;
    }
    for (int i=0;i<s[2].size();++i)
    for (int j=0;j<26;++j) {
        char x=char(j+'A');
        if (i>0 && s[2][i]!=x) Automat[i][j]=Automat[p[i-1]][j];
        else Automat[i][j]=i+(x==s[2][i]);
    }
    st non,ans;
    int maxval=0;
    non.x=-1; non.y=-1; non.z=-1;
    for (int i=0;i<s[0].size();++i)
        for (int j=0;j<s[1].size();++j)
            for (int k=0;k<s[2].size();++k)
                pred[i][j][k]=non;
    for (int i=0;i<s[0].size();++i){
        for (int j=0;j<s[1].size();++j) {
            for (int k=0;k<s[2].size();++k) {
                int x=s[0][i]-'A';
                int next=Automat[k][x];
                if (s[0][i]==s[1][j] && next<s[2].size()) {
                    if (dp[i][j][k]+1>dp[i+1][j+1][next]) {
                        dp[i+1][j+1][next]=dp[i][j][k]+1;
                        pred[i+1][j+1][next].x=i;
                        pred[i+1][j+1][next].y=j;
                        pred[i+1][j+1][next].z=k;
                    }
                }
                if (dp[i][j][k]>dp[i+1][j][k]) {
                    dp[i+1][j][k]=dp[i][j][k];
                    pred[i+1][j][k]=pred[i][j][k];
                }
                if (dp[i][j][k]>dp[i][j+1][k]) {
                    dp[i][j+1][k]=dp[i][j][k];
                    pred[i][j+1][k]=pred[i][j][k];
                }
                if (dp[i][j][k]>maxval) {
                    maxval=dp[i][j][k];
                    ans=pred[i][j][k];
                }
            }
        }
    }
    for (int i=0;i<=s[0].size();++i)
    for (int j=0;j<=s[1].size();++j)
    for (int k=0;k<s[2].size();++k)
    if (dp[i][j][k]>maxval) {
        maxval=dp[i][j][k];
        ans=pred[i][j][k];
    }
    if (maxval==0) {
        cout<<0;
        return 0;
    }
    string res="";
    while (true){
        if (ans.x==-1) break;
        res+=s[0][ans.x];
        ans=pred[ans.x][ans.y][ans.z];
    }
    reverse(res.begin(),res.end());
    cout<<res;
}