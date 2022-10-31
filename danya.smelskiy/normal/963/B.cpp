#include <bits/stdc++.h>
using namespace std;



int n,x;
vector<int> v[200005];
bool dp[200005][2];

void dfs(int x,int y) {
    bool nxt=false;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        nxt=true;
    }
    if (nxt==false) {
        dp[x][0]=true;
        dp[x][1]=false;
        return;
    }
    int c1=0,c2=0;
    int c3=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        if (dp[to][0]) ++c1; else ++c2;
        if (dp[to][0] && dp[to][1]) ++c3;
    }
    int step=v[x].size();
    step-=c2;
    if (!(step&1) || (c3>0)) dp[x][1]=true;
    if (y==-1) return;
    step=v[x].size();
    step--;
    step-=c2;
    if (!(step&1) || (c3>0)) dp[x][0]=true;
}

void solve(int x,int y,int z) {
    int c1=0,c2=0,c3=0;
    vector<int> q1,q2;
    int zz=-1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==z) continue;
        if (dp[to][0]) {
            ++c1;
            q1.push_back(to);
        } else {
            ++c2;
            q2.push_back(to);
        }
        if (dp[to][0] && dp[to][1]) {
            ++c3;
            zz=to;
        }
    }
    int step=v[x].size();
    if (y==1) {
        step-=c2;
        if (step&1) {
            q2.push_back(zz);
        } else zz=-1;
        for (int i=0;i<q2.size();++i) {
            int to=q2[i];
            solve(to,1,x);
        }
        cout<<x<<'\n';
        for (int i=0;i<q1.size();++i) {
            int to=q1[i];
            solve(to,0,x);
        }
        return;
    }

        step-=c2;
        step--;
        if (step&1) {
            q2.push_back(zz);
        } else zz=-1;
        for (int i=0;i<q2.size();++i) {
            int to=q2[i];
            solve(to,1,x);
        }
        cout<<x<<'\n';
        for (int i=0;i<q1.size();++i) {
            int to=q1[i];
            solve(to,0,x);
        }
        return;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x;
        if (x) {
            v[x].push_back(i);
            v[i].push_back(x);
        }
    }
    if (n==1) {
        cout<<"YES"<<'\n';
        cout<<"1";
        return 0;
    }
    dfs(1,-1);
    for (int i=1;i<=n;++i)
    if (!dp[i][0] && !dp[i][1]) {
        cout<<"NO";
        return 0;
    }
    if (dp[1][0]==false && dp[1][1]==false) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<'\n';
    if (dp[1][0]) solve(1,0,-1);
    else solve(1,1,-1);
}