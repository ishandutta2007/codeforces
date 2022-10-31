#include <bits/stdc++.h>
using namespace std;
int n,a,b;
string s;
bool dp[205][205];
int pred[205][205];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    cin>>s;
    int m=s.size();
    dp[0][0]=true;
    for (int i=1;i<=m;++i) {
        for (int j=1;j<=n;++j)
        for (int k=a;k<=min(i,b);++k) {
            if (dp[i-k][j-1]) {
                dp[i][j]=true;
                pred[i][j]=k;
                break;
            }
        }
    }
    if (!dp[m][n]) {
        cout<<"No solution";
        return 0;
    }
    vector<string> q;
    while (m) {
        string ss="";
        for (int j=m-pred[m][n]+1;j<=m;++j)
            ss+=s[j-1];
        q.push_back(ss);
        m-=pred[m][n];
        --n;
    }
    for (int i=q.size()-1;i>=0;--i)
        cout<<q[i]<<'\n';
}