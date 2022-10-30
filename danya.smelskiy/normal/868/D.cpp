#include <bits/stdc++.h>
using namespace std;

int n,m;
string s[1005];
string pref[1005],suff[1005];
bool dp[250][(1<<16)+5];

inline void add(int x,string s){
    for (int i=1;i<=min((int)s.size(),16);++i) {
        for (int j=1;j<=s.size()-i+1;++j) {
            int nw=0;
            for (int k=j;k<j+i;++k)
                nw=(nw*2+(s[k-1]-'0'));
            nw|=(1<<i);
            dp[x][nw]=true;
        }
    }
}
inline int ask(int x){
    int ans=0;
    for (int i=1;i<=15;++i) {
        bool t=false;
        for (int j=0;j<(1<<i);++j)
            if (!dp[x][(1<<i)+j]) {
                t=true;
                break;
            }
        if (!t) ans=i;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        add(i,s[i]);
        for (int j=1;j<=min((int)s[i].size(),16);++j){
            pref[i]+=s[i][j-1];
            suff[i]+=s[i][(int)s[i].size()-j];
        }
        reverse(suff[i].begin(),suff[i].end());
    }
    cin>>m;
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        for (int j=0;j<(1<<15);++j)
            dp[n+i][j]=(dp[x][j]|dp[y][j]);
        string sk=suff[x]+pref[y];
        add(n+i,sk);
        pref[n+i]=pref[x];
        suff[n+i]=suff[y];
        for (int j=1;j<=pref[y].size() && pref[n+i].size()<15;++j)
            pref[n+i]=pref[n+i]+pref[y][j-1];
        for (int j=1;j<=suff[x].size() && suff[n+i].size()<15;++j)
            suff[n+i]=suff[x][(suff[x].size()-j)]+suff[n+i];
        cout<<ask(n+i)<<'\n';
    }
}