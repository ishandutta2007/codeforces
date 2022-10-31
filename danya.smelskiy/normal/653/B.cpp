#include <bits/stdc++.h>
using namespace std;

int n,m;
string s,ss;
string a[100];
string b[100];
long long dp[10][100];
long long ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>s>>ss;
            //swap(s[0],s[1]);
        a[i]=s;
        b[i]=ss;
    }
    dp[1][0]=1;
    for (int i=1;i<n;++i) {
        for (int j=0;j<26;++j) if (dp[i][j]){
            for (int k=1;k<=m;++k) {
                int x=b[k][0]-'a';
                if (x==j) {
                    int y=a[k][0]-'a';
                    dp[i+1][y]+=dp[i][j];
                }
            }
        }
    }
    for (int i=0;i<26;++i)
        ans+=dp[n][i];
    cout<<ans;
}