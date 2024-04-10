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
bool used[SIZE];
vector<int>like[SIZE],dis[SIZE];
int an,bfs[SIZE];
void go(int x){
    int i,j,k,fal=0;
    set<int>H;
    used[x]=1;
    bfs[0]=x;
    H.insert(x);
    for(i=0,j=1;i<j;i++){
        x=bfs[i];
        for(k=0;k<like[x].size();k++){
            int y=like[x][k];
            if(used[y])continue;
            used[y]=1;
            if(fal){
                bfs[j++]=y;
                continue;
            }
            for(int kk=0;kk<dis[y].size();kk++){
                if(H.count(dis[y][kk]))fal=1;
            }
            H.insert(y);
            bfs[j++]=y;
        }
    }
    if(!fal)an=max(an,i);
}
int main(){
    int i,j,k,n,m;
    cin>>n;
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        like[x].pb(y);
        like[y].pb(x);
    }
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        dis[x].pb(y);
        dis[y].pb(x);
    }
    for(i=1;i<=n;i++){
        if(used[i]==0){
            go(i);
        }
    }
    cout<<an<<endl;
    return 0;
}