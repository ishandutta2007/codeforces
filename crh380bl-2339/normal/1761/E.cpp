#include<bits/stdc++.h>
using namespace std;
char s[4005][4005];
int fa[4005], deg[4005], n;
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool chk0(){
    int i;
    for(i=1;i<=n;++i)if(find(i)!=find(1))return 0;
    return 1;
}
bool tuan(int F, int &rt){
    int i,j;
    rt = -1;
    vector<int>v;v.clear();
    for(i=1;i<=n;++i){
        if(find(i) == F){
            v.push_back(i);
            if(rt==-1)rt=i;
            else if(deg[rt]>deg[i])rt=i;
        }
    }
    if(v.size()==1){
        rt = v[0];
        return 0;
    }
    for(i=0;i<v.size();++i){
        for(j=i+1;j<v.size();++j){
            if(s[v[i]][v[j]]==0)return 0;
        }
    }
    return 1;
}
vector<int> get(int F){
    vector<int>res;res.clear();
    int i;
    for(i=1;i<=n;++i){
        if(find(i) == F)res.push_back(i);
    }
    return res;
}
void work(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        fa[i]=i;
        deg[i]=0;
        scanf("%s",s[i]+1);
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            s[i][j]-='0';
            if(s[i][j]){
                int x = find(i);
                int y = find(j);
                ++deg[i];
                ++deg[j];
                if(x!=y)fa[x]=y;
            }
        }
    }
    if(chk0()){
        puts("0");
        return;
    }
    int root, cnt = 0;
    for(i=1;i<=n;++i){
        if(find(i) == i){
            ++cnt;
            if(!tuan(i, root)){
                printf("1\n%d\n",root);
                return;
            }
        }
    }
    if(cnt >= 3){
        puts("2");
        for(i=1;i<=n;++i){
            if(find(i)!=find(1)){
                printf("%d %d\n",1, i);
                return;
            }
        }
    }
    else{
        assert(cnt == 2);
        vector<int> V[2];
        V[0].clear();V[1].clear();
        for(i=1;i<=n;++i){
            if(find(i) == i){
                if(V[0].size()==0){
                    V[0] = get(i);
                }
                else V[1] = get(i);
            }
        }
        if(V[0].size()>V[1].size())swap(V[0], V[1]);
        printf("%d\n",V[0].size());
        for(auto x:V[0])printf("%d ",x);
        puts("");
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}