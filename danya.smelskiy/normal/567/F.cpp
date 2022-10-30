#include <bits/stdc++.h>
using namespace std;


int n,k;
vector<pair<string,int> > v[100];
long long dp[100][100];
long long ans;
inline bool f(int x,int y,int l,int r){
    for (int i=0;i<v[x].size();++i) {
        int yy=v[x][i].second;
        string c=v[x][i].first;
        if (c=="=") {
            if (yy!=y) return false;
        } else if (c==">") {
            if ((yy>l && yy<r))  return false;
        } else if (c=="<") {
            if ((yy<=l || yy>=r) || yy==y) return false;
        } else if (c==">=") {
            if (yy>l && yy<r && yy!=y) return false;
        } else {
            if (yy<=l || yy>=r) return false;
        }
    }
    for (int i=0;i<v[y].size();++i) {
        int yy=v[y][i].second;
        string c=v[y][i].first;
        if (c=="=") {
            if (yy!=x) return false;
        } else if (c==">") {
            if ((yy>l && yy<r)) return false;
        } else if (c=="<") {
            if ((yy<=l || yy>=r) || yy==x) return false;
        } else if (c==">=") {
            if (yy>l && yy<r && yy!=x) return false;
        } else {
            if (yy<=l || yy>=r) return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    n+=n;
    for (int i=1;i<=k;++i) {
        int x,y;
        string c;
        cin>>x>>c>>y;
        if (c=="=") {
            if (x==y) continue;
            v[x].push_back(make_pair(c,y));
            v[y].push_back(make_pair(c,x));
        } else if (c==">") {
            if (x==y) {
                cout<<"0";
                return 0;
            }
            v[x].push_back(make_pair(c,y));
            v[y].push_back(make_pair("<",x));
        } else if (c=="<") {
            if (x==y) {
                cout<<"0";
                return 0;
            }
            v[x].push_back(make_pair(c,y));
            v[y].push_back(make_pair(">",x));
        } else if (c==">=") {
            if (x==y) continue;
            v[x].push_back(make_pair(c,y));
            v[y].push_back(make_pair("<=",x));
        } else {
            if (x==y) continue;
            v[x].push_back(make_pair(c,y));
            v[y].push_back(make_pair(">=",x));
        }
    }
    dp[1][n]=1;
    for (int len=n;len>=2;len-=2) {
        for (int i=1;i<=n-len+1;++i) {
            int j=i+len-1;
            if (!dp[i][j]) continue;
            if (i==j-1) {
                if (f(i,j,i-1,j+1)) ans+=dp[i][j];
                continue;
            }
            if (f(i,j,i-1,j+1)) dp[i+1][j-1]+=dp[i][j];
            if (f(i,i+1,i-1,j+1)) dp[i+2][j]+=dp[i][j];
            if (f(j-1,j,i-1,j+1)) dp[i][j-2]+=dp[i][j];
        }
    }
    cout<<ans;
}