#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;
typedef long double ld;

struct Query{
        int a;
        ll cnt;
};

const int N=(int)2e5+7;
int n;
int q;
int p[N];
int solprint[N];
bool vis[N];
bool oncycle[N];
int whenvis[N],whennow;
vector<vector<int>> cycles;
vector<int> g[N];
vector<int> where[N]; /// where does not contain is on cycle

Query queries[N];
int dep[N],low[N],high[N],t,ord[N],rt[N],crt,csz,msz[N],contact[N],level[N],group[N],titan,szg[N];
vector<int> currentcycle;

void dfs(int a){
        group[a]=titan;
        rt[a]=crt;
        msz[a]=csz;
        vis[a]=1;

        t++;
        ord[t]=a;

        if(!oncycle[a]){

                where[dep[a]].push_back(t);
        }else{
                contact[a]=a;
                currentcycle.push_back(a);
        }
        low[a]=t;
        for(auto&b:g[a]){
                if(!vis[b]){
                        dep[b]=1+dep[a];
                        contact[b]=contact[a];
                        dfs(b);
                }
        }
        high[a]=t;
}

int getcntpref(int pref,int x){
        int sol=0,l=0,r=(int)where[x].size()-1;
        while(l<=r){
                int m=(l+r)/2;
                if(where[x][m]<=pref){
                        sol=m+1;
                        l=m+1;
                }else{
                        r=m-1;
                }
        }
        return sol;
}

struct Q1{
        int group;
        ll dep;
        int mod;
        int addwhere;
};

bool operator < (Q1 a, Q1 b){
        return a.dep<b.dep;
}

signed main(){
        #ifdef ONLINE_JUDGE
          home = 0;
        #endif

        if(home){
                freopen("iron_man.txt","r",stdin);
        }else{
                ios::sync_with_stdio(0); cin.tie(0);
        }

        cin>>n;
        for(int i=1;i<=n;i++){
                cin>>p[i];
                if(1&&home){
                        cout<<p[i]<<" "<<i<<"\n";
                }
                g[p[i]].push_back(i);
        }

        for(int r=1;r<=n;r++){
                if(!vis[r]){
                        whennow++;
                        int i=r;
                        while(!vis[i]){
                                vis[i]=1;
                                whenvis[i]=whennow;
                                i=p[i];
                        }
                        if(whenvis[i]==whennow){
                                /// cout<<"on cycle : "<<i<<"\n";
                                /// vertex i is on cycle
                                vector<int> cycle;
                                int want=i;
                                while(cycle.empty()||i!=want){
                                        cycle.push_back(i);
                                        oncycle[i]=1;
                                        i=p[i];
                                }
                                cycles.push_back(cycle);

                        }
                }
        }

        for(int i=1;i<=n;i++){
                vis[i]=0;
        }

        for(auto&cycle:cycles){

                titan++;
                currentcycle.clear();
                crt=cycle[0];
                csz=(int)cycle.size();
                dfs(cycle[0]);
                cycle=currentcycle;
                for(int j=0;j<(int)cycle.size();j++){
                        level[cycle[j]]=j;
                }

                szg[titan]=csz;
        }

        if(1&&home){
                for(auto&cycle:cycles){
                        cout<<" ---> ";
                        for(auto&x:cycle){
                                cout<<x<<" ";
                        }
                        cout<<"\n";
                }
        }

        for(int i=1;i<=n;i++){
                assert(vis[i]);
        }

        cin>>q;
        for(int i=1;i<=q;i++){
                cin>>queries[i].cnt>>queries[i].a;
                solprint[i]=-1;
        }

        vector<Q1> q1s;

        vector<vector<int>> levels;
        map<pair<int,int>, int> tr;
        int lol=0;

        for(int j=1;j<=n;j++){
                if(!oncycle[j]){
                        pair<int, int> tog={group[j],dep[j]};
                        if(!tr.count(tog)){
                                tr[tog]=lol++;
                                levels.push_back({});
                        }
                        levels[tr[tog]].push_back(level[contact[j]]);
                }
        }

        for(auto&level:levels){
                sort(level.begin(),level.end());
        }

        for(int i=1;i<=q;i++){
                ll cnt=queries[i].cnt;
                int a=queries[i].a;
                int g=group[a];
                if(!oncycle[a]){
                        int sol=0;

                        if(dep[a]+cnt<=n){

                                solprint[i]=getcntpref(high[a],dep[a]+cnt)-getcntpref(low[a]-1,dep[a]+cnt);
                        }else{
                                solprint[i]=0;
                        }
                }else{
                        int L=low[rt[a]],R=high[rt[a]],sz=msz[a];
                        int sol=0;

                        q1s.push_back({group[a], cnt+dep[a], (dep[a]+cnt)%sz, i});

                        if(cnt+dep[a]<=n){
                                pair<int,int>tog={g,cnt+dep[a]};

                                if(tr.count(tog)){
                                        int id=tr[tog],sm=0;
                                        int l=0,r=(int)levels[id].size()-1;
                                        while(l<=r){
                                                int m=(l+r)/2;
                                                if(levels[id][m]<=level[contact[a]]-1){
                                                        sm=m+1;
                                                        l=m+1;
                                                }else{
                                                        r=m-1;
                                                }
                                        }

                                        
                                        sol-=sm;
                                }

                        }
                        solprint[i]=1;
                        solprint[i]+=sol;
                }
        }

        sort(q1s.begin(),q1s.end());

        vector<pair<int,int>>depsandguys;

        for(int i=1;i<=n;i++){
                depsandguys.push_back({dep[i], i});
        }

        vector<vector<int>> memo=cycles;
        for(auto&v:memo){
                for(auto&x:v){
                        x=0;
                }
        }

        sort(depsandguys.begin(),depsandguys.end());

        int PT1=0;

        for(auto&it:q1s){
                int g=it.group;
                ll depmax=it.dep;
                int mod=it.mod;
                int addwhere=it.addwhere;
                int sz=szg[g];
                int sol=0;
                while(PT1<(int)depsandguys.size()&&depsandguys[PT1].first<=depmax){
                        int j=depsandguys[PT1].second;
                        if(!oncycle[j]){
                                memo[group[j]-1][dep[j]%(int)cycles[group[j]-1].size()]++;
                        }
                        PT1++;
                }
                solprint[addwhere]+=memo[g-1][mod];
        }

        for(int i=1;i<=q;i++){
                if(solprint[i]==-1){
                        assert(home);
                        cout<<"?\n";
                }else{
                        cout<<solprint[i]<<"\n";
                }
        }

        return 0;
}