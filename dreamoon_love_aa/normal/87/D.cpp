#include<stdio.h>
#include<algorithm>
#include<vector>
#define SIZE 100010
using namespace std;
long long an[SIZE];
struct Edge{
    int x,y,t,No;
    bool operator<(Edge b)const{return t<b.t||(t==b.t&&No<b.No);}
}e[SIZE],ee[SIZE];
int d[SIZE],r[SIZE],de[SIZE];
struct data{
    int y,No;
};
bool used[SIZE];
int find(int x){
    while(x!=d[x])x=d[x];
    return x;
}
void join(int x,int y){
    while(x!=d[x])x=d[x];
    while(y!=d[y])y=d[y];
    if(x!=y){
        if(r[x]<r[y]){
            d[x]=y;
            de[y]+=de[x];
        }
        else if(r[x]>r[y]){
            d[y]=x;
            de[x]+=de[y];
        }
        else{
            d[x]=y;
            r[y]++;
            de[y]+=de[x];
        }
    }
}
int sum;
vector<data>www,Map[SIZE];
int dfs(int x,int last){
    int i,res=de[x];
    sum+=de[x];
    for(i=0;i<Map[x].size();i++){
        if(Map[x][i].y==last)continue;
        int tmp=dfs(Map[x][i].y,x);
        res+=tmp;
        www.push_back((data){Map[x][i].No,tmp});
    }
    return res;
}
void Clac(int x){
    int i;
    sum=0;
    www.clear();
    dfs(find(ee[x].x),0);
    for(i=0;i<www.size();i++){
        used[www[i].y]=1;
        an[www[i].y]=(long long)(sum-www[i].No)*www[i].No;
    }
}
void Go(vector<int>&road){
    int n=road.size(),x,y,i;
    for(i=0;i<n;i++){
        x=find(ee[road[i]].x);
        y=find(ee[road[i]].y);
        Map[x].push_back((data){y,road[i]});
        Map[y].push_back((data){x,road[i]});
    }
    for(i=0;i<n;i++){
        if(used[road[i]])continue;
        Clac(road[i]);
    }
    for(i=0;i<n;i++){
        Map[find(ee[road[i]].x)].clear();
        Map[find(ee[road[i]].y)].clear();
        join(ee[road[i]].x,ee[road[i]].y);
    }
}
main(){
    int n,i,j;
    long long ma=0;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].t);
        e[i].No=i;
        ee[i]=e[i];
    }
    sort(e+1,e+n);
    for(i=1;i<=n;i++)d[i]=i,r[i]=0,de[i]=1;
    for(i=1;i<n;i+=j){
        vector<int>road;
        for(j=0;i+j<n&&e[i+j].t==e[i].t;j++)road.push_back(e[i+j].No);
        Go(road);
    }
    for(i=1;i<n;i++){
        if(an[i]>ma){
            ma=an[i];
        }
    }
    int numm=0;
    for(i=1;i<n;i++){
        if(an[i]==ma)numm++;
    }
    printf("%I64d %d\n",ma*2,numm);
    int first=0;
    for(i=1;i<n;i++){
        if(an[i]==ma){
            if(!first)first++;
            else putchar(' ');
            printf("%d",i);
        }
    }
    puts("");
}