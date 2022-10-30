#include <bits/stdc++.h>
using namespace std;


int n;
int all;
vector<pair<int,int> > v;
bool dp[1005][1005];


main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    all=2;
    v.push_back(make_pair(1,1));
    for (int i=1;i<=31;++i) {
        vector<pair<int,int> > vv;
        int s=0;
        for (int j=0;j<v.size();++j) {
            int x=v[j].first;
            int y=v[j].second;
            ++all;
            dp[y][all]=true;
            dp[all][y]=true;
            vv.push_back(make_pair(x,all));
            s+=x;
        }
        ++all;
        vv.push_back(make_pair(s,all));
        for (int j=0;j<v.size();++j) {
            int y=v[j].second;
            dp[y][all]=dp[all][y]=true;
        }
        v=vv;
    }
    cout<<all<<'\n';
    while (n) {
        for (int i=v.size()-1;i>=0;--i)
        if (v[i].first<=n) {
            int y=v[i].second;
            n-=v[i].first;
            dp[y][2]=dp[2][y]=true;
        }
    }
    for (int i=1;i<=all;++i) {
        for (int j=1;j<=all;++j) {
            if (dp[i][j]) cout<<"Y";
            else cout<<"N";
        }
        cout<<'\n';
    }
}