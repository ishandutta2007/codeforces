#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> ans;
int m;
bool dp[1005][21][11];
pair<int,int> pred[1005][21][11];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    cin>>m;
    dp[0][10][0]=true;
    for (int i=0;i<m;++i) {
        if (i%2==0) {
            for (int j=1;j<=10;++j)
                for (int k=0;k<=10;++k)
            if (dp[i][j][k]) {
                for (int z=1;z<=10;++z)
                if (s[z-1]=='1' && z!=k && j+z>10) {
                    dp[i+1][j+z][z]=true;
                    pred[i+1][j+z][z]=make_pair(j,k);
                }
            }
        } else {
            for (int j=10;j<=20;++j)
                for (int k=0;k<=10;++k)
                    if (dp[i][j][k])
                    for (int z=1;z<=10;++z)
            if (s[z-1]=='1' && z!=k && j-z<10) {
                dp[i+1][j-z][z]=true;
                pred[i+1][j-z][z]=make_pair(j,k);
            }
        }
    }
    int x=-1,y=-1;
    for (int i=1;i<=20;++i)
        for (int j=1;j<=10;++j)
    if (dp[m][i][j]) {
        x=i;
        y=j;
        break;
    }
    if (x==-1) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<'\n';
    for (int i=m;i>0;--i) {
        int xx=pred[i][x][y].first;
        int yy=pred[i][x][y].second;
        ans.push_back(abs(xx-x));
        x=xx;
        y=yy;
    }
    for (int i=m-1;i>=0;--i)
        cout<<ans[i]<<" ";
}