#include <bits/stdc++.h>
using namespace std;

int n;int m;int q;
int uf[300005];
struct gpp{
int f;int s;
}gp[300005];
vector<int>e[300005];
int fin(int x){
if(uf[x]==x){return x;}
uf[x]=fin(uf[x]);
return uf[x];
}
void mrg(int a,int b){
int pa=fin(a);int pb=fin(b);
if(pa==pb){return;}
int len=max({gp[pa].f+gp[pb].f+2,gp[pa].f+gp[pa].s+1,gp[pb].f+gp[pb].s+1});
uf[pa]=pb;



        gp[pb].f=(len)/2;
        gp[pb].s=len-1-gp[pb].f;


}
pair<int,int>dfs(int nw,int pa){
if(e[nw].size()==1&&pa!=0){
    return {1,nw};
}
int a=0;int b=0;
for(int i=0;i<e[nw].size();i++){
 int v=e[nw][i];
 if(v==pa){continue;}
    pair<int,int>pr=dfs(v,nw);
    if(pr.first>a){
        a=pr.first;b=pr.second;
    }
}
return{a+1,b};
}



int main() {
scanf("%d%d%d",&n,&m,&q);
for(int i=1;i<=n;i++){
    uf[i]=i;
    gp[i].f=0;gp[i].s=0;
}
for(int i=1;i<=m;i++){
    int a;int b;
    scanf(" %d",&a);scanf(" %d",&b);
    e[a].push_back(b);
    e[b].push_back(a);
    mrg(a,b);
}
for(int i=1;i<=n;i++){
    if(uf[i]==i){
        if(e[i].size()==0){
            gp[i].f=0;gp[i].s=0;continue;
        }
        int rt=dfs(i,0).second;
        int len=dfs(rt,0).first;
        gp[i].f=(len)/2;
        gp[i].s=len-1-gp[i].f;
    }
}
/*
for(int i=1;i<=n;i++){
    cout<<gp[i].f<<" "<<gp[i].s<<" "<<fin(i)<<endl;
}
cout<<endl;
*/
for(int ii=1;ii<=q;ii++){

    int typ;int a;int b;
    scanf(" %d",&typ);
    if(typ==1){
        scanf(" %d",&a);
        int pa=fin(a);
        printf("%d\n",gp[pa].f+gp[pa].s);continue;
    }
    scanf(" %d",&a);scanf(" %d",&b);
    mrg(a,b);
    /*
    for(int i=1;i<=n;i++){
    cout<<gp[i].f<<" "<<gp[i].s<<" "<<fin(i)<<endl;
    }
    cout<<endl;
    */
}




}