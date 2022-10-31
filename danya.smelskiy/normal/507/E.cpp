#include <bits/stdc++.h>
using namespace std;


set<pair<int,int> > s;
int n,m,x,y,z;
vector<pair<pair<int,int>,int> > ans,q;
vector<pair<int,int> > v[100005];
int d[100005];
int ans2[100005];
int pred[100005];
map<pair<int,int>,bool> used2;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
        q.push_back(make_pair(make_pair(x,y),z));
    }
    for (int i=1;i<=n;++i) d[i]=1e9;
    d[1]=0;
    s.insert(make_pair(0,1));
    while (!s.empty()) {
        int x=s.begin()->second;
        s.erase(s.begin());
        for (int i=0;i<v[x].size();++i) {
            int to=v[x][i].first;
            int len=d[x]+1;
            int len2=ans2[x]+v[x][i].second;
            if (d[to]>len || (d[to]==len && ans2[to]<len2)) {
                s.erase(make_pair(d[to],to));
                d[to]=len;
                ans2[to]=len2;
                s.insert(make_pair(d[to],to));
                pred[to]=x;
            }
        }
    }
    int z=n;
    while (z) {
        if (z==1) break;
        used2[make_pair(pred[z],z)]=used2[make_pair(z,pred[z])]=true;
        z=pred[z];
    }
    for (int i=0;i<q.size();++i) {
        int x=q[i].first.first,y=q[i].first.second;
        int z=q[i].second;
        if ((used2[make_pair(x,y)]==false && z==1) || (used2[make_pair(x,y)]==true && z==0)) {
            ans.push_back(make_pair(make_pair(x,y),1-z));
        }
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<'\n';
}