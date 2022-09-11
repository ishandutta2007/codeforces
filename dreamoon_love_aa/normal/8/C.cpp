#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int used[24],an,route[24],an_route[24],n;
struct Pointt{
    int x,y;
    int dis(Pointt X){return (x-X.x)*(x-X.x)+(y-X.y)*(y-X.y);}
}O,a[24];
struct data{
    int x,No;
    bool operator<(data b)const{return x<b.x;}
};
vector<data>d[24];
void dfs(int x,int v){
    int i,size=d[x].size();
    if(v>=an)return;
    if(x==n){
        an=v;
        for(i=0;i<n;i++)an_route[i]=route[i];
        return;
    }
    if(used[x]){
        dfs(x+1,v);
        return;
    }
    for(i=0;i<size;i++){
        if(used[d[x][i].No])continue;
        used[d[x][i].No]=1;
        route[d[x][i].No]=-2;
        route[x]=d[x][i].No;
        dfs(x+1,v+d[x][i].x);
        used[d[x][i].No]=0;
    }
    route[x]=-1;
    dfs(x+1,a[x].dis(O)+v);
}
main(){
    int dx,dy,x,y,i,j,init=0;
    an=1000000000;
    O.x=O.y=0;
    scanf("%d%d",&dx,&dy);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        a[i]=(Pointt){x-dx,y-dy};
        init+=a[i].dis(O);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
            if(a[i].dis(O)+a[j].dis(O)>a[i].dis(a[j]))d[i].push_back((data){a[i].dis(a[j]),j});
        sort(d[i].begin(),d[i].end());
    }
    dfs(0,init);
    printf("%d\n",an);
    printf("0");
    for(i=0;i<n;i++){
        if(an_route[i]>=0)printf(" %d %d 0",i+1,an_route[i]+1);
        else if(an_route[i]==-1)printf(" %d 0",i+1);
    }
    puts("");
}