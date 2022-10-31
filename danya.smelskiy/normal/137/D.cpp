#include <bits/stdc++.h>
using namespace std;

string s;
int m;
int dp1[505][505];
int dp2[505][505];
int pred[505][505];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>m;
    int n=s.size();
    for (int i=1;i<=n;++i)
    for (int j=i;j<=n;++j) {
        int l=i;
        int r=j;
        int res=0;
        while (l<r) {
            if (s[l-1]!=s[r-1]) ++res;
            ++l;
            --r;
        }
        dp1[i][j]=res;
    }
    for (int i=0;i<=n;++i)
        for (int j=0;j<=m;++j)
            dp2[i][j]=1e9;
    dp2[0][0]=0;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) if (dp2[i][j]!=1e9) {
            for (int k=i+1;k<=n;++k){
                int len=dp2[i][j]+dp1[i+1][k];
                if (len<dp2[k][j+1]) {
                    dp2[k][j+1]=len;
                    pred[k][j+1]=i;
                }
            }
        }
    }
    int pos=0;
    int mx=1e9;
    for (int i=1;i<=m;++i)
    if (dp2[n][i]<mx) {
        mx=dp2[n][i];
        pos=i;
    }
    cout<<mx<<'\n';
    vector<string> res;
    for (int i=pos;i>0;--i) {
        string nw="";
        for (int j=pred[n][i]+1;j<=n;++j)
            nw+=s[j-1];
        res.push_back(nw);
        n=pred[n][i];
    }
    string ans="";
    for (int i=res.size()-1;i>=0;--i){
        int l=0;
        int r=res[i].size()-1;
        while (l<r) {
            res[i][l]=res[i][r];
            ++l; --r;
        }
        ans+=res[i];
        if (i) ans+="+";
    }
    cout<<ans;
}