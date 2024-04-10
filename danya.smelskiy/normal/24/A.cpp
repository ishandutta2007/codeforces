#include <bits/stdc++.h>
using namespace std;


int n;
bool used[105];
vector<pair<int,int> > q,v[105];
int cost[105];
int f[105];
long long s1,s2;


void dfs(int x,int y) {
    used[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        if (used[to]) {
            if (to==1 && to!=y) {
                q.push_back(make_pair(x,v[x][i].second));
            }
        } else {
            q.push_back(make_pair(x,v[x][i].second));
            dfs(to,x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int
         i=1;i<=n;++i) {
        int x,y,z;
        cin>>x>>y>>z;
        cost[i]=z;
        f[i]=x;
        v[x].push_back(make_pair(y,i));
        v[y].push_back(make_pair(x,i));
    }
    dfs(1,-1);
    long long s1=0,s2=0;
    for (int i=0;i<q.size();++i) {
        int x=q[i].first;
        int y=q[i].second;
        if (f[y]==x) s1+=cost[y];
        else s2+=cost[y];
    }
    cout<<min(s1,s2);
}