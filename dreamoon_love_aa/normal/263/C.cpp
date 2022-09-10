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
#define SIZE 100010
vector<int>e[SIZE];
int bfs[SIZE],v[SIZE],used[SIZE],an[SIZE],ha[SIZE],n,tt;
bool con(int x,int y){
    for(int i=0;i<e[x].size();i++){
        if(e[x][i]==y)return 1;
    }
    return 0;
}
bool check(){
    int i;
    for(i=0;i<n;i++){
        if(i+1<n){
            if(!con(an[i],an[i+1]))return 0;
        }
        if(i+2<n){
            if(!con(an[i],an[i+2]))return 0;
        }
    }
    if(!con(an[0],an[n-1]))return 0;
    if(!con(an[0],an[n-2]))return 0;
    if(!con(an[1],an[n-1]))return 0;
    return 1;
}
void go(){
    int i,j;
    tt++;
    ha[an[0]]=ha[an[1]]=ha[an[2]]=tt;
    for(i=3;i<n;i++){
        int x=an[i-1];
        for(j=0;j<e[x].size();j++){
            if(con(e[x][j],an[i-2])&&e[x][j]!=an[i-3]){
                if(ha[e[x][j]]==tt){
                    return;
                }
                an[i]=e[x][j];
                ha[e[x][j]]=tt;
                break;
            }
        }
    }
    if(!check()){
        return;
    }
    for(i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",an[i]);
    }
    puts("");
    exit(0);
}
int main(){
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n*2;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    for(i=1;i<=n;i++){
        if(e[i].size()!=4){
            puts("-1");
            return 0;
        }
    }
    if(n==5){
        for(i=1;i<=5;i++){
            if(i!=1)printf(" ");
            printf("%d",i);
        }
        puts("");
        return 0;
    }
    bfs[0]=1;
    used[1]=1;
    for(i=0,j=1;i<j;i++){
        int x=bfs[i];
        for(k=0;k<e[x].size();k++){
            int y=e[x][k];
            if(!used[y]){
                used[y]=1;
                bfs[j++]=y;
                v[y]=v[x]+1;
            }
        }
    }
    vector<int>one;
    for(i=1;i<=n;i++){
        if(v[i]==1)one.pb(i);
    }
    if(one.size()!=4){
        puts("-1");
        return 0;
    }
    for(i=0;i<one.size();i++){
        for(j=i+1;j<one.size();j++){
            if(con(one[i],one[j])){
                an[0]=one[i];
                an[1]=1;
                an[2]=one[j];
                go();
            }
        }
    }
    puts("-1");
    return 0;
}