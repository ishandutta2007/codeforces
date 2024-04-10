#include<bits/stdc++.h>
using namespace std;
int n,val[110],Fa[110];
vector<int> T[110],f[110];
vector<int> nxt(vector<int> vec){
    vector<int> Ans=vec;
    Ans[1]++;
    for(int i=1;i<=n;i++){
        if(Ans[i]>1){
            Ans[i]-=2;
            Ans[i+1]++;
        }
    }return Ans;
}
struct cmp{
	bool operator()(const pair<vector<int>,int> &a,const pair<vector<int>,int> &b) const {
		for(int i=n;i>=1;i--){
            if(a.first[i]!=b.first[i]) return a.first[i]<b.first[i];
        }return a.second<b.second;
	}
};
bool check(const vector<pair<vector<int>,int> > &V,const vector<int> &T){
    if(!V.size()) return 1;
    set<pair<vector<int>,int>,cmp> S;
    for(auto pr:V){
        for(int i=1;i<=n;i++){
            if(pr.first[i]){
                val[pr.second]=i;
                break;
            }
        }
        S.insert(pr);
    }
    for(int i=n;i>=1;i--){
        if(!T[i]) continue;
        auto it=S.end();--it;
        auto pr=*it;S.erase(it);
        int x=0;
        for(int j=n;j>=1;j--){
            if(pr.first[j]){
                x=j;
                break;
            }
        }
        // printf("??? %d %d %d\n",pr.second,i,x);
        if(x>i) return 0;
        if(x==i){
            pr.first[x]=0;x=0;
            for(int j=n;j>=1;j--){
                if(pr.first[j]){
                    x=j;
                    break;
                }
            }
            if(x) S.insert(pr);
            // printf("S %d %d\n",x,pr.second);
        }else val[pr.second]=i;
        if(S.empty()) return 1;
    }
    // puts("???");
    if(S.empty()) return 1;
    else{
        auto it=S.end();--it;
        auto pr=it->first;
        bool pd=1;
        for(auto x:pr) if(x) pd=0;
        return pd;
    }
}
void dfs(int x,int fa){Fa[x]=fa;
    // printf("%d %d\n",x,fa);
    vector<pair<vector<int>,int> > V;
    for(auto to:T[x]){
        if(to==fa) continue;
        dfs(to,x);
        V.push_back(make_pair(nxt(f[to]),to));
    }
    for(int i=1;i<=n;i++) f[x][i]=1;
    for(int i=n;i>=1;i--){
        f[x][i]=0;
        // for(int j=n;j>=1;j--) printf("%d ",f[x][j]);puts("");
        if(!check(V,f[x])) f[x][i]=1;
        // printf("%d\n",f[x][i]);
        // for(auto pr:V){
        //     for(int j=n;j>=1;j--) printf("%d ",pr.first[j]);
        //     puts("");
        // }puts("");
    }check(V,f[x]);
    // printf("DFS %d %d\n",x,fa);
    // for(int i=n;i>=1;i--) printf("%d ",f[x][i]);
    // puts("");
}
vector<pair<int,int> > T2[110];
bool vis[110];int maxn,maxx[2];
void find_max(int x,int fa){
    for(auto pr:T2[x]){
        int to=pr.first;
        if(to==fa||vis[to]) continue;
        find_max(to,x);
        if(pr.second>maxn){
            maxn=pr.second;
            maxx[0]=x;maxx[1]=to;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++){
        scanf("%d %d",&x,&y);
        T[x].push_back(y);
        T[y].push_back(x);
    }
    for(int i=1;i<=n;i++) f[i].resize(n+1);
    dfs(1,0);
    for(int i=2;i<=n;i++){
        T2[i].push_back(make_pair(Fa[i],val[i]));
        T2[Fa[i]].push_back(make_pair(i,val[i]));
        // printf("%d %d %d\n",i,Fa[i],val[i]);
    }int rt=1;
    while(1){
        maxn=maxx[0]=maxx[1]=0;
        find_max(rt,0);
        printf("? %d %d\n",maxx[0],maxx[1]);
        fflush(stdout);scanf("%d",&rt);
        if(maxx[0]==rt) vis[maxx[1]]=1;
        else vis[maxx[0]]=1;
        bool pd=1;
        for(auto pr:T2[rt]){
            int to=pr.first;
            if(!vis[to]) pd=0;
        }if(pd) break;
    }printf("! %d\n",rt);fflush(stdout);
    return 0;
}