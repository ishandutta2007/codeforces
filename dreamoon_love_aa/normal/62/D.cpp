#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
#define SIZE 101
int N[SIZE][SIZE];
struct data{
    int y,No;
    bool operator<(data b)const{return y<b.y;}
};
vector<data>e[SIZE];
int a[2011],step[2011],o[2011],tt[2011],t;
bool used[2011];
vector<int>an;
void dfs(int x){
    int i;
    while(o[x]<e[x].size()){
        if(!used[e[x][o[x]].No]||tt[e[x][o[x]].No]==t){
            o[x]++;
        }
        else{
            tt[e[x][o[x]].No]=t;
            o[x]++;
            dfs(e[x][o[x]-1].y);
        }
    }
    an.push_back(x);
}
main(){
    int n,m,i,j,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<=m;i++)scanf("%d",&a[i]);
    memset(N,-1,sizeof(N));
    for(i=0;i<m;i++){
        N[a[i]][a[i+1]]=N[a[i+1]][a[i]]=i;
        e[a[i]].push_back((data){a[i+1],i});
        e[a[i+1]].push_back((data){a[i],i});
    }
    for(i=1;i<=n;i++)sort(e[i].begin(),e[i].end());
    used[m-1]=1;
    used[m-2]=1;
    for(i=m-3;i>=0;i--){
        used[i]=1;
        for(j=a[i+1]+1;j<=n;j++){
            if(N[a[i]][j]!=-1&&used[N[a[i]][j]]){
                an.clear();
                for(k=1;k<=n;k++)o[k]=0;
                t++;
                tt[N[a[i]][j]]=t;
                dfs(j);
                if(an.size()==m-i){
                    printf("%d",a[0]);
                    for(k=1;k<=i;k++)printf(" %d",a[k]);
                    for(k=an.size()-1;k>=0;k--)printf(" %d",an[k]);
                    puts("");
                    break;
                }
            }
        }
        if(j<=n)break;
    }
    if(i<0)puts("No solution");
}