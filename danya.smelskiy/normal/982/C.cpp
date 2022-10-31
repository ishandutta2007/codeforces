#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> v[100005];
pair<bool,int> dp[100005][2];
vector<pair<int,int> > vv;


inline bool cmp1(pair<int,int> x,pair<int,int> y) {
    return x.second-x.first>y.second-y.first;
}
inline bool cmp2(pair<int,int> x,pair<int,int> y) {
    return x.first-x.second>y.first-y.second;
}


void dfs(int x,int y) {
    bool t=false;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to!=y) dfs(to,x),t=true;
    }
    if (!t) {
        dp[x][1]=make_pair(true,0);
        return;
    }
    vv.clear();
    int c=1;
    int cost=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        if (!dp[to][0].first && !dp[to][1].first) {
            cout<<"-1";
            exit(0);
        }
        if (!dp[to][0].first) {
            c^=1;
            cost+=dp[to][1].second;
        } else if (!dp[to][1].first) {
            cost+=dp[to][0].second+1;
        } else {
            vv.push_back(make_pair(dp[to][0].second,dp[to][1].second));
        }
    }
    sort(vv.begin(),vv.end(),cmp1);
    int cc=c;
    int cost2=cost;
    for (int i=0;i<vv.size();++i) {
        cost2+=vv[i].first;
        ++cost2;
    }
    if (cc==1) {
        dp[x][1]=make_pair(true,cost2);
    }
    for (int i=0;i<vv.size();++i) {
        cc^=1;
        --cost2;
        cost2+=vv[i].second-vv[i].first;
        if (cc==1) {
            if (!dp[x][1].first || dp[x][1].second<cost2) {
                dp[x][1]=make_pair(true,cost2);
            }
        }
    }
    cc=c;
    cost2=cost;
    for (int i=0;i<vv.size();++i) {
        cost2+=vv[i].first;
        ++cost2;
    }
    if (cc==0) {
        dp[x][0]=make_pair(true,cost2);
    }
    for (int i=0;i<vv.size();++i) {
        cc^=1;
        --cost2;
        cost2+=vv[i].second-vv[i].first;
        if (cc==0) {
            if (!dp[x][0].first || dp[x][0].second<cost2){
                dp[x][0]=make_pair(true,cost2);
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int x,y;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    if (dp[1][0].first) {
        cout<<dp[1][0].second;
    } else cout<<"-1";
}