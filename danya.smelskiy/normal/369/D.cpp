#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[3005];
bool dp[3005][3005];
bool s[3005],r[3005];
int ans;
int d[3005][3005];
int rr;
pair<int,int> q[9000000];
inline void add(int x,int y,int xx,int yy){
    if (dp[x][y]) return;
    dp[x][y]=true;
    d[x][y]=d[xx][yy]+1;
    ++rr;
    q[rr]=make_pair(x,y);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    dp[1][2]=true;
    for (int i=n;i>0;--i){
        s[i]=s[i+1];
        if (a[i]==100) s[i]=true;
        r[i]=r[i+1];
        if (a[i]) r[i]=true;
    }
    rr=1;
    q[1]=make_pair(1,2);
    dp[1][2]=true;
    for (int i=1;i<=rr;++i) {
        ++ans;
        int x=q[i].first,y=q[i].second;
        if (x>n || y>n) continue;
        if (d[x][y]==k) continue;
        if (a[x] && r[y]) add(y+1,y+2,x,y);
        if (a[x] && !s[y]) add(x,y+1,x,y);
        if (a[x]!=100 && r[y]) add(y,y+1,x,y);
    }
    cout<<ans;
}