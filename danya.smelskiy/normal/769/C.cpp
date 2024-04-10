#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;

string s,ans;
pair<int,int> q[1000005];
int d[1005][1005];
int n,m,k;
int q1,q2;
int x,y;
int a[1005][1005];
inline bool chek(int x,int y){
    return (x>=1 && x<=n && y>=1 && y<=m && a[x][y]==0);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    if (k&1) {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for (int i=1;i<=n;++i){
        cin>>s;
        for (int j=1;j<=m;++j){
            d[i][j]=inf;
            if (s[j-1]=='*') a[i][j]=1;
            if (s[j-1]=='X') {
                x=i;
                y=j;
            }
        }
    }
    q1=x; q2=y;
    d[x][y]=0;
    int l=1,r=1;
    q[1]=make_pair(q1,q2);
    while (l<=r){
        x=q[l].first; y=q[l].second;
        if (chek(x+1,y) && d[x+1][y]>d[x][y]+1) {
            ++r;
            q[r]=make_pair(x+1,y);
            d[x+1][y]=d[x][y]+1;
        }
        if (chek(x,y-1) && d[x][y-1]>d[x][y]+1) {
            ++r;
            q[r]=make_pair(x,y-1);
            d[x][y-1]=d[x][y]+1;
        }
        if (chek(x,y+1) && d[x][y+1]>d[x][y]+1) {
            ++r;
            q[r]=make_pair(x,y+1);
            d[x][y+1]=d[x][y]+1;
        }
        if (chek(x-1,y) && d[x-1][y]>d[x][y]+1) {
            ++r;
            q[r]=make_pair(x-1,y);
            d[x-1][y]=d[x][y]+1;
        }
        ++l;
    }
    x=q1;
    y=q2;
    for (int i=k-1;i>=0;--i) {
        if (chek(x+1,y) && d[x+1][y]<=i) {
            ans+="D";
            ++x;
        } else if (chek(x,y-1) && d[x][y-1]<=i) {
            ans+="L";
            --y;
        } else if (chek(x,y+1) && d[x][y+1]<=i){
            ans+="R";
            ++y;
        } else if (chek(x-1,y) && d[x-1][y]<=i) {
            ans+="U";
            --x;
        } else {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    cout<<ans;
}