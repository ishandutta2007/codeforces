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
#define SIZE 55
int d[SIZE],d_num[SIZE];
int init(int n){for(int i=0;i<n;i++)d[i]=i,d_num[i]=1;}
int find(int x){return x!=d[x]?(d[x]=find(d[x])):x;}
bool uu(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return 0;
    if(d_num[x]<d_num[y]){d[x]=y;d_num[y]+=d_num[x];}
    else{d[y]=x;d_num[x]+=d_num[y];}
    return 1;
}
vector<int>group[50],sz[4];
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    init(n);
    for(i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        uu(x,y);
    }
    for(i=0;i<n;i++)
        group[find(i)+1].pb(i+1);
    for(i=1;i<=n;i++)
        if(group[i].size()>0){
            if(group[i].size()>3){
                puts("-1");
                return 0;
            }
            sz[group[i].size()].pb(i);
        }
    if(sz[2].size()>sz[1].size()){
        puts("-1");
        return 0;
    }
    for(i=0;i<sz[3].size();i++){
        for(j=0;j<3;j++){
            if(j)printf(" ");
            printf("%d",group[sz[3][i]][j]);
        }
        puts("");
    }
    for(i=0;i<sz[2].size();i++){
        for(j=0;j<2;j++){
            if(j)printf(" ");
            printf("%d",group[sz[2][i]][j]);
        }
        printf(" %d",group[sz[1][i]][0]);
        puts("");
    }
    for(i=sz[2].size();i<sz[1].size();i++){
        if((i-sz[2].size())%3)printf(" ");
        else if(i!=sz[2].size())printf("\n");
        printf("%d",group[sz[1][i]][0]);
    }
    return 0;
}