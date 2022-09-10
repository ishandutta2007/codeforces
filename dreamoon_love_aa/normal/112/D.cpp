#include<stdio.h>
#include<vector>
using namespace std;
#define SIZE 100001
int p[SIZE],last[SIZE];
vector<int>d[SIZE];
main(){
    int i,q,x,y,j;
    for(i=1;i<=100000;i++){
        for(j=1;j*j<i;j++){
            if(i%j==0){
                d[i].push_back(j);
                d[i].push_back(i/j);
            }
        }
        if(j*j==i)d[i].push_back(j);
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf("%d%d",&x,&y);
        int an=0;
        for(j=0;j<d[x].size();j++){
            if(last[d[x][j]]<i-y)an++;
            last[d[x][j]]=i;
        }
        printf("%d\n",an);
    }
}