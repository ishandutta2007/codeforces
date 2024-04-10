#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#define hash hassh
using namespace std;
int n,m;
vector <int> v[100005];
int bl[100005],f[100005];
int main() {
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bl[1]=1;
    for(int i=0;i<v[1].size();i++) f[v[1][i]]=1;
    for(int i=1;i<=n;i++) if(f[i]==0) bl[i]=1;
    int p=0;
    for(int i=1;i<=n;i++)
        if(bl[i]==0){
            p=i;
            break;
        }
    if(!p){
        puts("-1");
        return 0;
    }
    memset(f,0,sizeof(f));
    int t=1;
    for(int i=0;i<v[p].size();i++) f[v[p][i]]=1;
    for(int i=1;i<=n;i++)
        if(!f[i]){
            //cout<<i<<endl;
            if(bl[i]==0) bl[i]=2;
            else t=0;
        }
    if(!t){
        puts("-1");
        return 0;
    }
    p=0;
    for(int i=1;i<=n;i++)
        if(bl[i]==0){
            p=i;
            break;
        }
    //for(int i=1;i<=n;i++) cout<<bl[i]<<" ";cout<<endl;
    if(!p){
        puts("-1");
        return 0;
    }
    memset(f,0,sizeof(f));
    for(int i=0;i<v[p].size();i++) f[v[p][i]]=1;
    for(int i=1;i<=n;i++)
        if(!f[i]){
            if(bl[i]==0) bl[i]=3;
            else t=0;
        }
    //for(int i=1;i<=n;i++) cout<<bl[i]<<" ";cout<<endl;
    if(!t){
        puts("-1");
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<v[i].size();j++)
            if(bl[i]==bl[v[i][j]])
                t=0;
    if(!t){
        puts("-1");
        return 0;
    }
    int c[4]={};
    for(int i=1;i<=n;i++) c[bl[i]]++;
    if(c[1]+c[2]+c[3]!=n){
        puts("-1");
        return 0;
    }
    if(m==1LL*n*(n-1)/2-1LL*c[1]*(c[1]-1)/2-1LL*c[2]*(c[2]-1)/2-1LL*c[3]*(c[3]-1)/2){
        for(int i=1;i<=n;i++) printf("%d ",bl[i]);
    }
    else puts("-1");
    return 0;
}