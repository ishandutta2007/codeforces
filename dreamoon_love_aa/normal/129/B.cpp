#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 126
vector<int>e[SIZE];
int main(){
    int i,j,k,n,m,an=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    while(1){
        int cnt=0,d[SIZE];
        for(i=1;i<=n;i++)
            if(e[i].size()==1){
                d[cnt++]=i;
            }
        if(!cnt)break;
        an++;
        for(i=0;i<cnt;i++){
            if(!e[d[i]].size())continue;
            int tmp=e[d[i]][0];
            vector<int>::iterator it;
            for(it=e[tmp].begin();*it!=d[i];it++);
            e[tmp].erase(it);
            e[d[i]].clear();
        }
    }
    cout<<an<<endl;
    return 0;
}