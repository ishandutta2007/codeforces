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
string str[555];
int r[555][555],K,an,used[555],n;
void dfs(int x,int y,int v){
    if(y>K)return;
    if(x==n){
        if(y==K)an=max(an,v);
        return;
    }
    dfs(x+1,y,v);
    used[x]=1;
    for(int i=0;i<x;i++){
        if(used[i])v+=r[i][x];
    }
    dfs(x+1,y+1,v);
    used[x]=0;
}
int main(){
    int i,j,k;
    cin>>n>>K;
    for(i=0;i<n;i++)cin>>str[i];
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++){
            for(k=0;k<str[i].size()&&k<str[j].size()&&str[i][k]==str[j][k];k++);
            r[i][j]=k;
        }
    dfs(0,0,0);
    cout<<an<<endl;
    return 0;
}