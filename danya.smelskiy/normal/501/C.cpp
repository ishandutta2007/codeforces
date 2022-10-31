#include <bits/stdc++.h>
using namespace std;
int n,x,y;
int d[100005];
int s[100005];
set<pair<int,int> > ss;
vector<pair<int,int> > ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>x>>y;
        d[i]=x;
        s[i]=y;
        ss.insert(make_pair(x,i));
    }
    while (!ss.empty()) {
        int x=ss.begin()->second;
        ss.erase(make_pair(d[x],x));
        if (d[x]==0) continue;
        int y=s[x];
        s[y]^=x;
        ss.erase(make_pair(d[y],y));
        --d[y];
        if (d[y]>0)
        ss.insert(make_pair(d[y],y));
        ans.push_back(make_pair(x,y));
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}