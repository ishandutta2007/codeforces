#include <bits/stdc++.h>
using namespace std;
long long n,m;

long long p,q;
long long used[255][255];
long long dp[255][255];
long long last;
long long r;
long long kol[255][255];
string s[255];
pair<long long,long long> qq[200005];
inline void check(long long x,long long y,long long z){
    if (!z) return;
    if (x<1 || x>n || y<1 || y>m) return;
    if (s[x][y]=='*') return;
    if (used[x][y]==last) return;
    ++r;
    qq[r]=make_pair(x,y);
    used[x][y]=last;
    kol[x][y]=z/2;
}
inline void build(long long x,long long y){
    ++last;
    r=1;
    qq[1]=make_pair(x,y);
    kol[x][y]=(s[x][y]-'A'+1)*q;
    used[x][y]=last;
    for (long long i=1;i<=r;++i) {
        long long xx=qq[i].first;
        long long yy=qq[i].second;
        dp[xx][yy]+=kol[xx][yy];
        check(xx,yy-1,kol[xx][yy]);
        check(xx,yy+1,kol[xx][yy]);
        check(xx-1,yy,kol[xx][yy]);
        check(xx+1,yy,kol[xx][yy]);
    }
}
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q>>p;
    for (long long i=1;i<=n;++i) {
        cin>>s[i];
        s[i]="."+s[i];
    }
    for (long long i=1;i<=n;++i) {
        for (long long j=1;j<=m;++j) if (s[i][j]>='A' && s[i][j]<='Z') {
            build(i,j);
        }
    }
    long long ans=0;
    for (long long i=1;i<=n;++i)
        for (long long j=1;j<=m;++j)
            if (dp[i][j]>p) ++ans;
    cout<<ans;
}