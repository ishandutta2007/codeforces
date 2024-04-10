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
#define SIZE 100100
vector<int>e[SIZE];
long long a[SIZE],inc[SIZE],de[SIZE];
void dfs(int x,int last){
    int i;
    long long res=0;
    for(i=0;i<e[x].size();i++){
        if(last==e[x][i]){
            continue;
        }
        dfs(e[x][i],x);
        inc[x]=max(inc[x],inc[e[x][i]]);
        de[x]=max(de[x],de[e[x][i]]);
    }
    if(a[x]>=0){
        if(inc[x]+a[x]<=de[x]){
            inc[x]=de[x]-a[x];
        }
        else{
            de[x]=inc[x]+a[x];
        }
    }
    else{
        a[x]=-a[x];
        if(de[x]+a[x]<=inc[x]){
            de[x]=inc[x]-a[x];
        }
        else{
            inc[x]=de[x]+a[x];
        }
    }
    return;
}
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].pb(y);
        e[y].pb(x);
    }
    e[1].pb(0);
    for(i=1;i<=n;i++)cin>>a[i];
    dfs(1,0);
    cout<<inc[1]+de[1]<<endl;
    return 0;
}