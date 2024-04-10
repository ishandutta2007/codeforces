#include <bits/stdc++.h>
using namespace std;


bool dp[30][50];
pair<pair<int,int>,pair<int,int> > pred[30][50];
inline void solve(string s){
    for (int i=0;i<=25;++i) {
        for (int j=0;j<40;++j)
            dp[i][j]=false;
    }
    int n=s.size();
    dp[n][0]=true;
    for (int i=n;i>0;--i) {
        for (int j=0;j<40;++j) if (dp[i][j]) {
            for (int k=0;k<=6;++k)
            for (int z=0;z<=6-k;++z) {
                int nxt=(j+k*4+z*7);
                if (nxt/10>=40) {
                    cout<<".."<<'\n';
                    return;
                }
                if (s[i-1]-'0'==nxt%10 && dp[i-1][nxt/10]==false) {
                    dp[i-1][nxt/10]=true;
                    pred[i-1][nxt/10]=make_pair(make_pair(i,j),make_pair(k,z));
                }
            }
        }
    }
    if (dp[0][0]==false) {
        cout<<"-1"<<'\n';
        return;
    }
    string ss[6];
    for (int i=0;i<6;++i)
        ss[i]="";
    int x,y;
    y=0;
    for (int i=0;i<n;++i){
        int xx=pred[i][y].second.first;
        int yy=pred[i][y].second.second;
        for (int j=0;j<xx;++j)
            ss[j]+="4";
        for (int j=xx;j<xx+yy;++j)
            ss[j]+="7";
        for (int j=xx+yy;j<6;++j)
            if (ss[j].size()) ss[j]+="0";
        y=pred[i][y].first.second;
    }
    for (int i=0;i<6;++i) {
        if (ss[i].size()==0) ss[i]="0";
        cout<<ss[i]<<" ";
    }
    cout<<'\n';
    return;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n;
    cin>>n;
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        solve(s);
    }
}