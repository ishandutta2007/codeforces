#include <bits/stdc++.h>
using namespace std;



string op[1000005];
vector<int> v[1000005];
bool used[1000005];
bool dp1[1000005][2];
int dp2[1000005];
int bt[1000005];
int ans[1000005];
int n;
string s;
int x,y;

inline int f(string s,int x,int y) {
    if (s=="XOR") x^=y;
    else if (s=="AND") x&=y;
    else x|=y;
    return x;
}

void dfs1(int x) {
    if (used[x]) return;
    if (op[x]=="NOT") {
        int to=v[x][0];
        dfs1(to);
        dp2[x]=(1-dp2[to]);
        for (int i=0;i<2;++i) if (dp1[to][i]) {
            dp1[x][1-i]=true;
        }
        return;
    }
    dfs1(v[x][0]);
    dfs1(v[x][1]);
    int xx=v[x][0];
    int yy=v[x][1];
    dp2[x]=f(op[x],dp2[xx],dp2[yy]);
    for (int i=0;i<2;++i) {
        if (dp1[xx][i]) {
            int zz=f(op[x],i,dp2[yy]);
            dp1[x][zz]=true;
        }
        if (dp1[yy][i]) {
            int zz=f(op[x],i,dp2[xx]);
            dp1[x][zz]=true;
        }
    }
}

void dfs2(int x,int y,int z) {
    if (used[x]) {
        if (bt[x]==y) return;
        ans[x]=z;
        return;
    }
    if (!dp1[x][y]) return;
    if (op[x]=="NOT") {
        int to=v[x][0];
        dfs2(to,1-y,z);
        return;
    }
    int xx=v[x][0];
    int yy=v[x][1];
    for (int i=0;i<2;++i) {
        int zz=dp2[yy];
        zz=f(op[x],i,zz);
        if (zz==y) dfs2(xx,i,z);
        zz=dp2[xx];
        zz=f(op[x],i,zz);
        if (zz==y) dfs2(yy,i,z);
    }
}

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>s;
        if (s=="IN") {
            used[i]=true;
            cin>>bt[i];
            x=bt[i];
            dp2[i]=x;
            x^=1;
            dp1[i][x]=true;
        } else {
            op[i]=s;
            if (s=="NOT") {
                cin>>x;
                v[i].push_back(x);
            } else {
                cin>>x>>y;
                v[i].push_back(x);
                v[i].push_back(y);
            }
        }
    }
    dfs1(1);
    dfs2(1,0,0);
    dfs2(1,1,1);
    for (int i=1;i<=n;++i)
        if (used[i]) cout<<ans[i];
}