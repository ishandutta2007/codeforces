#include <bits/stdc++.h>
using namespace std;
const long long  inf=1e15;
int n,m,x,y,z;
long long d[100005];
vector<pair<long long,int> > v[100005];
int pred[100005];
vector<int> ans;

void dej(){
    set<pair<long long,int> > s;
    for (int i=2;i<=n;++i){
        s.insert(make_pair(inf,i));
        d[i]=inf;
    }
    s.insert(make_pair(0,1));
    while (!s.empty()){
            int x=s.begin()->second;
            s.erase(s.begin());
            if (d[x]==inf) break;
            for (int j=0;j<v[x].size();++j){
                int to=v[x][j].first;
                if (d[to]>d[x]+v[x][j].second){
                    s.erase(make_pair(d[to],to));
                    d[to]=d[x]+v[x][j].second;
                    pred[to]=x;
                    s.insert(make_pair(d[to],to));
                }
            }
    }
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    dej();
    if (d[n]==inf) cout<<"-1";
    else {
        while (n!=0){
            ans.push_back(n);
            n=pred[n];
        }
        for (int i=ans.size()-1;i>=0;--i)
            cout<<ans[i]<<" ";
    }
}