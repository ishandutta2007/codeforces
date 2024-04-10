/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-02-13 19:21:04
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int n,m;
char s[110][60];
bool check(int x,int y){
    for(int i=1;i<=m;i++){
        if(s[x][i]!=s[y][m+1-i]) return 0;
    }
    return 1;
}
bool used[110];
vector<int> ans1,ans2;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    int one=0;
    for(int i=1;i<=n;i++){
        if(used[i]) continue;
        for(int j=i+1;j<=n;j++){
            if(check(i,j)&&!used[j]){
                ans1.push_back(i);
                ans2.push_back(j);
                used[i]=used[j]=1;
            }
        }
        if(!used[i]&&!one&&check(i,i)){
            one=i;
        }
    }
    printf("%d\n",(ans1.size()+ans2.size()+(one!=0))*m);
    for(int i=0;i<ans1.size();i++){
        for(int j=1;j<=m;j++) printf("%c",s[ans1[i]][j]);
    }
    if(one!=0) for(int j=1;j<=m;j++) printf("%c",s[one][j]);
    for(int i=ans2.size()-1;i>=0;i--){
        for(int j=1;j<=m;j++) printf("%c",s[ans2[i]][j]);
    }
    return 0;
}