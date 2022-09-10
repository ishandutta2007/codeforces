#include<stdio.h>
#include<vector>
using namespace std;
#define SIZE 2024
vector<int>e[SIZE];
int a[SIZE],an,re;
int dfs(int x,int v){
    if(re<v)re=v;
    int i;
    for(i=0;i<e[x].size();i++)
        dfs(e[x][i],v+1);
}
main(){
    int n,x,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        if(x==-1){
            a[an++]=i;
        }
        else{
            e[x].push_back(i);
        }
    }
    for(i=0;i<an;i++){
        dfs(a[i],1);
    }
    printf("%d\n",re);
}