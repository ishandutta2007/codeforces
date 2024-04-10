#include <bits/stdc++.h>
using namespace std;
const long long inf=1e17;
int n,m,k,x,y,z;
struct st{
    int l,y,id;
};
long long d[100001];
vector<st> v[100001];
bool used[100001];
st t;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    t.id=1;
    for (int i=1;i<=m;++i){
        cin>>x>>y>>z;
        t.y=y;
        t.l=z;
        v[x].push_back(t);
        t.y=x;
        v[y].push_back(t);
    }
    t.id=2;
    for (int i=1;i<=k;++i){
        cin>>x>>y;
        t.y=x;
        t.l=y;
        v[1].push_back(t);
    }
    set<pair<int,int> > s;
    s.insert(make_pair(0,1));
    for (int i=1;i<=n;++i)
        d[i]=inf;
    d[1]=0;
    for (int i=1;i<=n;++i)
        used[i]=false;
    while (!s.empty()){
        x=s.begin()->second;
        s.erase(s.begin());
        for (int i=0;i<v[x].size();++i){
            int to=v[x][i].y;
            int len=v[x][i].l;
            int id=v[x][i].id;
            if (d[x]+len<d[to] || (d[x]+len==d[to] && id==1)){
                s.erase(make_pair(d[to],to));
                d[to]=d[x]+len;
                used[to]=false;
                if (id==2) used[to]=true;
                s.insert(make_pair(d[to],to));
            }
        }
    }
    for (int i=1;i<=n;++i)
        if (used[i]) --k;
    cout<<k;
}