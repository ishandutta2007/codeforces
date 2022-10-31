#include <bits/stdc++.h>
using namespace std;


int n;
string s;
int nxt[100005][26];
vector<int> v[100005];
int dp[100005];

inline vector<int> mrg(vector<int> x,vector<int> y) {
    if (x.size()==0) return y;
    int l=0;
    int r=0;
    vector<int> res;
    while (l<x.size() || r<y.size()) {
        if (l==x.size() || (r<y.size() && y[r]<x[l])) res.push_back(y[r++]);
        else res.push_back(x[l++]);
    }
    return res;
}

void solve(int x,int dist) {
    bool z=false;
    if (v[x].size()>0) z=true;
    for (int i=0;i<26;++i) if (nxt[x][i]) {
        solve(nxt[x][i],dist+1);
        dp[x]+=dp[nxt[x][i]];
        if (v[nxt[x][i]].size()>0) v[x]=mrg(v[x],v[nxt[x][i]]);
        v[nxt[x][i]].clear();
    }
    if (v[x].size()>0 && dist>0 && !z) {
        int y=v[x].back();
        dp[x]-=y-dist;
        y=dist;
        v[x].pop_back();
        vector<int> z;
        z.push_back(y);
        for (int i=0;i<v[x].size();++i)
            z.push_back(v[x][i]);
        v[x]=z;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int all=0;
    for (int i=1;i<=n;++i) {
        cin>>s;
        int last=0;
        for (int j=0;j<s.size();++j) {
            int to=s[j]-'a';
            if (!nxt[last][to]) nxt[last][to]=++all;
            last=nxt[last][to];
        }
        dp[last]+=s.size();
        v[last].push_back(s.size());
    }
    solve(0,0);
    cout<<dp[0];


}