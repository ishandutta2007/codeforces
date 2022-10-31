#include <bits/stdc++.h>
using namespace std;


int n;
string s;
bool used[50][(1<<21)+5];
short dp[50][(1<<21)+5];
short a[50][50];
int msk[50][50];
string ss[50];
short solve(int x,int y){
    if (x==n+n-2) return a[n-1][n-1];
    if (used[x][y]) return dp[x][y];
    used[x][y]=true;
    int q=0;
    for (int i=0;i<n;++i)
        if (y&(1<<i)) {
            q=a[i][x-i];
            break;
        }
    int yy=y;
    y=(y|(y<<1));
    int res=((x&1) ? -100 : 100);
    for (int i=0;i<26;++i) {
        int mm=msk[x+1][i];
        mm=(mm&y);
        if (!mm) continue;
        if (x&1) res=max(res,solve(x+1,mm)+q);
        else res=min(res,solve(x+1,mm)+q);
    }
    dp[x][yy]=res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>s;
        ss[i]=s;
        for (int j=0;j<n;++j) {
            if (s[j]=='a') a[i][j]=1;
            else if (s[j]=='b') a[i][j]=-1;
            else a[i][j]=0;
        }
    }
    for (int i=0;i<=n+n-2;++i) {
        for (int j=0;j<n;++j) {
            int y=i-j;
            if (y<0 || y>=n) continue;
            msk[i][ss[j][y]-'a']|=(1<<j);
        }
    }
    int ans=solve(0,1);
    if (ans>0) cout<<"FIRST";
    else if (ans==0) cout<<"DRAW";
    else cout<<"SECOND";
}