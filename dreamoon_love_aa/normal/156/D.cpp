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
#define SIZE 100001
vector<int>e[SIZE],now;
bool used[SIZE];
int bfs[SIZE];
int go(int x){
    int i,j,k;
    bfs[0]=x;
    used[x]=1;
    for(i=0,j=1;i<j;i++){
        x=bfs[i];
        for(k=0;k<e[x].size();k++)
        {
            if(!used[e[x][k]]){
                used[e[x][k]]=1;
                bfs[j++]=e[x][k];
            }
        }
    }
    return i;
}
int main(){
    int i,j,k,n,m;
    cin>>n>>m>>k;
    while(m--){
        int x,y;
        cin>>x>>y;
        e[x].pb(y);
        e[y].pb(x);
    }
    for(i=1;i<=n;i++){
        if(!used[i])now.pb(go(i));
    }
    if(now.size()==1){
        printf("%d\n",1%k);
        return 0;
    }
    long long an=1;
    for(i=0;i<(int)now.size()-2;i++){
        an*=n;
        an%=k;
    }
    for(i=0;i<now.size();i++){
        an*=now[i];
        an%=k;
    }
    cout<<an<<endl;
    return 0;
}