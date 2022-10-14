#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=5e5+1;
int val[MAXN];
pii edge[MAXN];
vector<pair<pii,pair<pair<pii,pii>,int>>> ops;
pii dsu[MAXN];
set<pii> largest[MAXN];
map<int,pii> children[MAXN];
int find(int a){
    if(dsu[a].first==a)return a;
    return find(dsu[a].first);
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    ops.push_back({{ap,bp},{{dsu[ap],dsu[bp]},-1}});
    if(ap==bp)return;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    children[ap][bp]=*largest[bp].rbegin();
    largest[ap].insert(*largest[bp].rbegin());
    ops.back().second.second=ap;
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
}
void update(int a){
    int cur=a;
    pii newlargest={0,a};
    int from=-1;
    while(1) {
        pii oldlargest=*largest[cur].rbegin();
        largest[cur].erase({val[a], a});
        largest[cur].insert(newlargest);
        if(from!=-1)children[cur][from]=newlargest;
        newlargest=*largest[cur].rbegin();
        if(newlargest==oldlargest||dsu[cur].first==cur)break;
        from=cur;
        cur=dsu[cur].first;
    }
    val[a]=0;
}
void undo(){
    dsu[ops.back().first.first]=ops.back().second.first.first;
    dsu[ops.back().first.second]=ops.back().second.first.second;
    int ap=ops.back().first.first,bp=ops.back().first.second;
    if(ops.back().second.second==-1){
        ops.pop_back();
        return;
    }
    if(bp==ops.back().second.second)swap(ap,bp);
    largest[ap].erase(children[ap][bp]);
    children[ap].erase(bp);
    ops.pop_back();
}
pii query[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>val[i],dsu[i]={i,1},largest[i].insert({val[i],i});
    vector<pii> edgeorder;
    for(int i=0;i<m;i++){
        edgeorder.push_back({q,i});
        cin>>edge[i].first>>edge[i].second;
    }
    for(int i=0;i<q;i++){
        cin>>query[i].first>>query[i].second;
        if(query[i].first==2)edgeorder[query[i].second-1].first=i;
    }
    sort(edgeorder.begin(),edgeorder.end(),greater<>());
    for(auto x:edgeorder){
        uni(edge[x.second].first,edge[x.second].second);
    }
    for(int i=0;i<q;i++){
        if(query[i].first==1){
            int p=find(query[i].second);
            printf("%d\n",largest[p].rbegin()->first);
            update(largest[p].rbegin()->second);
        }
        else undo();
    }
    return 0;
}