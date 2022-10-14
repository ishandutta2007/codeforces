#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAXN=3e5+1;
bool arr[MAXN];
int tot=0;
vector<set<int>> nodes;
pair<pii,pair<vector<int>,pii>> dis[2*MAXN];
pii sorter[2*MAXN];
vector<int> subs[2*MAXN];
vector<int> locs[MAXN];
vector<int> todo[MAXN];
bool inserted[2*MAXN];
int wh[MAXN];
vector<pii> mer[MAXN];
int oth(int val, int cur){
    if(locs[val].size()==1)return -1;
    return (locs[val][0]==cur?locs[val][1]:locs[val][0]);
}
int find(int a){
    if(dis[a].first.first==a)return a;
    return dis[a].first.first=find(dis[a].first.first);
}
void uni(int a, int b, int type){
    int ap=find(a),bp=find(b);
    if(dis[ap].first.second<dis[bp].first.second)swap(a,b),swap(ap,bp);
    dis[bp].first.first=ap;
    dis[ap].first.second+=dis[bp].first.second;
    int whb=wh[b];
    int wha=wh[a];
    for(int x:nodes[dis[bp].second.second.first]){
        if(type){
            wh[x]=(wh[x]==whb?wha:!wha);
            if(dis[ap].second.first[wh[x]]==MAXN+1)dis[ap].second.first[wh[x]]=0;
            dis[ap].second.first[wh[x]]++;
        }
        else{
            wh[x]=(wh[x]==whb?!wha:wha);
            if(dis[ap].second.first[wh[x]]==MAXN+1)dis[ap].second.first[wh[x]]=0;
            dis[ap].second.first[wh[x]]++;
        }
        nodes[dis[ap].second.second.first].insert(x);
    }
    if(dis[bp].second.second.second!=-1){
        dis[ap].second.second.second=(type?(dis[bp].second.second.second==whb?wha:!wha):(dis[bp].second.second.second==whb?!wha:wha));
    }
}
void insert(int a){
    inserted[a]=true;
    for(int x:subs[a]) {
        int te = oth(x, a);
        if (te == -1) {
            todo[x].push_back(a);
        } else {
            mer[x].push_back({a,te});
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    char c;
    for(int i=1;i<=n;i++){
        cin>>c;
        arr[i]=(c=='1');
    }
    for(int i=1;i<=k;i++){
        dis[i].first={i,1};
        dis[i].second={{1,0},{(int)nodes.size(),-1}};
        nodes.push_back({i});
        int a;
        cin>>a;
        subs[i].resize(a);
        while(a--){
            cin>>subs[i][a];
            locs[subs[i][a]].push_back(i);
        }
        sort(subs[i].begin(),subs[i].end());
        sorter[i]={*subs[i].begin(),i};
    }
    sort(sorter+1,sorter+k+1);
    int cur=1;
    for(int i=1;i<=n;i++){
        while(cur<=k&&sorter[cur].first<=i){
            insert(sorter[cur].second);
            cur++;
        }
        for(auto a:mer[i]){
            if(find(a.first)!=find(a.second)) {
                if (dis[find(a.first)].second.second.second == -1)
                    tot -= min(dis[find(a.first)].second.first[0], dis[find(a.first)].second.first[1]);
                else tot -= dis[find(a.first)].second.first[dis[find(a.first)].second.second.second];
                if (dis[find(a.second)].second.second.second == -1)
                    tot -= min(dis[find(a.second)].second.first[0], dis[find(a.second)].second.first[1]);
                else tot -= dis[find(a.second)].second.first[dis[find(a.second)].second.second.second];
                uni(a.second, a.first, arr[i]);
                if (dis[find(a.first)].second.second.second != -1) {
                    tot += dis[find(a.first)].second.first[dis[find(a.first)].second.second.second];
                } else {
                    tot += min(dis[find(a.first)].second.first[0], dis[find(a.first)].second.first[1]);
                }
            }
        }
        for(int a:todo[i]){
            if(dis[find(a)].second.second.second==-1)tot-=min(dis[find(a)].second.first[0],dis[find(a)].second.first[1]);
            else tot-=dis[find(a)].second.first[dis[find(a)].second.second.second];
            dis[find(a)].second.second.second=(arr[i]?!wh[a]:wh[a]);
            tot+=dis[find(a)].second.first[dis[find(a)].second.second.second];
        }
        printf("%d\n",tot);
    }
    return 0;
}