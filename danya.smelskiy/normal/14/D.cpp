#include <bits/stdc++.h>
using namespace std;

int n,x,y;
vector<pair<int,int> > q;
vector<int> v[100005];
int ans;
int res2;

int dfs(int x,int y){
    int sz1=0,sz2=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        int res=dfs(to,x);
        if (res>sz2) {
            sz2=res;
            if (sz1<sz2) swap(sz1,sz2);
        }
    }
    ans=max(ans,sz1+sz2);
    ans=max(ans,sz1);
    return sz1+1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        q.push_back(make_pair(x,y));
    }
    for (int i=0;i<q.size();++i) {
        if (q[i].first>q[i].second) swap(q[i].first,q[i].second);
        ans=0;
        dfs(q[i].first,q[i].second);
        int res=ans;
        ans=0;
        dfs(q[i].second,q[i].first);
        res2=max(res2,res*ans);
    }
    cout<<res2;
}