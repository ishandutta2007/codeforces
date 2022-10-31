#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int> > q;
int color[100005];
bool t[100005];
int a[100005];
int en,kol;
void dfs(int x,int y){
    color[x]=y;
    int to=a[x];
    if (color[to]==0) dfs(to,y);
    else {
        en=to;
        return;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        t[a[i]]=true;
    }
    for (int i=1;i<=n;++i) if (t[i]==false) {
        dfs(i,++kol);
        q.push_back(make_pair(i,en));
    }
    for (int i=1;i<=n;++i)
    if (color[i]==0) {
        dfs(i,++kol);
        q.push_back(make_pair(i,i));
    }
    if (q.size()==1 && q[0].first==q[0].second) cout<<"0";
    else {
        cout<<q.size()<<'\n';
        for (int i=0;i<q.size();++i) {
            int to=(i+1)%(q.size());
            cout<<q[i].second<<" "<<q[to].first<<'\n';
        }
    }
}