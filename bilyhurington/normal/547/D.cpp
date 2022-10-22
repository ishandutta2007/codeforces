/*
 * @Author: BilyHurington
 * @Date: 2020-08-14 15:41:13
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-08-14 16:23:48
 */
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> X[200010],Y[200010];
vector<int> ed[200010];
int col[200010];
void color(int x){
    for(int i=0;i<ed[x].size();i++){
        if(!col[ed[x][i]]) col[ed[x][i]]=3-col[x],color(ed[x][i]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<=n;i++){
        scanf("%d %d",&x,&y);
        X[x].push_back(i);
        Y[y].push_back(i);
    }
    for(int i=1;i<=200000;i++){
        for(int j=0;j+1<X[i].size();j+=2){
            ed[X[i][j]].push_back(X[i][j+1]);
            ed[X[i][j+1]].push_back(X[i][j]);
        }
        for(int j=0;j+1<Y[i].size();j+=2){
            ed[Y[i][j]].push_back(Y[i][j+1]);
            ed[Y[i][j+1]].push_back(Y[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        if(!col[i]){
            col[i]=1;
            color(i);
        }
    }
    for(int i=1;i<=n;i++) printf("%c",col[i]==1?'r':'b');
    return 0;
}