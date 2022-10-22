/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-04-03 23:29:50
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
int n,m,l[100010],ans[100010];
int main(){
    long long sum=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&l[i]);
        if(i+l[i]-1>n){printf("-1");return 0;}
        sum+=l[i];
    }
    if(sum<n){printf("-1");return 0;}
    for(int i=m,j=n;i>=1;i--,j--){
        j=ans[i]=max(i,j-l[i]+1);
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}