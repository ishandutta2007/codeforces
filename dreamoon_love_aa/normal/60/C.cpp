#include<stdio.h>
#include<vector>
using namespace std;
struct data{
    int y,gcd,lcm;
};
int an[128];
vector<data>edge[128];
int Gcd(int x,int y){
    if(y)while((x%=y)&&(y%=x));
    return x+y;
}
bool dfs(int x){
    int i,y,v;
    for(i=0;i<edge[x].size();i++){
        y=edge[x][i].y;
        if(1ll*edge[x][i].gcd*edge[x][i].lcm/an[x]>edge[x][i].lcm)return 0;
        v=1ll*edge[x][i].gcd*edge[x][i].lcm/an[x];
        if(Gcd(an[x],v)!=edge[x][i].gcd)return 0;
        if(v/edge[x][i].gcd*an[x]!=edge[x][i].lcm)return 0;
        if(an[y]==0){
            an[y]=v;
            if(!dfs(y))
                return 0;
        }
        else{
            if(an[y]!=v)return 0;
        }
    }
    return 1;
}
void clear(int x){
    if(!an[x])return;
    an[x]=0;
    int i;
    for(i=0;i<edge[x].size();i++)
        clear(edge[x][i].y);
}
bool Start(int x){
    int i;
    if(edge[x].size()==0){
        an[x]=1;
        return 1;
    }
    else{
        for(i=1;i*i<=edge[x][0].lcm;i++){
            if(edge[x][0].lcm%i==0){
                if(i>=edge[x][0].gcd){
                    clear(x);
                    an[x]=i;
                    if(dfs(x))break;
                }
                if(edge[x][0].lcm/i>=edge[x][0].gcd){
                    clear(x);
                    an[x]=edge[x][0].lcm/i;
                    if(dfs(x))break;
                }
            }
        }
        return i*i<=edge[x][0].lcm;
    }
}
main(){
    int n,m,i,x,y,gcd,lcd;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%d%d",&x,&y,&gcd,&lcd);
        edge[x].push_back((data){y,gcd,lcd});
        edge[y].push_back((data){x,gcd,lcd});
    }
    for(i=1;i<=n;i++){
        if(!an[i])
            if(!Start(i))break;
    }
    if(i<=n)puts("NO");
    else{
        puts("YES");
        for(i=1;i<=n;i++){
            if(i>1)printf(" ");
            printf("%d",an[i]);
        }
        puts("");
    }
}