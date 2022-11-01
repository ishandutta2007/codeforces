#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 200001
vector<int>e[SIZE];//e
int ll[SIZE],rr[SIZE],No,de[SIZE],h,stack[SIZE],to[SIZE*4];
//llrrNodehdfsstack0to
void dfs(int x){//
    int i;
    de[x]=h;//
    h++;//+1
    ll[x]=++No;//
    to[No]=x;//
    for(i=0;i<e[x].size();i++)dfs(e[x][i]);//+1
    rr[x]=++No;//
    to[No]=x;//
    h--;//
}
int an[SIZE],q[SIZE][2];
//anq01k
struct data{
    int nn,flag;//nnflag
    data(int _nn=0,int _flag=1){nn=_nn,flag=_flag;}
};
vector<int>q1[SIZE];//
vector<data>q2[SIZE];//
void dfs2(int x){//k
    stack[h]=x;//
    for(int i=0;i<q1[x].size();i++){
        if(q[q1[x][i]][1]>=h)continue;
        q2[ll[stack[h-q[q1[x][i]][1]]]-1].pb(data(q1[x][i],-1));//k
        q2[rr[stack[h-q[q1[x][i]][1]]]].pb(data(q1[x][i],1));//k
    }
    h++;//+1
    for(int i=0;i<e[x].size();i++){
        dfs2(e[x][i]);//
    }
    h--;//-1
}
int main(){
    int i,j,k,n,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&k);
        e[k].pb(i);
    }
    dfs(0);//0dfs0
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&q[i][0],&q[i][1]);
        q1[q[i][0]].pb(i);//
    }
    dfs2(0);//
    map<int,int>H;//
    for(i=1;i<No;i++){//
        H[de[to[i]]]++;//+1
        for(j=0;j<q2[i].size();j++){//k
            an[q2[i][j].nn]+=H[de[q[q2[i][j].nn][0]]]*q2[i][j].flag;
        }
        //k*
        //
        //+k
        //+kk
    }
    for(i=0;i<m;i++){
        if(i)printf(" ");
        printf("%d",max(an[i]/2-1,0));
        ///2
    }
    puts("");
    return 0;
}