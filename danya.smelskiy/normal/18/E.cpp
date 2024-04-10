#include <bits/stdc++.h>
using namespace std;

int n,m;
string s[505];
int dp[2][30][30];
int kol[30][2];
pair<short,short> pred[505][26][26];

inline void up(int x){
    for (int i=0;i<26;++i)
        for (int j=0;j<26;++j)
            dp[x][i][j]=1e9;
}
inline int MIN(int x,int y){
    return (x<y ? x : y);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
    }
    int x=0,y=1;
    for (int i=1;i<=n;++i) {
        swap(x,y);
        up(x);
        for (int j=0;j<26;++j)
            kol[j][0]=kol[j][1]=0;
        for (int j=0;j<m;++j) {
            int xx=s[i][j]-'a';
            ++kol[xx][(j&1)];
        }
        for (int j=0;j<26;++j)
            for (int k=0;k<26;++k) if (j!=k)
                for (int z=0;z<26;++z) if (z!=j)
                    for (int zz=0;zz<26;++zz) if (zz!=z && zz!=k){
                        int nw=dp[y][j][k]+m-kol[z][0]-kol[zz][1];
                        if (nw<dp[x][z][zz]) {
                            dp[x][z][zz]=nw;
                            pred[i][z][zz]=make_pair(j,k);
                        }
                    }
    }
    int ans=1e9;
    int x2,y2;
    for (int i=0;i<26;++i)
        for (int j=0;j<26;++j){
            if (dp[x][i][j]<ans) {
                ans=dp[x][i][j];
                x2=i;
                y2=j;
            }
        }
    cout<<ans<<'\n';
    vector<pair<short,short> > q;
    for (int i=n;i>0;--i) {
        q.push_back(make_pair(x2,y2));
        short x3=pred[i][x2][y2].first;
        short y3=pred[i][x2][y2].second;
        x2=x3;
        y2=y3;
    }
    for (int i=q.size()-1;i>=0;--i) {
        x2=q[i].first;
        y2=q[i].second;
        for (int j=0;j<m;++j)
            if (j&1) cout<<char(y2+'a'); else cout<<char(x2+'a');
        cout<<'\n';
    }
}