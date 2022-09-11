#include<stdio.h>
#include<map>
#include<vector>
#define SIZE 100001
using namespace std;
int m;
vector<int>d[SIZE];
map<int,int>H,U;
void f(int x,int last){
    printf(" %d",H[x]);
    if(d[x].size()==1)return;
    if(d[x][0]==last)f(d[x][1],x);
    else f(d[x][0],x);
}
main(){
    int n,x,y,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        if(U.count(x)==0){
            U[x]=m;
            H[m++]=x;
        }
        if(U.count(y)==0){
            U[y]=m;
            H[m++]=y;
        }
        x=U[x];
        y=U[y];
        d[x].push_back(y);
        d[y].push_back(x);
    }
    for(i=0;i<m;i++)
        if(d[i].size()==1)break;
    printf("%d",H[i]);
    f(d[i][0],i);
    puts("");
}