#include <bits/stdc++.h>
using namespace std;


int dp[405][405];
int dp4[405][405];
pair<int,int> q[405][405],qq[405][405];
int dp2[1000][1000];
int dp3[1000][1000];
int n,m;
string s[405],s1[405];
int ans;

void build(int n,int m){
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j)
            dp[i][j]=dp[i-1][j]+(s[i][j-1]-'0');
    }
    int last=0;
    for (int i=1;i<=n;++i) {
        ++last;
        int kol=0;
        int x=i;
        int y=1;
        while (x>=1 && y<=m) {
            ++kol;
            dp2[last][kol]=dp2[last][kol-1];
            if (s[x][y-1]=='1') ++dp2[last][kol];
            q[x][y]=make_pair(last,kol);
            --x; ++y;
        }
    }
    for (int i=2;i<=m;++i) {
        ++last;
        int kol=0;
        int x=n;
        int y=i;
        while (x>=1 && y<=m) {
            ++kol;
            dp2[last][kol]=dp2[last][kol-1];
            if (s[x][y-1]=='1') ++dp2[last][kol];
            q[x][y]=make_pair(last,kol);
            --x; ++y;
        }
    }
    last=0;
    for (int i=n;i>0;--i) {
        ++last;
        int kol=0;
        int x=i;
        int y=1;
        while (x<=n && y<=m) {
            ++kol;
            dp3[last][kol]=dp3[last][kol-1];
            if (s[x][y-1]=='1') ++dp3[last][kol];
            qq[x][y]=make_pair(last,kol);
            ++x; ++y;
        }
    }
    for (int i=2;i<=m;++i) {
        ++last;
        int kol=0;
        int x=1;
        int y=i;
        while (x<=n && y<=m) {
            ++kol;
            dp3[last][kol]=dp3[last][kol-1];
            if (s[x][y-1]=='1') ++dp3[last][kol];
            qq[x][y]=make_pair(last,kol);
            ++x; ++y;
        }
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            dp4[i][j]=dp4[i][j-1]+s[i][j-1]-'0';
}
void solve(int n,int m){
    build(n,m);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) if (s[i][j-1]!='1') {
            for (int k=1;;++k) {
                if (i-k<1) break;
                if (j-k<1) break;
                int z=q[i-k][j].first;
                int zz=q[i-k][j].second;
                int zz2=q[i][j-k].second;
                if (s[i-k][j-1]=='1' || s[i][j-k-1]=='1') break;
                if (dp2[z][zz]-dp2[z][zz2-1]) {} else
                 { ++ans;}
            }
            for (int k=1;;++k) {
                if (i-k<1 || i+k>n || j+k>m) break;
                if (s[i-k][j+k-1]=='1' || s[i+k][j+k-1]=='1') break;
                if (dp[i+k][j+k]-dp[i-k-1][j+k]) {} else
                { ++ans; }
            }
            for (int k=1;;++k) {
                if (i+k>n || j+k>m || j-k<1) break;
                if (s[i+k][j-k-1]=='1' || s[i+k][j+k-1]=='1') break;
                if (dp4[i+k][j+k]-dp4[i+k][j-k-1]) {} else
                 {++ans;}
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
    }
    solve(n,m);
    for (int i=1;i<=n;++i)
        reverse(s[i].begin(),s[i].end());
    for (int i=0;i<m;++i) {
        string ss="";
        for (int j=n;j>0;--j) {
            ss+=s[j][i];
        }
        s1[i+1]=ss;
    }
    for (int i=1;i<=m;++i)
        s[i]=s1[i];
    swap(n,m);
    solve(n,m);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) if (s[i][j-1]=='0') {
            for (int k=1;;++k) {
                    if (i+k>n) break;
                    if (j-k<1) break;
                    int z=qq[i+k][j].first;
                    int zz=qq[i+k][j].second;
                    int zz2=qq[i][j-k].second;
                    if (s[i+k][j-1]=='1' || s[i][j-k-1]=='1') break;
                    if (dp3[z][zz]-dp3[z][zz2-1]) {} else
                    { ++ans;}
                }
            for (int k=1;;++k) {
                    if (i-k<1) break;
                    if (j+k>m) break;
                    int z=qq[i-k][j].first;
                    int zz=qq[i-k][j].second;
                    int zz2=qq[i][j+k].second;
                    if (s[i-k][j-1]=='1' || s[i][j+k-1]=='1') break;
                    if (dp3[z][zz]-dp3[z][zz2-1]) {} else
                    { ++ans;}
                }
            }
    }
    cout<<ans;
}